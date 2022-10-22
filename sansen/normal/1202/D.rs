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
        pub fn next_vec<T: FromStr>(&mut self, n: usize) -> Vec<T> {
            (0..n).map(|_| self.next()).collect::<Vec<T>>()
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
    macro_rules! puts {
        ($($format:tt)*) => (write!(out, $($format)*).unwrap());
    }
    let t: usize = sc.next();
    for _ in 0..t {
        let mut n: u64 = sc.next();
        let mut k = 1;
        while k * (k + 1) / 2 <= n {
            k += 1;
        }
        let mut x = vec![];
        while n > 0 {
            if k * (k + 1) / 2 <= n {
                x.push(k);
                n -= k * (k + 1) / 2;
            } else {
                k -= 1;
            }
        }
        x.reverse();
        let mut ans = String::new();
        ans.push('1');
        ans.push('3');
        let mut j = 0;
        for i in 1.. {
            ans.push('3');
            while j < x.len() && x[j] == i as u64 {
                ans.push('7');
                j += 1;
            }
            if j >= x.len() {
                break;
            }
        }
        puts!("{}\n", ans);
    }
}