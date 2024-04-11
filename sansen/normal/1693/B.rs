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
// r 
// r
// dfs 
// 

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut child = vec![vec![]; n];
        for i in 1..n {
            let p = sc.next::<usize>() - 1;
            child[p].push(i);
        }
        let mut p = vec![(0i64, 0i64); n];
        for p in p.iter_mut() {
            p.0 = sc.next();
            p.1 = sc.next();
        }
        let ans = dfs(0, &child, &p).0;
        writeln!(out, "{}", ans).ok();
    }
}

fn dfs(v: usize, child: &[Vec<usize>], p: &[(i64, i64)]) -> (usize, i64) {
    let mut cnt = 0;
    let mut sum = 0;
    for &u in child[v].iter() {
        let (a, b) = dfs(u, child, p);
        cnt += a;
        sum += b;
    }
    if sum < p[v].0 {
        cnt += 1;
        sum = p[v].1;
    } else {
        sum = sum.min(p[v].1);
    }
    (cnt, sum)
}