// ---------- begin recurse ----------
// reference
// https://twitter.com/noshi91/status/1393952665566994434
// https://twitter.com/shino16_cp/status/1393933468082397190
pub fn recurse<A, R, F>(f: F) -> impl Fn(A) -> R
where
    F: Fn(&dyn Fn(A) -> R, A) -> R,
{
    fn call<A, R, F>(f: &F, a: A) -> R
    where
        F: Fn(&dyn Fn(A) -> R, A) -> R,
    {
        f(&|a| call(f, a), a)
    }
    move |a| call(&f, a)
}
// ---------- end recurse ----------
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
// vx
// 
// 
// N<=2 
//
// 
// 
//
// -1
// 
//
// 
// 0: N=1
// 1: 
// 2: 
//
// 
// 
// 
//
// 
// a, b v d(a, v) != d(b, v)
// v 
//
// -1
//

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut g = vec![vec![]; n];
        for _ in 1..n {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            g[a].push(b);
            g[b].push(a);
        }
        let mut del = vec![false; n];
        let mut dfs = vec![];
        for i in 0..n {
            if g[i].len() == 1 {
                del[i] = true;
                dfs.push(i);
            }
        }
        while let Some(v) = dfs.pop() {
            for &u in g[v].iter() {
                if !del[u] && g[u].len() <= 2 {
                    del[u] = true;
                    dfs.push(u);
                }
            }
        }
        let mut ans = 0;
        for i in 0..n {
            let c = g[i].iter().filter(|v| del[**v]).count();
            if !del[i] && c > 0 {
                ans += c - 1;
            }
        }
        if n > 1 && del.iter().all(|d| *d) {
            ans = 1;
        }
        writeln!(out, "{}", ans).ok();
    }
}