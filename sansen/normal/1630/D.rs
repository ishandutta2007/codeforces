// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: u64, b: u64) -> u64 {
    if a == 0 || b == 0 {
        return a + b;
    }
    let x = a.trailing_zeros();
    let y = b.trailing_zeros();
    let mut a = a >> x;
    let mut b = b >> y;
    while a != b {
        let x = (a ^ b).trailing_zeros();
        if a < b {
            std::mem::swap(&mut a, &mut b);
        }
        a = (a - b) >> x;
    }
    a << x.min(y)
}
// ---------- end binary_gcd ----------
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

// b_i a[l..(l + b_i)] 
// sum_i a_i 
// N <= 10^6
// 1 <= b_i <= N/2
// |a_i| <= 10^9
//
// b_i 1
// gcd
// N/2
//
// |B| = 1 
// 
//

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let a: Vec<i64> = sc.next_vec(n);
        let mut g = 0;
        for _ in 0..m {
            let b: u64 = sc.next();
            g = binary_gcd(g, b);
        }
        let mut a = a;
        let g = g as usize;
        let mut ans = 0;
        for _ in 0..2 {
            let mut b = vec![vec![]; g];
            for (i, a) in a.iter().enumerate() {
                b[i % g].push(*a);
            }
            let mut sum = 0;
            for a in b {
                // 
                let mut dp = (a[0], -a[0]);
                for &a in a[1..].iter() {
                    dp = ((dp.0 + a).max(dp.1 - a), (dp.0 - a).max(dp.1 + a));
                }
                sum += dp.0;
            }
            ans = ans.max(sum);
            for a in a[..g].iter_mut() {
                *a *= -1;
            }
        }
        if g == 1 {
            ans = a.iter().fold(0, |s, a| s + a.abs());
        }
        writeln!(out, "{}", ans).ok();
    }
}