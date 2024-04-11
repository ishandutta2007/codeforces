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
    let n: usize = sc.next();
    let m: usize = sc.next();
    let k: usize = sc.next();
    let s: Vec<usize> = sc
        .next_bytes()
        .into_iter()
        .map(|c| (c - b'a') as usize)
        .collect::<Vec<_>>();
    let mut cnt = vec![vec![0; k + 1]; k + 1];
    for s in s.windows(2) {
        cnt[s[0]][s[1]] += 1;
    }
    cnt[k][s[0]] += 1;
    cnt[s[n - 1]][k] += 1;
    let mut set = std::collections::BTreeSet::new();
    set.insert((0, 0, k));
    set.insert((n + 1, n + 1, k));
    for (i, c) in s.into_iter().enumerate() {
        set.insert((i + 1, i + 1, c));
    }
    for _ in 0..m {
        let op: u8 = sc.next();
        if op == 1 {
            let l = sc.next::<usize>();
            let r = sc.next::<usize>();
            let c = (sc.next_bytes()[0] - b'a') as usize;
            let mut d = vec![*set.range(..(l, 0, 0)).next_back().unwrap()];
            d.extend(set.range((l, 0, 0)..=(r + 1, n, k)).cloned());
            for d in d.windows(2) {
                cnt[d[0].2][d[1].2] -= 1;
            }
            for &(l, r, c) in d.iter() {
                cnt[c][c] -= r - l;
            }
            for d in d.iter() {
                set.remove(d);
            }
            d = d.into_iter().filter(|p| !(l <= p.0 && p.1 <= r)).collect();
            if let Some(&p) = d.iter().find(|p| p.0 < l && r < p.1) {
                let x = d.iter().position(|q| *q == p).unwrap();
                d.remove(x);
                d.push((p.0, l - 1, p.2));
                d.push((r + 1, p.1, p.2));
            }
            for d in d.iter_mut() {
                if d.0 < l && l <= d.1 {
                    d.1 = l - 1;
                } else if d.0 <= r && r < d.1 {
                    d.0 = r + 1;
                }
            }
            d.push((l, r, c));
            d.sort();
            for d in d.windows(2) {
                cnt[d[0].2][d[1].2] += 1;
            }
            for &(l, r, c) in d.iter() {
                cnt[c][c] += r - l;
            }
            set.extend(d.into_iter());
        } else {
            let p: Vec<usize> = sc
                .next_bytes()
                .into_iter()
                .map(|c| (c - b'a') as usize)
                .collect::<Vec<_>>();
            let mut ans = n;
            for (i, a) in p.iter().enumerate() {
                for b in p.iter().take(i) {
                    ans -= cnt[*b][*a];
                }
            }
            writeln!(out, "{}", ans).ok();
        }
    }
}