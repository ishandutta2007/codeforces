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

// dp[i][k][bit]: bit, iik
// i
// 
// xbit
// xdp[i][k][bit] k(=y) 
// dp[i + 1][y][bit ^ x] <- (sum x)
// 
// 2^N * N * N
// 3^N * N^3 
// sum x 
// bit1
//
// 
// 

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: Vec<i32> = (0..n).map(|_| sc.next()).collect();
        let mut sum = vec![0];
        for a in a.iter() {
            let len = sum.len();
            for i in 0..len {
                let v = sum[i] + *a;
                sum.push(v);
            }
        }
        let mut next = vec![vec![std::usize::MAX; 1 << n]; n];
        for i in 0..n {
            for j in 0..(1 << n) {
                if j >> i == 0 {
                    continue;
                }
                let mut k = i;
                while (j >> k) & 1 == 0 {
                    k += 1;
                }
                next[i][j] = k;
            }
        }
        let inf = 1_000_000i32 * 15 + 1;
        let mut dp = vec![vec![vec![inf; 1 << n]; n + 1]; n + 1];
        let mut prev: Vec<Vec<Vec<Option<(usize, usize, usize)>>>> = vec![vec![vec![None; 1 << n]; n + 1]; n + 1];
        dp[0][0][(1 << n) - 1] = 0;//[i][Index][] = i
        for i in 0..n {
            for k in 0..=n {
                for bit in 0..(1 << n) {
                    if dp[i][k][bit] == inf {
                        continue;
                    }
                    let v = dp[i][k][bit];
                    let mut x = bit;
                    while x > 0 {
                        let s = sum[x];
                        let nxt = next[k][x];
                        if v < s && nxt < n && (x >> nxt) & 1 == 1 && dp[i + 1][nxt][bit ^ x] > s {
//                            println!("({}, {}, {}) -> ({}, {}, {}), {}", i, k, bit, i + 1, nxt, bit ^ x, s);
                            dp[i + 1][nxt][bit ^ x] = s;
                            prev[i + 1][nxt][bit ^ x] = Some((i, k, bit));
                        }
                        x = (x - 1) & bit;
                    }
                }
            }
        }
        let mut pos = (0, 0);
        for i in 1..=n {
            for k in 0..=n {
                if prev[i][k][0].is_some() {
                    pos = (i, k);
                }
            }
        }
        assert!(pos.0 > 0);
        let mut bit = 0;
        let mut ans = vec![];
        while pos.0 > 0 {
            let (i, k) = pos;
            let (a, b, c) = prev[i][k][bit].unwrap();
            let x = c ^ bit;
            for j in 0..n {
                if j != k && (x >> j) & 1 == 1 {
                    ans.push((j + 1, k + 1));
                }
            }
            bit = c;
            pos = (a, b);
        }
        /*
        writeln!(out, "{}", ans.len()).ok();
        for (a, b) in ans {
            writeln!(out, "{} {}", a, b).ok();
        }
        */
        let mut way = vec![];
        while let Some((a, b)) = ans.pop() {
            way.push((a, b));
            for p in ans.iter_mut() {
                if p.0 >= a {
                    p.0 -= 1;
                }
                if p.1 >= a {
                    p.1 -= 1;
                }
            }
        }
        writeln!(out, "{}", way.len()).ok();
        for (a, b) in way {
            writeln!(out, "{} {}", a, b).ok();
        }
    }
}