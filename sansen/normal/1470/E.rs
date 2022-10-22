// ---------- begin super slice ----------
pub trait SuperSlice {
    type Item;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn lower_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn lower_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn upper_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn upper_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
}

impl<T> SuperSlice for [T] {
    type Item = T;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.lower_bound_by(|p| p.cmp(key))
    }
    fn lower_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Greater))
            .unwrap_err()
    }
    fn lower_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.lower_bound_by(|p| f(p).cmp(key))
    }
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.upper_bound_by(|p| p.cmp(key))
    }
    fn upper_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Less))
            .unwrap_err()
    }
    fn upper_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.upper_bound_by(|p| f(p).cmp(key))
    }
}
// ---------- end super slice ----------
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

// DP
// 
// 
// 
// n^4 
// DP
// 
// 
// 
// () = 
// 
// ()=
// 
// 
// 
// 

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let c: usize = sc.next();
        let q: usize = sc.next();
        let p: Vec<usize> = (0..n).map(|_| sc.next()).collect::<Vec<_>>();
        let mut dp = vec![vec![0u64; n + 1]; c + 1];
        dp[0][n] = 1;
        for i in 0..=c {
            for j in (0..n).rev() {
                for k in 0..=i.min(n - j - 1) {
                    dp[i][j] += dp[i - k][j + k + 1];
                }
            }
        }
        for i in 1..=c {
            for j in 0..=n {
                dp[i][j] += dp[i - 1][j];
            }
        }
        let mut small = vec![vec![0u64; n + 1]; c + 1];
        let mut large = vec![vec![0u64; n + 1]; c + 1];
        for i in 1..=c {
            for j in (0..n).rev() {
                let mut a = vec![];
                for k in 1..=i.min(n - j - 1) {
                    a.push((p[j + k], dp[i - k][j + k + 1]));
                }
                a.sort();
                for (s, way) in a {
                    if s < p[j] {
                        small[i][j] += way;
                    } else {
                        large[i][j] += way;
                    }
                }
                small[i][j] += small[i][j + 1];
                large[i][j] += large[i][j + 1];
            }
        }
        let solve = |x: usize, k: u64| -> Option<usize> {
            if k >= dp[c][0] {
                return None;
            }
            let mut s = 0;
            let mut c = c;
            let mut k = k;
            while c > 0 {
                assert!(k < dp[c][s]);
                let small = &small[c];
                let large = &large[c];
                if k < small[s] {
                    let mut y = small[s..].upper_bound_by(|v| (small[s] - *v).cmp(&k));
                    k -= small[s] - small[s + y - 1];
                    y += s - 1;
                    let mut a = vec![];
                    for i in 1..=c {
                        if y + i < n && p[y + i] < p[y] {
                            a.push((p[y + i], i, dp[c - i][y + i + 1]));
                        }
                    }
                    assert!(a.len() > 0);
                    a.sort();
                    for (_, i, way) in a {
                        if k >= way {
                            k -= way;
                        } else {
                            if y <= x && x <= y + i {
                                return Some(p[y + y + i - x]);
                            }
                            c -= i;
                            s = y + i + 1;
                            break;
                        }
                    }
                } else {
                    k -= small[s];
                    if k == 0 {
                        return Some(p[x]);
                    }
                    k -= 1;
                    let mut y = large.lower_bound_by(|l| l.cmp(&k).reverse());
                    k -= large[y];
                    y -= 1;
                    let mut a = vec![];
                    for i in 1..=c {
                        if y + i < n && p[y + i] > p[y] {
                            a.push((p[y + i], i, dp[c - i][y + i + 1]));
                        }
                    }
                    a.sort();
                    assert!(a.len() > 0);
                    for (_, i, way) in a {
                        if k >= way {
                            k -= way;
                        } else {
                            if y <= x && x <= y + i {
                                return Some(p[y + y + i - x]);
                            }
                            c -= i;
                            s = y + i + 1;
                            break;
                        }
                    }
                }
                if x < s {
                    return Some(p[x]);
                }
            }
            Some(p[x])
        };
        for _ in 0..q {
            let x = sc.next::<usize>() - 1;
            let k = sc.next::<u64>() - 1;
            if let Some(v) = solve(x, k) {
                writeln!(out, "{}", v).ok();
            } else {
                writeln!(out, "-1").ok();
            }
        }
    }
}