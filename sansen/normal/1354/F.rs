// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let k: usize = sc.next();
        let mut p = (0..n).map(|k| {
            let a: u64 = sc.next();
            let b: u64 = sc.next();
            (a, b, k)
        }).collect::<Vec<_>>();
        p.sort_by_key(|p| p.1);
        let p = p;
        // [][] = (, )
        let mut dp = vec![vec![(0, 0, 0); 1]; 2];
        let mut memo = vec![];
        for &(a, b, _) in p.iter() {
            let mut next = vec![vec![(0, 0, 0); dp[0].len() + 1]; 2];
            for last in 0..2 {
                for (i, &(v, _, _)) in dp[last].iter().enumerate() {
                    let x = i as u64;
                    let y = (k - 1) as u64;
                    let max = std::cmp::max;
                    next[last][i] = max(next[last][i], (v + y * b, last, i));
                    next[last][i + 1] = max(next[last][i + 1], (v + a + x * b, last, i));
                    if last == 0 {
                        next[1][i] = max(next[1][i], (v + a + y * b, last, i));
                    }
                }
            }
            memo.push(dp);
            dp = next;
        }
        memo.push(dp);
        let mut last = 0;
        let mut rem = vec![];
        let mut del = vec![];
        let mut pos = (1, k - 1);
        for (&(_, _, k), dp) in p.iter().rev().zip(memo.iter().rev()) {
            let (_, x, y) = dp[pos.0][pos.1];
            if x < pos.0 {
                last = k;
            } else if y < pos.1 {
                rem.push(k);
            } else {
                del.push(k);
            }
            pos = (x, y);
        }
        let mut ans = vec![];
        for r in rem.iter().rev() {
            let r = *r as i32 + 1;
            ans.push(r);
        }
        for d in del.iter() {
            let d = *d as i32 + 1;
            ans.push(d);
            ans.push(-d);
        }
        ans.push(last as i32 + 1);
        let mut s = String::new();
        s.push_str(&format!("{}\n", ans.len()));
        for a in ans {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}