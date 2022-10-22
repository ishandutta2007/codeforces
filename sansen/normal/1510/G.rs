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
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let k: usize = sc.next();
        let mut g = vec![vec![]; n];
        for i in 1..n {
            let p = sc.next::<usize>() - 1;
            g[p].push(i);
        }
        let mut depth = vec![0; n];
        for i in (0..n).rev() {
            let mut d = 0;
            for &u in g[i].iter() {
                d = d.max(depth[u] + 1);
            }
            depth[i] = d;
        }
        let mut k = k;
        let mut ans = vec![];
        let mut pos = 0;
        while k > 1 {
            ans.push(pos);
            k -= 1;
            let x = *g[pos].iter().max_by_key(|u| depth[**u]).unwrap();
            let d = depth[x] + 1;
            for &u in g[pos].iter() {
                if k > d && u != x {
                    k -= d;
                    dfs(u, &mut k, &g, &mut ans);
                    ans.push(pos);
                    k += d;
                }
            }
            pos = x;
        }
        ans.push(pos);
        writeln!(out, "{}", ans.len() - 1).ok();
        for (i, a) in ans.iter().enumerate() {
            if i > 0 {
                write!(out, " ").ok();
            }
            write!(out, "{}", *a + 1).ok();
        }
        writeln!(out).ok();
    }
}

fn dfs(v: usize, rem: &mut usize, g: &[Vec<usize>], ans: &mut Vec<usize>) {
    ans.push(v);
    *rem -= 1;
    let mut i = 0;
    while i < g[v].len() && *rem > 0 {
        dfs(g[v][i], rem, g, ans);
        ans.push(v);
        i += 1;
    }
}