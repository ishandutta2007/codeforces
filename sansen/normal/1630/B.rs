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
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let k: i32 = sc.next();
        let a: Vec<usize> = sc.next_vec(n);
        let mut cnt = vec![0i32; n + 1];
        for a in a.iter() {
            cnt[*a] += 1;
        }
        let mut sum = -(n as i32);
        let mut dp = (n + 1, 0, 0);
        let mut y = 1;
        for x in 1..=n {
            while sum < k && y <= n {
                sum += 2 * cnt[y];
                y += 1;
            }
            if sum >= k {
                dp = (y - 1 - x, x, y - 1).min(dp);
            }
            sum -= 2 * cnt[x];
        }
        let mut ans = vec![];
        let mut l = 1;
        let mut cnt = 0i32;
        for (i, a) in a.iter().enumerate() {
            if dp.1 <= *a && *a <= dp.2 {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            if cnt > 0 && ans.len() + 1 < (k as usize) {
                ans.push((l, i + 1));
                l = i + 2;
                cnt = 0;
            }
        }
        ans.push((l, n));
        writeln!(out, "{} {}", dp.1, dp.2).ok();
        for (a, b) in ans {
            writeln!(out, "{} {}", a, b).ok();
        }
    }
}