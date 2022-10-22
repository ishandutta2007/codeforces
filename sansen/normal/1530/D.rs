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

// x
// ==1ok
// 
// 

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a: Vec<usize> = sc.next_vec(n);
        let mut deg = vec![0; n];
        for a in a.iter_mut() {
            *a -= 1;
            deg[*a] += 1;
        }
        let mut dfs = vec![];
        for i in 0..n {
            if deg[i] == 0 {
                dfs.push(i);
            }
        }
        let mut used = vec![false; n];
        let mut topo = vec![];
        while let Some(mut v) = dfs.pop() {
            used[v] = true;
            topo.push(v);
            while !used[a[v]] {
                v = a[v];
                used[v] = true;
                topo.push(v);
            }
        }
        let mut ans = a.clone();
        if topo.len() > 0 {
            let u = topo[0];
            topo.push(u);
            for t in topo.windows(2) {
                ans[t[0]] = t[1];
            }
        }
        let mut score = 0;
        for i in 0..n {
            if ans[i] == a[i] {
                score += 1;
            }
        }
        writeln!(out, "{}", score).ok();
        let s = ans.iter().map(|s| (*s + 1).to_string()).collect::<Vec<_>>().join(" ");
        writeln!(out, "{}", s).ok();
    }
}