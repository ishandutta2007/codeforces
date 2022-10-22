// ---------- end Scanner(require delimiter) ----------
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

// floor(a ^ (1 / k))
fn kth_root(a: u64, k: u64) -> u64 {
    assert!(k > 0);
    if a == 0 {
        return 0;
    }
    if k >= 64 {
        return 1;
    }
    if k == 1 {
        return a;
    }
    let valid = |x: u64| -> bool {
        let mut t = x;
        for _ in 1..k {
            let (val, ok) = t.overflowing_mul(x);
            if !(!ok && val <= a) {
                return false;
            }
            t = val;
        }
        true
    };
    let mut ok = 1;
    let mut ng = 2;
    while valid(ng) {
        ng *= 2;
    }
    while ng - ok > 1 {
        let mid = ok + (ng - ok) / 2;
        if valid(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    ok
}

fn run() {
    let inf = 1_000_000_000_000_000_000u64;
    let w = 60;
    let mut a = vec![];
    for k in 3..=w {
        let u = kth_root(inf, k);
        for r in 2..=u {
            let v = r.pow(k as u32);
            let x = kth_root(v, 2);
            if x * x != v {
                a.push(v);
            }
        }
    }
    a.sort();
    a.dedup();
    let calc = |n: u64| -> u64 {
        let x = match a.binary_search(&n) {
            Ok(k) => k + 1,
            Err(k) => k,
        } as u64;
        x + kth_root(n, 2)
    };
    let stdin = std::io::stdin();
    let mut sc = scanner::Scanner::new(stdin.lock());
    let t: usize = sc.next(b'\n');
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for _ in 0..t {
        let l: u64 = sc.next(b' ');
        let r: u64 = sc.next(b'\n');
        let ans = calc(r) - calc(l - 1);
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}