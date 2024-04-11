//---------- begin union_find ----------
#[allow(dead_code)]
mod union_find {
    pub struct UF {
        p: Vec<i32>,
    }
    impl UF {
        pub fn new(n: usize) -> UF {
            UF {p: vec![-1; n] }
        }
        pub fn init(&mut self) {
            for p in self.p.iter_mut() {
                *p = -1;
            }
        }
        pub fn root(&self, mut x: usize) -> usize {
            while self.p[x] >= 0 {
                x = self.p[x] as usize;
            }
            x
        }
        pub fn same(&self, x: usize, y: usize) -> bool {
            self.root(x) == self.root(y)
        }
        pub fn unite(&mut self, mut x: usize, mut y: usize) -> Option<(usize, usize)> {
            x = self.root(x);
            y = self.root(y);
            if x == y {
                return None;
            }
            if self.p[x] > self.p[y] {
                let s = x;
                x = y;
                y = s;
            }
            self.p[x] += self.p[y];
            self.p[y] = x as i32;
            Some((x, y))
        }
        pub fn get_size(&self, x: usize) -> usize {
            let r = self.root(x);
            (-self.p[r]) as usize
        }
    }
}
//---------- end union_find ----------
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
use std::cmp::*;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let k: usize = sc.next();
    let s: Vec<char> = sc.next_chars();
    let mut a = vec![vec![]; n];
    for i in 0..k {
        let c: usize = sc.next();
        for _ in 0..c {
            let x: usize = sc.next();
            a[x - 1].push(i);
        }
    }
    let inf = 300_000u64 + 1;
    let mut dp = vec![0; 2 * k];
    for i in 0..k {
        dp[k + i] = 1;
    }
    let mut u = union_find::UF::new(2 * k);
    let mut ans = 0;
    for i in 0..n {
        if a[i].len() == 0 {
            assert!(s[i] == '1');
        } else if a[i].len() == 1 {
            let x = a[i][0];
            let (p, q) = (u.root(x), u.root(x + k));
            ans -= min(dp[p], dp[q]);
            if s[i] == '0' {
                dp[p] += inf;
            } else {
                dp[q] += inf;
            }
            ans += min(dp[p], dp[q]);
        } else {
            assert!(a[i].len() == 2);
            let (a, b) = (a[i][0], a[i][1]);
            let (x, y, z, w) = if s[i] == '0' {
                (u.root(a), u.root(b), u.root(a + k), u.root(b + k))
            } else {
                (u.root(a), u.root(b + k), u.root(a + k), u.root(b))
            };
            if let Some((p, q)) = u.unite(x, w) {
                let (r, s) = u.unite(y, z).unwrap();
                ans -= min(dp[x], dp[z]);
                ans -= min(dp[y], dp[w]);
                dp[p] += dp[q];
                dp[r] += dp[s];
                ans += min(dp[p], dp[r]);
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}