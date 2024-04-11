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

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let x: Vec<_> = (0..3).map(|_| sc.next::<usize>()).collect();
        let a: Vec<u64> = (0..n).map(|_| sc.next()).collect();
        type State = [[usize; 6]; 3];
        let next = |dp: &mut State| {
            for d in dp.iter_mut() {
                d.rotate_right(1);
            }
            for i in 0..3 {
                let mut set = std::collections::BTreeSet::new();
                for j in 0..3 {
                    if i == 0 || (i != j) {
                        set.insert(dp[j][x[j]]);
                    }
                }
                let mut g = 0;
                while set.contains(&g) {
                    g += 1;
                }
                dp[i][0] = g;
            }
        };
        let ini = [[0; 6]; 3];
        let mut dp = vec![ini.clone()];
        let mut y = ini;
        next(&mut y);
        dp.push(y.clone());
        next(&mut y);
        dp.push(y.clone());
        let (mut s, mut e) = (1, 2);
        while dp[s] != dp[e] {
            let mut val = dp[e].clone();
            next(&mut val);
            dp.push(val.clone());
            next(&mut val);
            dp.push(val);
            s += 1;
            e += 2;
        }
        let step = e - s;
        let a: Vec<usize> = a.into_iter().map(|a| {
            if a < dp.len() as u64 {
                a as usize
            } else {
                s + ((a - s as u64) % step as u64) as usize
            }
        }).collect();
        let mut g = 0;
        for &a in a.iter() {
            g ^= dp[a][0][0];
        }
        let mut ans = 0;
        for &a in a.iter() {
            let dp = &dp[a];
            for i in 0..3 {
                if (g ^ dp[0][0] ^ dp[i][x[i]]) == 0 {
                    ans += 1;
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}