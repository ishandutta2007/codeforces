// ---------- begin chmin, chmax ---------
#[allow(dead_code)]
fn chmin<T: PartialOrd>(x: &mut T, a: T) -> bool {
    if *x > a {
        *x = a;
        true
    } else {
        false
    }
}

#[allow(dead_code)]
fn chmax<T: PartialOrd>(x: &mut T, a: T) -> bool {
    if *x < a {
        *x = a;
        true
    } else {
        false
    }
}
// ---------- end chmin, chmax ----------
// ---------- begin Scanner(require delimiter) ----------
mod scanner {
    pub struct Scanner<R> {
        reader: R,
        buf: Vec<u8>,
    }
    #[allow(dead_code)]
    impl<R: std::io::BufRead> Scanner<R> {
        pub fn new(reader: R) -> Self {
            Scanner {
                reader: reader,
                buf: Vec::with_capacity(1024),
            }
        }
        fn read(&mut self, del: u8) {
            self.buf.clear();
            self.reader.read_until(del, &mut self.buf).ok();
            assert!(self.buf.pop().unwrap() == del);
        }
        pub fn next<T: std::str::FromStr>(&mut self, del: u8) -> T {
            self.read(del);
            std::str::from_utf8(&self.buf)
                .unwrap()
                .trim()
                .parse::<T>()
                .ok()
                .unwrap()
        }
        pub fn next_bytes(&mut self, del: u8) -> Vec<u8> {
            self.read(del);
            std::str::from_utf8(&self.buf)
                .unwrap()
                .trim()
                .bytes()
                .collect()
        }
    }
}
// ---------- end scanner(require delimiter) ----------

use std::io::Write;

fn main() {
    let stdin = std::io::stdin();
    let mut sc = scanner::Scanner::new(stdin.lock());
    run(&mut sc);
}

fn run<R: std::io::BufRead>(sc: &mut scanner::Scanner<R>) {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let t = sc.next::<usize>(b'\n');
    for _ in 0..t {
        let n: usize = sc.next(b' ');
        let m: usize = sc.next(b'\n');
        let mut a = vec![vec![]; m];
        for _ in 0..n {
            for (i, a) in a.iter_mut().enumerate() {
                let d = if i == m - 1 {b'\n'} else {b' '};
                a.push(sc.next::<u32>(d));
            }
        }
        for a in a.iter_mut() {
            let mut v = (0, 0);
            for (i, a) in a.iter().enumerate() {
                chmax(&mut v, (*a, i));
            }
            a.rotate_left(v.1);
        }
        a.sort();
        let mut dp = vec![0u32; 1 << n];
        for a in a.iter().rev().take(n) {
            let mut sum = vec![0];
            for &a in a.iter() {
                for i in 0..sum.len() {
                    let v = sum[i] + a;
                    sum.push(v);
                }
            }
            let mut score = vec![0; 1 << n];
            for (i, s) in sum.into_iter().enumerate() {
                let mut x = i;
                for _ in 0..n {
                    chmax(&mut score[x], s);
                    x = (x >> 1) | ((x & 1) << (n - 1));
                }
            }
            for i in (1..(1 << n)).rev() {
                let mut j = i;
                while j > 0 {
                    let v = dp[i ^ j] + score[j];
                    chmax(&mut dp[i], v);
                    j = (j - 1) & i;
                }
            }
        }
        let ans = dp[(1 << n) - 1];
        writeln!(out, "{}", ans).ok();
    }
}