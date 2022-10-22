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
    let s = sc.next_chars();
    const D: usize = 10;
    let mut cnt = [[0; D]; D];
    let mut prev = s[0].to_digit(10).unwrap() as usize;
    for c in s[1..].iter() {
        let to = (*c).to_digit(10).unwrap() as usize;
        cnt[prev][to] += 1;
        prev = to;
    }
    for i in 0..D {
        for j in 0..D {
            let mut d = [[11; D]; D];
            for k in 0..D {
                d[k][(k + i) % D] = 1;
                d[k][(k + j) % D] = 1;
            }
            for k in 0..D {
                for x in 0..D {
                    for y in 0..D {
                        d[x][y] = std::cmp::min(d[x][y], d[x][k] + d[k][y]);
                    }
                }
            }
            let mut ans = 0;
            'outer: for x in 0..D {
                for y in 0..D {
                    if cnt[x][y] > 0 && d[x][y] == 11 {
                        ans = -1;
                        break 'outer;
                    } else {
                        ans += cnt[x][y] * (d[x][y] - 1);
                    }
                }
            }
            if j > 0 {
                puts!(" ");
            }
            puts!("{}", ans);
        }
        puts!("\n");
    }
}