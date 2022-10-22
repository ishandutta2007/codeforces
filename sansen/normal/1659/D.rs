mod util {
    pub trait Join {
        fn join(self, sep: &str) -> String;
    }

    impl<T, I> Join for I
    where
        I: Iterator<Item = T>,
        T: std::fmt::Display,
    {
        fn join(self, sep: &str) -> String {
            let mut s = String::new();
            use std::fmt::*;
            for (i, v) in self.enumerate() {
                if i > 0 {
                    write!(&mut s, "{}", sep).ok();
                }
                write!(&mut s, "{}", v).ok();
            } 
            s
        }
    }
}

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
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

// a_0  k 
// a[0..k] = 1
// a[k] = 0
// 
// a[1] = u ...
// 
// a[n - 1] n, 1, 0 
// n -> 1
// 1 -> 0, 1
// 0 -> 0
// A1
// ...

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let c: Vec<usize> = sc.next_vec(n);
        let mut one = c.iter().sum::<usize>() / n;
        let mut ans = vec![0; n];
        let mut imos = vec![0; n + 1];
        for i in (0..n).rev() {
            imos[i] += imos[i + 1];
            let c = c[i] - imos[i];
            let len = i + 1;
            if c == 0 {
                break;
            } else {
                assert!(c == 1 || c == len, "ERROR: {}, {}", c, len);
                imos[i] += 1;
                if one <= i {
                    imos[i - one] -= 1;
                }
                if c == len {
                    ans[i] = 1;
                    one -= 1;
                }
            }
        }
        use util::*;
        writeln!(out, "{}", ans.iter().join(" ")).ok();
    }
}