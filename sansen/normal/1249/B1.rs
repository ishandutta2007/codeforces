//---------- begin scannner ----------
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
//---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let q: usize = sc.next();
    for _ in 0..q {
        let n: usize = sc.next();
        let p: Vec<usize> = (0..n).map(|_| sc.next::<usize>() - 1).collect();
        let mut ans = vec![0; n];
        for i in 0..n {
            if ans[i] > 0 {
                continue;
            }
            let mut cnt = 1;
            let mut now = p[i];
            while now != i {
                now = p[now];
                cnt += 1;
            }
            for _ in 0..cnt {
                ans[now] = cnt;
                now = p[now];
            }
        }
        let mut s = String::new();
        for i in 0..n {
            s.push_str(&format!("{} ", ans[i]));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}