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

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let p: Vec<i32> = sc.next_vec(n);
        if let Some(ans) = solve(p) {
            writeln!(out, "YES").ok();
            for (i, a) in ans.iter().enumerate() {
                if i > 0 {
                    write!(out, " ").ok();
                }
                write!(out, "{}", *a).ok();
            }
            writeln!(out).ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn solve(p: Vec<i32>) -> Option<Vec<i32>> {
    let n = p.len();
    let inf = 1_000_000 + 1;
    // dp[][][]: (, table)
    let mut dp = vec![[[([-inf; 2], 0, 0); 2]; 2]; n + 1];
    dp[n][0][0].0 = [inf; 2];
    for (i, &p) in p.iter().enumerate().rev() {
        let pre = &dp[i + 1];
        let mut next = [[([-inf; 2], 0, 0); 2]; 2];
        for (next, &p) in next.iter_mut().zip([-p, p].iter()) {
            for (sign, pre) in pre.iter().enumerate() {
                for (last, pre) in pre.iter().enumerate() {
                    if pre.0[0] > p {
                        let val = ([p, pre.0[1]], sign, last);
                        next[0].chmax(val);
                    } else if pre.0[1] > p {
                        let val = ([pre.0[0], p], sign, last);
                        next[1].chmax(val);
                    }
                }
            }
        }
        dp[i] = next;
    }
    let mut s = 2;
    let mut t = 2;
    for sign in 0..2 {
        for last in 0..2 {
            if dp[0][sign][last].0[1] > -inf {
                s = sign;
                t = last;
            }
        }
    }
    if s == 2 {
        return None;
    }
    let mut ans = vec![];
    for i in 0..n {
        if s == 0 {
            ans.push(-p[i]);
        } else {
            ans.push(p[i]);
        }
        let (_, x, y) = dp[i][s][t];
        s = x;
        t = y;
    }
    Some(ans)
}