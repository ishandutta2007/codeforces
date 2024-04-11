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
        let m: usize = sc.next();
        let mut g = vec![vec![]; n];
        for _ in 0..m {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            g[a].push(b);
        }
        let mut alive = vec![true; n];
        let mut child = vec![false; n];
        let mut ans = vec![];
        for i in 0..n {
            if !alive[i] {
                continue;
            }
            if child[i] {
                for &v in g[i].iter() {
                    alive[v] = false;
                    ans.push(v);
                }
            } else {
                for &v in g[i].iter() {
                    child[v] = true;
                }
            }
        }
        ans.sort();
        ans.dedup();
        assert!(ans.len() <= 4 * n / 7);
        let mut s = String::new();
        s.push_str(&format!("{}\n", ans.len()));
        for a in ans.iter() {
            s.push_str(&format!("{} ", *a + 1));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}