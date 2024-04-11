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
        let h: usize = sc.next();
        let w: usize = sc.next();
        let mut a = (0..h).map(|_| sc.next_vec(w)).collect::<Vec<Vec<u32>>>();
        let mut map = std::collections::BTreeMap::new();
        for (i, a) in a.iter().enumerate() {
            for (j, a) in a.iter().enumerate() {
                map.entry(*a).or_insert(vec![]).push((i, j));
            }
        }
        let mut ans = vec![vec![0; w]; h];
        let mut s = 0;
        for (v, index) in map.into_iter().rev() {
            for (x, y) in index {
                ans[x][y] = v;
                if (x + y) & 1 == s {
                    ans[x][y] += 1;
                }
            }
            s ^= 1;
        }
        let mut s = String::new();
        for a in ans {
            for a in a {
                s.push_str(&format!("{} ", a));
            }
            s.pop();
            s.push('\n');
        }
        write!(out, "{}", s).ok();
    }
}