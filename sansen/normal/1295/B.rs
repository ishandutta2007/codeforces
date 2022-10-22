// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std;
    use std::io::Read;
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error"),
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
        let x: i64 = sc.next();
        let mut s: Vec<i64> = sc
            .next_chars()
            .into_iter()
            .map(|c| c.to_digit(10).unwrap() as i64)
            .collect();
        for c in s.iter_mut() {
            if *c == 0 {
                *c = 1;
            } else {
                *c = -1;
            }
        }
        let mut now = 0;
        let mut min = 0;
        let mut max = 0;
        let mut map = std::collections::BTreeMap::new();
        map.insert(now, 1);
        for i in 0..n {
            now += s[i];
            min = std::cmp::min(now, min);
            max = std::cmp::max(now, max);
            if i < n - 1 {
                *map.entry(now).or_insert(0) += 1;
            }
        }
        if now == 0 && min <= x && x <= max {
            writeln!(out, "-1").ok();
            continue;
        } else if now == 0 {
            writeln!(out, "0").ok();
            continue;
        }
        let add = now;
        let mut ans = 0;
        if add > 0 {
            for k in ((x - max) / add - 2)..((x - min) / add + 3) {
                if k >= 0 {
                    ans += *map.get(&(x - k * add)).unwrap_or(&0);
                }
            }
        } else {
            for k in ((x - min) / add - 2)..((x - max) / add + 3) {
                if k >= 0 {
                    ans += *map.get(&(x - k * add)).unwrap_or(&0);
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}