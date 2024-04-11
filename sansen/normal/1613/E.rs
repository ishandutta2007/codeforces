// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let h: usize = sc.next();
        let w: usize = sc.next();
        let mut s = vec![];
        for _ in 0..h {
            let mut a = sc.next_chars();
            a.insert(0, '#');
            a.push('#');
            s.push(a);
        }
        s.insert(0, vec!['#'; w + 2]);
        s.push(vec!['#'; w + 2]);
        let src = || -> (usize, usize) {
            for (i, s) in s.iter().enumerate() {
                for (j, s) in s.iter().enumerate() {
                    if *s == 'L' {
                        return (i, j);
                    }
                }
            }
            unreachable!()
        }();
        let mut dfs = vec![src];
        let mut used = vec![vec![false; w + 2]; h + 2];
        let dir = [(0, 1), (1, 0), (!0, 0), (0, !0)];
        while let Some((x, y)) = dfs.pop() {
            if s[x][y] == '.' {
                for &(dx, dy) in dir.iter() {
                    let mut cond = false;
                    for &(p, q) in dir.iter() {
                        if (p, q) == (dx, dy) {
                            continue;
                        }
                        cond |= s[x + p][y + q] == '.';
                    }
                    if !cond {
                        s[x][y] = '+';
                    }
                }
            }
            if s[x][y] != '.' && !used[x][y] {
                used[x][y] = true;
                for &(dx, dy) in dir.iter() {
                    let x = x + dx;
                    let y = y + dy;
                    if s[x][y] == '.' {
                        dfs.push((x, y));
                    }
                }
            }
        }
        for i in 1..=h {
            for j in 1..=w {
                write!(out, "{}", s[i][j]).ok();
            }
            writeln!(out).ok();
        }
    }
}