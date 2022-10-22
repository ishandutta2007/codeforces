pub fn join<T: std::fmt::Display>(a: &[T], sep: &str) -> String {
    use std::fmt::Write;
    let mut s = String::new();
    for (i, a) in a.iter().enumerate() {
        if i > 0 {
            write!(&mut s, "{}", sep).ok();
        }
        write!(&mut s, "{}", a).ok();
    }
    s
}

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
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

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
        let m: usize = sc.next();
        let a: Vec<u32> = sc.next_vec(n);
        let mut p = vec![vec![]; n];
        for i in 1..=m {
            let e = sc.next::<usize>() - 1;
            let t = sc.next::<u32>();
            let w = sc.next::<usize>();
            p[e].push((t, w, i));
        }
        let inf = std::u32::MAX / 2;
        let mut ans = vec![];
        let mut last = 0;
        for (p, a) in p.iter().zip(a.iter()) {
            let n = p.len();
            let mut dp = vec![vec![inf; 201]; n + 1];
            dp[0][0] = 0;
            for (i, &(t, w, _)) in p.iter().enumerate() {
                let src = std::mem::take(&mut dp[i]);
                dp[i + 1] = src.clone();
                for j in (w..src.len()).rev() {
                    dp[i + 1][j].chmin(src[j - w] + t);
                }
                dp[i] = src;
            }
            let it = (100..dp[0].len()).filter(|x| dp[n][*x] <= *a - last).min_by_key(|x| dp[n][*x]);
            if let Some(x) = it {
                last += dp[n][x];
                let mut pos = x;
                for i in (1..=n).rev() {
                    let (t, w, k) = p[i - 1];
                    if pos >= w && dp[i][pos] == dp[i - 1][pos - w] + t {
                        ans.push(k);
                        pos -= w;
                    }
                }
                assert!(pos == 0);
            } else {
                ans.clear();
                break;
            }
        }
        if ans.is_empty() {
            writeln!(out, "-1").ok();
        } else {
            writeln!(out, "{}", ans.len()).ok();
            writeln!(out, "{}", join(&ans, " ")).ok();
        }
    }
}