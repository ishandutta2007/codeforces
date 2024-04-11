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

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a: Vec<u64> = sc.next_vec(n);
        let mut b = a.clone();
        let mut ans = vec![];
        let inf = 1000000000 + 1;
        for (i, a) in a.chunks_exact_mut(2).enumerate() {
            let v = a[0].min(a[1]);
            ans.push((2 * i, 2 * i + 1, v, inf));
            a[0] = v;
            a[1] = inf;
        }
        for i in (1..n).step_by(2) {
            let l = a[i - 1];
            let r = if i + 1 < n {
                a[i + 1]
            } else {
                l
            };
            let mut v = l.max(r);
            while binary_gcd(l, v) > 1 || binary_gcd(r, v) > 1 {
                v += 1;
            }
            ans.push((i - 1, i, l, v));
        }
        for &(p, q, r, s) in ans.iter() {
            assert!(b[p].min(b[q]) == r.min(s));
            b[p] = r;
            b[q] = s;
        }
        assert!(b.windows(2).all(|b| binary_gcd(b[0], b[1]) == 1));
        writeln!(out, "{}", ans.len()).ok();
        for (a, b, c, d) in ans {
            writeln!(out, "{} {} {} {}", a + 1, b + 1, c, d).ok();
        }
    }
}