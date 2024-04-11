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
        let n: usize = sc.next();
        let s: Vec<Vec<u8>> = (0..n).map(|_| sc.next::<String>().bytes().collect()).collect();
        let reach = |s: &Vec<Vec<u8>>, c: u8| -> bool {
            let mut s = s.clone();
            s[0][0] = c;
            s[n - 1][n - 1] = c;
            let mut used = vec![vec![false; n]; n];
            used[0][0] = true;
            let mut q = std::collections::VecDeque::new();
            q.push_back((0, 0));
            while let Some((x, y)) = q.pop_front() {
                for &(a, b) in [(1, 0), (0, 1), (!0, 0), (0, !0)].iter() {
                    let x = x + a;
                    let y = y + b;
                    if x < n && y < n && s[x][y] == c && !used[x][y] {
                        used[x][y] = true;
                        q.push_back((x, y));
                    }
                }
            }
            used[n - 1][n - 1]
        };
        let p = [(0, 1), (1, 0), (n - 1, n - 2), (n - 2, n - 1)];
        let mut ans = vec![];
        for i in 0usize..(1 << 4) {
            if i.count_ones() > 2 {
                continue;
            }
            let mut s = s.clone();
            let mut b = vec![];
            for (j, p) in p.iter().enumerate() {
                if i >> j & 1 == 1 {
                    s[p.0][p.1] ^= b'0' ^ b'1';
                    b.push(*p);
                }
            }
            if !reach(&s, b'0') && !reach(&s, b'1') {
                ans = b;
                break;
            }
        }
        writeln!(out, "{}", ans.len()).ok();
        for (a, b) in ans {
            writeln!(out, "{} {}", a + 1, b + 1).ok();
        }
    }
}