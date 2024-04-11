// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
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
use std::cmp::*;

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
        let m: usize = sc.next();
        let mut g = vec![vec![]; n];
        let mut e = vec![];
        for _ in 0..m {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            e.push((a, b));
            g[a].push(b);
        }
        let mut dp = vec![n; n];
        dp[0] = 0;
        let mut q = std::collections::VecDeque::new();
        q.push_back(0);
        while let Some(v) = q.pop_front() {
            let d = dp[v] + 1;
            for &u in g[v].iter() {
                if dp[u].chmin(d) {
                    q.push_back(u);
                }
            }
        }
        let mut g = vec![vec![]; n];
        let mut h = vec![vec![]; n];
        for &(a, b) in e.iter() {
            if dp[a] < dp[b] {
                g[b].push(a);
            } else {
                h[b].push(a);
            }
        }
        let mut res = vec![n; n];
        let mut he = std::collections::BinaryHeap::new();
        for (i, d) in dp.iter().enumerate() {
            if res[i].chmin(*d) {
                he.push(Reverse((*d, i)));
            }
            for &u in h[i].iter() {
                if res[u].chmin(*d) {
                    he.push(Reverse((*d, u)));
                }
            }
        }
        let mut h = he;
        while let Some(Reverse((d, v))) = h.pop() {
            if d > res[v] {
                continue;
            }
            for &u in g[v].iter() {
                if res[u].chmin(d) {
                    h.push(Reverse((d, u)));
                }
            }
        }
        let mut ans = String::new();
        for a in res {
            ans.push_str(&format!("{} ", a));
        }
        ans.pop();
        writeln!(out, "{}", ans).ok();
    }
}