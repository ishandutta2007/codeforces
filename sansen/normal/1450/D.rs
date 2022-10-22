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
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
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

// 10
// 1
// ?000..001
// 
//  <<<>>>> 1
// ?
// 00100 ?
// 

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: Vec<usize> = sc.next_vec(n);
        let mut b = vec![vec![]; n];
        for (i, a) in a.iter().enumerate() {
            b[*a - 1].push(i + 1);
        }
        let mut imos = vec![0; n + 2];
        let mut set = std::collections::BTreeSet::new();
        set.insert(0);
        set.insert(n + 1);
        for (i, b) in b.iter().enumerate() {
            if b.is_empty() {
                break;
            }
            let mut p = vec![];
            for &b in b.iter() {
                let l = *set.range(..=b).rev().next().unwrap();
                let r = *set.range(b..).next().unwrap();
                p.push((l, r));
            }
            for b in b.iter() {
                set.insert(*b);
            }
            p.sort_by_key(|p| (p.1 - p.0, p.0, p.1));
            p.reverse();
            if p.len() > 1 {
                let x = p[0];
                if p.iter().any(|&p| p.1 - p.0 == x.1 - x.0 && p != x) {
                    break;
                }
                let y = p[1];
                let z = x.1 - x.0;
                if x == y {
                    imos[z - 1] += 1;
                    imos[z] -= 1;
                } else {
                    let w = y.1 - y.0;
                    imos[w] += 1;
                    imos[z] -= 1;
                }
            } else {
                imos[1] += 1;
                imos[p[0].1 - p[0].0] -= 1;
            }
        }
        let mut ans = String::new();
        for i in 1..=n {
            imos[i] += imos[i - 1];
            if imos[i] == n + 1 - i {
                ans.push('1');
            } else {
                ans.push('0');
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}