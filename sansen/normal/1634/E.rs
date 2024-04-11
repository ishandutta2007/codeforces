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

// 
// 
//
// 
// 2*10^5
//
// 2
// 
//
// LR
// 
// 
// ok
// ok

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let m: usize = sc.next();
    let mut a = vec![];
    let mut x = vec![];
    for _ in 0..m {
        let n: usize = sc.next();
        let b: Vec<usize> = sc.next_vec(n);
        x.extend_from_slice(&b);
        a.push(b);
    }
    x.sort();
    if !x.chunks(2).all(|x| x[0] == x[1]) {
        writeln!(out, "NO").ok();
        return;
    }
    writeln!(out, "YES").ok();
    x.dedup();
    let mut b = vec![];
    let mut ans = vec![];
    for (i, a) in a.iter().enumerate() {
        ans.push(vec!['.'; a.len()]);
        for (j, a) in a.iter().enumerate() {
            b.push((*a, i, j));
        }
    }
    b.sort();
    let mut g = vec![vec![]; m];
    for (i, b) in b.chunks(2).enumerate() {
        g[b[0].1].push((b[1].1, b[1].2, b[0].2, i));
        g[b[1].1].push((b[0].1, b[0].2, b[1].2, i));
    }
    let mut used = vec![false; b.len()];
    for s in 0..g.len() {
        while let Some((t, x, y, k)) = g[s].pop() {
            if used[k] {
                continue;
            }
            used[k] = true;
            ans[s][y] = 'L';
            ans[t][x] = 'R';
            let mut pos = t;
            while pos != s {
                while let Some((t, x, y, k)) = g[pos].pop() {
                    if used[k] {
                        continue;
                    }
                    used[k] = true;
                    ans[pos][y] = 'L';
                    ans[t][x] = 'R';
                    pos = t;
                    break;
                }
            }
        }
    }
    for ans in ans {
        let s = ans.into_iter().collect::<String>();
        writeln!(out, "{}", s).ok();
    }
}