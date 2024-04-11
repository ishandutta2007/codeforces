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

// 0
// 
// 

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let q: usize = sc.next();
    for _ in 0..q {
        let s: Vec<char> = sc.next_chars();
        let mut map = std::collections::BTreeMap::new();
        for c in s {
            *map.entry(c).or_insert(0) += 1;
        }
        let m: usize = sc.next();
        let mut b: Vec<i32> = (0..m).map(|_| sc.next()).collect();
        let mut ans = vec!['.'; m];
        loop {
            let mut x = vec![];
            for (i, b) in b.iter().enumerate() {
                if *b == 0 && ans[i] == '.' {
                    x.push(i);
                }
            }
            if x.is_empty() {
                break;
            }
            for x in x.iter() {
                let x = *x as i32;
                for i in 0..m {
                    let k = i as i32;
                    b[i] -= (k - x).abs();
                }
            }
            while let Some((&p, &v)) = map.iter().rev().next() {
                map.remove(&p);
                if v >= x.len() {
                    for x in x.iter() {
                        ans[*x] = p;
                    }
                    break;
                }
            }
        }
        let s = ans.into_iter().collect::<String>();
        writeln!(out, "{}", s).ok();
    }
}