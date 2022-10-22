// 
// 
//
// 
// 
// 10
// 10 mod (x^10 - 1) 
//  10 x 
// dft, idft 
//
// 
// 10^5  x^1, ..., x^9 
//
//  dft -> idft x^1, ..., x^9 
// dft
// sum_{i=0..10} x^i
// x != 1  x^10 - 1 = 0 0
// mat[0][0] = 1 dft, idft 1
// sum_{i=0..10} x^i = 0 0
// 
// 1111111111 
// 2020202020  5000050000 0
// x^10 - 1 = (x-1)(x^9 + ... + 1)
// x^10 - 1 = (x^5 + 1)(x^5 - 1)
// = (x+1)(x^4-x^3+x^2-x+1)(x-1)(x^4+x^3+x^2+x^1+1)
// x^4-x^3+x^2-x+1 0
//

use std::ops::*;

const LEN: usize = 10;
const SIZE: usize = 4;

#[derive(Clone, Copy)]
struct M([u64; SIZE]);

impl Add for M {
    type Output = Self;
    fn add(self, rhs: Self) -> Self {
        let mut c = M::zero();
        for ((c, a), b) in c.0.iter_mut().zip(&self.0).zip(&rhs.0) {
            *c = *a + *b;
        }
        c
    }
}

impl Sub for M {
    type Output = Self;
    fn sub(self, rhs: Self) -> Self {
        let mut c = M::zero();
        for ((c, a), b) in c.0.iter_mut().zip(&self.0).zip(&rhs.0) {
            *c = *a - *b;
        }
        c
    }
}

impl Mul for M {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self {
        let mut c = [0; 2 * SIZE - 1];
        for (i, a) in self.0.iter().enumerate() {
            for (c, b) in c[i..].iter_mut().zip(&rhs.0) {
                *c += *a * *b;
            }
        }
        for i in (SIZE..c.len()).rev() {
            let v = c[i];
            c[i - 1] = c[i - 1] + v;
            c[i - 2] = c[i - 2] - v;
            c[i - 3] = c[i - 3] + v;
            c[i - 4] = c[i - 4] - v;
        }
        let mut d = M::zero();
        for (d, c) in d.0.iter_mut().zip(&c) {
            *d = *c;
        }
        d
    }
}

impl M {
    fn zero() -> Self {
        M([0; SIZE])
    }
    fn one() -> Self {
        let mut z = Self::zero();
        z.0[0] = 1;
        z
    }
    fn pow(&self, mut n: usize) -> Self {
        let mut t = Self::one();
        let mut r = *self;
        while n > 0 {
            if n & 1 == 1 {
                t = t * r;
            }
            r = r * r;
            n >>= 1;
        }
        t
    }
}

fn read() -> Vec<usize> {
    let mut s = String::new();
    use std::io::Read;
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace().flat_map(|s| s.parse::<usize>());
    it.next();
    it.collect()
}

fn pow(mut r: u64, mut n: u64) -> u64 {
    let mut t = 1;
    while n > 0 {
        if n & 1 == 1 {
            t *= r;
        }
        r *= r;
        n >>= 1;
    }
    t
}

fn run() {
    let mut rad = M::zero();
    rad.0[1] = 1;
    let mut zeta = [M::zero(); LEN];
    let mut p = M::one();
    for zeta in zeta.iter_mut() {
        *zeta = p;
        p = p * rad;
    }
    let mut izeta = zeta;
    izeta[1..].reverse();
    let dft = |a: &mut [M; LEN]| {
        let mut memo = [M::zero(); LEN];
        for (memo, zeta) in memo.iter_mut().zip(&zeta) {
            for a in a.iter().rev() {
                *memo = *memo * *zeta + *a;
            }
        }
        *a = memo;
    };
    let idft = |a: &mut [M; LEN]| {
        let mut memo = [M::zero(); LEN];
        for (memo, izeta) in memo.iter_mut().zip(&izeta) {
            for a in a.iter().rev() {
                *memo = *memo * *izeta + *a;
            }
        }
        *a = memo;
    };

    let a = read();
    let n = 5;
    let mut dp = vec![M::zero(); LEN.pow(n)];
    for a in a.iter() {
        dp[*a].0[0] += 1;
    }
    for i in 1..=n {
        let x = LEN.pow(i - 1);
        for dp in dp.chunks_exact_mut(LEN * x) {
            for j in 0..x {
                let mut mat = [M::zero(); LEN];
                for (k, mat) in mat.iter_mut().enumerate() {
                    *mat = dp[x * k + j];
                }
                dft(&mut mat);
                for (k, mat) in mat.iter_mut().enumerate() {
                    dp[x * k + j] = *mat;
                }
            }
        }
    }
    for dp in dp.iter_mut() {
        *dp = dp.pow(a.len());
    }
    for i in (1..=n).rev() {
        let x = LEN.pow(i - 1);
        for dp in dp.chunks_exact_mut(LEN * x) {
            for j in 0..x {
                let mut mat = [M::zero(); LEN];
                for (k, mat) in mat.iter_mut().enumerate() {
                    *mat = dp[x * k + j];
                }
                idft(&mut mat);
                for (k, mat) in mat.iter_mut().enumerate() {
                    dp[x * k + j] = *mat;
                }
            }
        }
    }
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let inv = pow(pow(5, (1u64 << 63) - 1), n as u64);
    for dp in dp.iter_mut().take(a.len()) {
        let ans = (dp.0[0] * inv) >> 5;
        writeln!(out, "{}", ans % (1 << 58)).ok();
    }
}

fn main() {
    run();
}