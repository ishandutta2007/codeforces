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

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut row = vec![vec![vec![]; n]; 10];
        let mut col = vec![vec![vec![]; n]; 10];
        for i in 0..n {
            let s: Vec<u8> = sc.next::<String>().bytes().collect();
            for (j, &c) in s.iter().enumerate() {
                let k = (c - b'0') as usize;
                row[k][i].push(j);
                col[k][j].push(i);
            }
        }
        let mut s = String::new();
        for (row, col) in row.iter().zip(col.iter()) {
            let mut ans = 0;
            for row in [row, col].iter() {
                let mut s = None;
                let mut t = None;
                for (i, row) in row.iter().enumerate() {
                    if row.is_empty() {
                        continue;
                    }
                    if s.is_none() {
                        s = Some(i);
                    }
                    let len = row.len();
                    ans.chmax((row[len - 1] - row[0]) * i.max(n - 1 - i));
                    t = Some(i);
                }
                if s.is_none() {
                    continue;
                }
                let s = s.unwrap();
                let t = t.unwrap();
                for (i, row) in row.iter().enumerate() {
                    if row.is_empty() {
                        continue;
                    }
                    let len = row.len();
                    ans.chmax((i - s) * (row[len - 1] - 0));
                    ans.chmax((i - s) * (n - 1 - row[0]));
                    ans.chmax((t - i) * (row[len - 1] - 0));
                    ans.chmax((t - i) * (n - 1 - row[0]));
                }
            }
            s.push_str(&format!("{} ", ans));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}