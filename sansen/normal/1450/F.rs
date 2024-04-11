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

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: Vec<usize> = sc.next_vec(n);
        if let Some(v) = solve(&a) {
            writeln!(out, "{}", v).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}

fn solve(a: &[usize]) -> Option<usize> {
    if a.windows(2).all(|a| a[0] != a[1]) {
        return Some(0);
    }
    let mut cnt = vec![0; a.len() + 1];
    for a in a.iter() {
        cnt[*a] += 1;
    }
    let mut h = std::collections::BinaryHeap::new();
    for (i, c) in cnt.iter().enumerate() {
        h.push((*c, i));
    }
    let mut pre = 0;
    while let Some((c, x)) = h.pop() {
        if c == 0 {
            break;
        }
        if pre != x {
            pre = x;
            h.push((c - 1, x));
        } else {
            let p = h.pop().unwrap();
            if p.0 == 0 {
                return None;
            }
            pre = p.1;
            h.push((p.0 - 1, p.1));
            h.push((c, x));
        }
    }
    let mut cnt = vec![0; a.len() + 1];
    let mut pre = a[0];
    let mut set = std::collections::BTreeSet::new();
    let mut id = 0;
    let mut req = 0;
    for i in 1..a.len() {
        if a[i] == a[i - 1] {
            if a[i] == pre {
                cnt[pre] += 1;
            } else {
                set.insert((pre, a[i], id));
                id += 1;
            }
            req += 1;
            pre = a[i];
        }
    }
    if *a.last().unwrap() == pre {
        cnt[pre] += 1;
    } else {
        let x = *a.last().unwrap();
        set.insert((x, pre, id));
    }
    let mut h = std::collections::BinaryHeap::new();
    for (i, c) in cnt.iter().enumerate() {
        h.push((*c, i));
    }
    let mut pre = 0;
    while let Some((c, x)) = h.pop() {
        if c == 0 {
            break;
        }
        if pre != x {
            pre = x;
            h.push((c - 1, x));
        } else {
            let p = h.pop().unwrap();
            if p.0 == 0 {
                let mut cnt = 0;
                for p in set.iter() {
                    if p.0 != pre && p.1 != pre {
                        cnt += 1;
                    }
                }
                if cnt >= c {
                    return Some(req);
                } else {
                    return Some(c - cnt + req);
                }
            } else {
                pre = p.1;
                h.push((p.0 - 1, p.1));
                h.push((c, x));
            }
        }
    }
    Some(0 + req)
}