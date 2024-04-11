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

// 2
// 
// 
// 1
// 2
//
// 
//
// 
// 2
// 3
//
// 2
// 
// 

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut cnt = vec![0; n + 1];
        let mut seg = vec![];
        for _ in 1..n {
            let len: usize = sc.next();
            let mut a = vec![];
            for _ in 0..len {
                let v: usize = sc.next();
                cnt[v] += 1;
                a.push(v);
            }
            seg.push(a);
        }
        let mut ans = vec![];
        for k in 1..=n {
            if cnt[k] > 1 {
                continue;
            }
            let mut seg = seg.clone();
            let mut cnt = cnt.clone();
            use std::collections::BTreeSet;
            let mut set: Vec<_> = (0..=n).map(|_| (1..=n).collect::<BTreeSet<_>>()).collect();
            set[n].clear();
            set[n].insert(k);
            let mut a = vec![];
            for i in (2..=n).rev() {
                if set[i].is_empty() {
                    break;
                }
                let mut v = n + 1;
                for u in set[i].iter() {
                    if cnt[*u] == 1 {
                        v = *u;
                        break;
                    }
                }
                if v > n {
                    break;
                }
                a.push(v);
                for j in 1..i {
                    set[j].remove(&v);
                }
                let k = seg.iter().position(|p| p.contains(&v)).unwrap();
                let s = seg.swap_remove(k);
                for &u in s.iter() {
                    cnt[u] -= 1;
                }
                let len = s.len();
                let and: BTreeSet<_> = s.into_iter().filter(|u| *u != v).collect();
                for j in (i - len + 1)..i {
                    set[j] = set[j].intersection(&and).cloned().collect();
                }
            }
            if a.len() == n - 1 {
                a.push(*set[1].iter().next().unwrap());
                a.reverse();
                ans = a;
                break;
            }
        }
        let mut s = String::new();
        for a in ans {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}