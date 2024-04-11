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
    let n: usize = sc.next();
    let mut sum = vec![0i64; n];
    let mut map = std::collections::BTreeMap::new();
    for i in 0..n {
        let len: usize = sc.next();
        for _ in 0..len {
            let v: i64 = sc.next();
            sum[i] += v;
            assert!(map.insert(v, i).is_none());
        }
    }
    let sum = sum;
    let s = sum.iter().fold(0, |s, a| s + *a);
    if s % (n as i64) != 0 {
        writeln!(out, "No").ok();
        return;
    }
    let s = s / (n as i64);
    let mut dp = vec![false; 1 << n];
    dp[0] = true;
    let mut memo: Vec<Option<Vec<(usize, i64, usize)>>> = vec![None; 1 << n];
    for (&val, &x) in map.iter() {
        let mut a = vec![(x, val, n)];
        let mut bit = 1 << x;
        let mut now = (val, x);
        while let Some(&y) = map.get(&(s - (sum[now.1] - now.0))) {
            let v = s - (sum[now.1] - now.0);
            if (bit >> y) & 1 == 1 {
                if (v, y) == (val, x) {
                    a[0].2 = now.1;
                    dp[bit] = true;
                    memo[bit] = Some(a);
                }
                break;
            } else {
                bit |= 1 << y;
                let to = a.last().unwrap().0;
                a.push((y, v, to));
                now = (v, y);
            }
        }
    }
    for i in 1..(1 << n) {
        let mut x = i & (i - 1);
        while x > 0 {
            dp[i] |= dp[x] && dp[i ^ x];
            x = (x - 1) & i;
        }
    }
    if !dp[(1 << n) - 1] {
        writeln!(out, "No").ok();
        return;
    }
    let mut ans = vec![];
    let mut stack = vec![(1 << n) - 1];
    while let Some(x) = stack.pop() {
        assert!(x > 0 && dp[x]);
        if memo[x].is_some() {
            ans.append(&mut memo[x].take().unwrap());
        } else {
            let mut y = (x - 1) & x;
            while y > 0 {
                if dp[y] && dp[x ^ y] {
                    break;
                }
                y = (y - 1) & x;
            }
            stack.push(y);
            stack.push(x ^ y);
        }
    }
    ans.sort_by_key(|p| p.0);
    writeln!(out, "Yes").ok();
    for p in ans {
        writeln!(out, "{} {}", p.1, p.2 + 1).ok();
    }
}