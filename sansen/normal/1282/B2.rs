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

fn run(sc: &mut Scanner<StdinLock>, out: &mut BufWriter<StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let p: i32 = sc.next();
        let k: usize = sc.next();
        let mut a: Vec<i32> = (0..n).map(|_| sc.next()).collect();
        a.sort();
        let mut dp = vec![0; n + 1];
        for i in 0..(k - 1) {
            dp[i + 1] = dp[i] + a[i];
        }
        for i in (k - 1)..n {
            dp[i + 1] = dp[i - k + 1] + a[i];
        }
        let mut ans = 0;
        for i in 1..=n {
            if dp[i] <= p {
                ans = i;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}