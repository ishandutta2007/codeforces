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
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: i64 = sc.next();
        let mut a = vec![0i64; n];
        for a in a.iter_mut() {
            *a = sc.next();
        }
        let mut one = vec![];
        let mut two = vec![];
        for a in a {
            let b: usize = sc.next();
            if b == 1 {
                one.push(a);
            } else {
                two.push(a);
            }
        }
        one.sort();
        two.sort();
        let mut ans = 2 * n + 1;
        let mut sum = one.iter().sum::<i64>();
        let mut x = 0;
        for (i, two) in two.iter().rev().enumerate()  {
            sum += two;
            while x < one.len() && sum - one[x] >= m {
                sum -= one[x];
                x += 1;
            }
            if sum >= m {
                ans = ans.min(one.len() - x + 2 * (i + 1));
            }
        }
        let mut sum = 0;
        for (i, one) in one.iter().rev().enumerate() {
            sum += *one;
            if sum >= m {
                ans = ans.min(i + 1);
                break;
            }
        }
        if ans <= 2 * n {
            writeln!(out, "{}", ans).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}