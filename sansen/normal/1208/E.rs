//---------- begin scannner ----------
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
//---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let out = std::io::BufWriter::new(out.lock());
    run(sc, out);
}

fn run(mut sc: scanner::Scanner, mut out: std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let w: usize = sc.next();
    let w = w + 2;
    let mut a = vec![vec![]; n];
    for i in 0..n {
        let len: usize = sc.next();
        a[i].push(0);
        for _ in 0..len {
            let v: i64 = sc.next();
            a[i].push(v);
        }
        a[i].push(0);
    }
    let mut ans = vec![0i64; w];
    let mut imos = vec![0i64; w];
    for i in 0..n {
        let a = &a[i];
        let l = a.len();
        let mut deq = std::collections::VecDeque::<(usize, i64)>::new();
        if 2 * l >= w {
            for j in 0..w {
                if j < l {
                    let x = a[j];
                    while let Some(v) = deq.back() {
                        if v.1 > x {
                            break;
                        } else {
                            deq.pop_back();
                        }
                    }
                    deq.push_back((j, x));
                }
                if let Some(v) = deq.front() {
                    if l - v.0 > w - j {
                        deq.pop_front();
                    }
                }
                ans[j] += deq.front().unwrap().1;
            }
        } else {
            for j in 0..l {
                let x = a[j];
                while let Some(v) = deq.back() {
                    if v.1 > x {
                        break;
                    } else {
                        deq.pop_back();
                    }
                }
                deq.push_back((j, x));
                if let Some(v) = deq.front() {
                    if l - v.0 > w - j {
                        deq.pop_front();
                    }
                }
                ans[j] += deq.front().unwrap().1;
            }
            let max = deq.front().unwrap().1;
            imos[l] += max;
            imos[w - l] -= max;
            for j in (w - l)..w {
                if let Some(v) = deq.front() {
                    if l - v.0 > w - j {
                        deq.pop_front();
                    }
                }
                ans[j] += deq.front().unwrap().1;
            }
        }
    }
    ans[0] += imos[0];
    for i in 1..w {
        imos[i] += imos[i - 1];
        ans[i] += imos[i];
    }
    for (i, ans) in ans[1..(w - 1)].iter().enumerate() {
        if i > 0 {
            write!(out, " ").unwrap();
        }
        write!(out, "{}", *ans).unwrap();
    }
    writeln!(out, "").unwrap();
}