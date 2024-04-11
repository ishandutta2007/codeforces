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
    use std;
    use std::io::Read;
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error"),
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

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

// k, 
// K
// 

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut g = vec![vec![]; n];
        for _ in 1..n {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            g[a].push(b);
            g[b].push(a);
        }
        let mut topo = vec![0];
        for i in 0..n {
            let v = topo[i];
            let child = std::mem::take(&mut g[v]);
            for &u in child.iter() {
                let x = g[u].iter().position(|e| *e == v).unwrap();
                g[u].remove(x);
                topo.push(u);
            }
            g[v] = child;
        }
        let mut ans = 1;
        let mut dp = vec![0; n];
        for &v in topo[1..].iter().rev() {
            if g[v].is_empty() {
                continue;
            }
            let mut a = n;
            let mut b = 0;
            for &u in g[v].iter() {
                a = a.min(dp[u] + 1);
                b = b.max(dp[u] + 1);
            }
            if g[v].len() == 1 {
                dp[v] = a;
            } else {
                ans.chmax(b + 1);
                dp[v] = a;
            }
        }
        let mut d = vec![];
        for &u in g[0].iter() {
            d.push(dp[u] + 1);
        }
        d.sort();
        if d.len() == 1 {
            ans.chmax(d[0]);
        } else {
            let len = d.len();
            ans.chmax(d[len - 2] + 1);
            ans.chmax(d[len - 1]);
        }
        writeln!(out, "{}", ans).ok();
    }
}