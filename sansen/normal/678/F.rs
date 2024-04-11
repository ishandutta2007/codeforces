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
    let n: usize = sc.next(b'\n');
    let mut line = vec![];
    let mut map = std::collections::BTreeMap::new();
    let mut ask = vec![];
    for i in 1..=n {
        let op: u8 = sc.next(b' ');
        if op == 1 {
            let a: i64 = sc.next(b' ');
            let b: i64 = sc.next(b'\n');
            map.insert(i, (a, b, ask.len()));
        } else if op == 2 {
            let k: usize = sc.next(b'\n');
            let (a, b, s) = map.remove(&k).unwrap();
            if s < ask.len() {
                line.push((a, b, s, ask.len()));
            }
        } else {
            let q: i64 = sc.next(b'\n');
            let x = ask.len();
            ask.push((q, x));
        }
    }
    for (_, (a, b, s)) in map {
        if s < ask.len() {
            line.push((a, b, s, ask.len()));
        }
    }
    line.sort_by_key(|p| p.0);
    ask.sort_by_key(|p| p.0);
    let mut ans = vec![std::i64::MIN; ask.len()];
    dfs(0, ask.len(), line, ask, &mut ans);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        if a == std::i64::MIN {
            writeln!(out, "EMPTY SET").ok();
        } else {
            writeln!(out, "{}", a).ok();
        }
    }
}

fn dfs(l: usize, r: usize, line: Vec<(i64, i64, usize, usize)>, ask: Vec<(i64, usize)>, ans: &mut [i64]) {
    let mut cht = vec![];
    for &(a, b, s, t) in line.iter() {
        if s <= l && r <= t {
            cht.push((a, b));
        }
    }
    cht.dedup_by(|a, b| {
        a.0 == b.0 && {
            b.1 = b.1.max(a.1);
            true
        }
    });
    let mut stack: Vec<(i64, i64)> = vec![];
    for (a, b) in cht {
        while stack.len() > 1 {
            let len = stack.len();
            let (c, d) = stack[len - 1];
            let (e, f) = stack[len - 2];
            if (f - b) * (a - c) < (d - b) * (a - e) {
                break;
            } else {
                stack.pop();
            }
        }
        stack.push((a, b));
    }
    for &(x, k) in ask.iter().rev() {
        while stack.len() > 1 {
            let len = stack.len();
            let (a, b) = stack[len - 1];
            let (c, d) = stack[len - 2];
            if a * x + b <= c * x + d {
                stack.pop();
            } else {
                break;
            }
        }
        stack.last().map(|p| ans[k] = ans[k].max(p.0 * x + p.1));
    }
    if l + 1 < r {
        let m = (l + r) / 2;
        let mut left = vec![];
        let mut right = vec![];
        for (a, b, s, t) in line {
            if !(s <= l && r <= t) {
                if s < m {
                    left.push((a, b, s, t));
                }
                if m < t {
                    right.push((a, b, s, t));
                }
            }
        }
        let mut ask_l = vec![];
        let mut ask_r = vec![];
        for (x, k) in ask {
            if k < m {
                ask_l.push((x, k));
            } else {
                ask_r.push((x, k));
            }
        }
        dfs(l, m, left, ask_l, ans);
        dfs(m, r, right, ask_r, ans);
    }
}