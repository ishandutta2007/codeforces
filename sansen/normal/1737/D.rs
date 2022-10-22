// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
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

// (u, v, w) vx
// (u, x, w) w
// 1-n  + 
//
// 1-n
// k
// 
//
// 4 3
// 1 2 inf
// 2 4 inf
// 2 3 1
// 34
// 
// (1, n) bfs
// 
// (i, j) O(N)
// 
// 
// 6
//
// 2-5
// 2-6
// 6-6
// 6-7
// 6-1
// 1-4
// 1-8
//
// 
// bfs
// 1-n bfs

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let mut e = (0..m)
            .map(|_| {
                let x = sc.next::<usize>() - 1;
                let y = sc.next::<usize>() - 1;
                let w: i64 = sc.next();
                (x.min(y), x.max(y), w)
            })
            .collect::<Vec<_>>();
        e.sort_by_key(|e| (e.0, e.1));
        e.dedup_by(|a, b| {
            (a.0, a.1) == (b.0, b.1) && {
                b.2 = a.2.min(b.2);
                true
            }
        });
        let mut g = vec![vec![]; n];
        for &(a, b, _) in e.iter() {
            g[a].push(b);
            g[b].push(a);
        }
        let inf = 500 * 500i64;
        let mut dp = vec![vec![inf; n]; n];
        dp[0][n - 1] = 0;
        dp[n - 1][0] = 0;
        let mut pq = std::collections::BinaryHeap::new();
        pq.push((0, 0, n - 1));
        pq.push((0, n - 1, 0));
        while let Some((_, x, y)) = pq.pop() {
            let d = dp[x][y] + 1;
            if e.binary_search_by_key(&(x.min(y), x.max(y)), |e| (e.0, e.1)).is_ok() {
                if dp[x][x].chmin(d) {
                    pq.push((-d, x, x));
                    for y in 0..n {
                        if dp[x][y].chmin(d + 1) {
                            pq.push((-(d + 1), x, y));
                        }
                    }
                }
                if dp[y][y].chmin(d) {
                    pq.push((-d, y, y));
                    for x in 0..n {
                        if dp[x][y].chmin(d + 1) {
                            pq.push((-(d + 1), x, y));
                        }
                    }
                }
            }
            for (x, y) in g[x].iter().map(|u| (*u, y)).chain(g[y].iter().map(|u| (x, *u))) {
                if dp[x][y].chmin(d) {
                    pq.push((-d, x, y));
                }
            }
        }
        let mut ans = std::i64::MAX;
        for &(a, b, w) in e.iter() {
            let v = dp[a][b].min(dp[b][a]);
            ans.chmin((v + 1) * w);
        }
        writeln!(out, "{}", ans).ok();
    }
}