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
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a: Vec<usize> = sc.next_vec(n);
        let mut z = a.clone();
        z.sort();
        z.dedup();
        for a in a.iter_mut() {
            *a = z.binary_search(a).unwrap();
        }
        let ans = if a.windows(2).filter(|a| a[0] == a[1]).count() <= 1 {
            0
        } else {
            let mut res = n;
            for _ in 0..2 {
                {
                    let mut a = a.clone();
                    let l = a.windows(2).position(|a| a[0] == a[1]).unwrap();
                    let r = a.windows(2).rposition(|a| a[0] == a[1]).unwrap();
                    let mut ans = 0;
                    let mut id = n;
                    for i in (l + 1)..r {
                        if a[i] == a[i - 1] {
                            a[i] = id;
                            a[i + 1] = id;
                            ans += 1;
                            id += 1;
                        }
                    }
                    if a[r] == a[r - 1] && a[r] == a[r + 1] {
                        ans += 1;
                    }
                    res = res.min(ans);
                }
                a.reverse();
            }
            res
        };
        writeln!(out, "{}", ans).ok();
    }
}