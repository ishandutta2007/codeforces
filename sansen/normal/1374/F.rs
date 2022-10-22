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
        let mut a = (0..n).map(|_| sc.next::<usize>()).collect::<Vec<_>>();
        let mut ans = vec![];
        for i in (2..n).rev() {
            let mut max = (0, 0);
            for j in (0..=i).rev() {
                max = std::cmp::max(max, (a[j], j));
            }
            while max.1 < i {
                if max.1 == 0 {
                    a[..3].rotate_right(1);
                    ans.push(max.1);
                } else {
                    a[(max.1 - 1)..(max.1 + 2)].rotate_right(1);
                    ans.push(max.1 - 1);
                }
                max.1 += 1;
            }
        }
        let mut can = a[0] <= a[1];
        if a[0] > a[1] {
            if a[0] == a[2] {
                ans.push(0);
                a[..3].rotate_right(1);
                ans.push(0);
                a[..3].rotate_right(1);
                can = true;
            } else {
                let mut p = 0;
                while p + 3 < n && a[p + 2] != a[p + 3] {
                    ans.push(p);
                    a[p..(p + 3)].rotate_right(1);
                    p += 1;
                }
                if p + 3 < n {
                    ans.push(p + 1);
                    a[(p + 1)..(p + 4)].rotate_right(1);
                    ans.push(p);
                    a[p..(p + 3)].rotate_right(1);
                    can = true;
                }
                while p > 0 {
                    p -= 1;
                    ans.push(p);
                    a[p..(p + 3)].rotate_right(1);
                    ans.push(p);
                    a[p..(p + 3)].rotate_right(1);
                }
            }
        }
        if can {
            assert!(ans.len() <= n * n && a.windows(2).all(|a| a[0] <= a[1]));
            let mut s = String::new();
            s.push_str(&format!("{}\n", ans.len()));
            for a in ans {
                s.push_str(&format!("{} ", a + 1));
            }
            s.pop();
            writeln!(out, "{}", s).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}