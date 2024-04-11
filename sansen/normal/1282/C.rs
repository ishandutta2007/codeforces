use std::io::*;
use std::str::*;

struct Scanner<R: BufRead> {
    handle: R,
    buffer: String,
    token: Vec<String>,
}

#[allow(dead_code)]
impl<R: BufRead> Scanner<R> {
    fn new(input: R) -> Self {
        Scanner {
            handle: input,
            buffer: String::new(),
            token: Vec::new(),
        }
    }
    fn next<T: FromStr>(&mut self) -> T {
        loop {
            if let Some(s) = self.token.pop() {
                match s.parse::<T>() {
                    Ok(v) => {
                        return v;
                    },
                    _ => panic!("Scanner error"),
                }
            }
            self.buffer.clear();
            self.handle.read_line(&mut self.buffer).ok();
            let mut i = 0;
            for s in self.buffer.split_whitespace().rev() {
                if i >= self.token.len() {
                    self.token.push(String::new());
                }
                self.token[i].clear();
                self.token[i].push_str(s);
                i += 1;
            }
        }
    }
    fn next_chars(&mut self) -> Vec<char> {
        let s: String = self.next();
        s.chars().collect()
    }
}

fn main() {
    let stdin = std::io::stdin();
    let sc = &mut Scanner::new(stdin.lock());
    let out = std::io::stdout();
    let out = &mut std::io::BufWriter::new(out.lock());
    run(sc, out);
}

use std::cmp::*;

fn run(sc: &mut Scanner<StdinLock>, out: &mut BufWriter<StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let t: u64 = sc.next();
        let a: u64 = sc.next();
        let b: u64 = sc.next();
        let mut p = vec![(0u64, 0usize); n];
        let mut cnt = [0u64, 0u64];
        for p in p.iter_mut() {
            p.1 = sc.next();
            cnt[p.1] += 1;
        }
        for p in p.iter_mut() {
            p.0 = sc.next();
        }
        p.sort();
        let mut ans = if cnt[0] * a + cnt[1] * b <= t {n as u64} else {0};
        if p[0].0 > 0 {
            let mut c = 0;
            let mut rem = p[0].0 - 1;
            let v = min(rem / a, cnt[0]);
            c += v;
            rem -= a * v;
            let v = min(rem / b, cnt[1]);
            c += v;
            ans = max(ans, c);
        }
        let mut sum = 0;
        for i in 0..(n - 1) {
            let k = p[i].1;
            sum += if k == 0 {a} else {b};
            cnt[k] -= 1;
            if sum >= p[i + 1].0 {
                continue;
            }
            let mut c = i as u64 + 1;
            let mut rem = p[i + 1].0 - 1 - sum;
            let v = min(rem / a, cnt[0]);
            c += v;
            rem -= a * v;
            let v = min(rem / b, cnt[1]);
            c += v;
            ans = max(ans, c);
        }
        writeln!(out, "{}", ans).ok();
    }
}