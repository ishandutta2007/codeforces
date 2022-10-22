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
        let m: usize = sc.next();
        let mut a: Vec<i32> = sc.next_vec(n);
        let mut b: Vec<i32> = sc.next_vec(m);
        let x = a.iter().position(|a| *a >= 0).unwrap_or(a.len());
        let (al, ar) = a.split_at_mut(x);
        let x = b.iter().position(|a| *a >= 0).unwrap_or(b.len());
        let (bl, br) = b.split_at_mut(x);
        al.iter_mut().for_each(|a| *a *= -1);
        al.reverse();
        bl.iter_mut().for_each(|a| *a *= -1);
        bl.reverse();
        let solve = |a: &[i32], b: &[i32]| -> i32 {
            let mut ans = 0;
            for a in a.iter() {
                if b.binary_search(a).is_ok() {
                    ans += 1;
                }
            }
            let mut c = vec![];
            for a in a.iter() {
                c.push((*a, 0));
            }
            for b in b.iter() {
                c.push((*b, 1));
            }
            c.sort();
            let mut fix = ans;
            let mut cnt = 0;
            for (x, op) in c {
                if op == 0 {
                    cnt += 1;
                    if b.binary_search(&x).is_ok() {
                        fix -= 1;
                    }
                } else {
                    let p = b.binary_search(&x).unwrap() + 1;
                    let q = b.binary_search_by_key(&(x - cnt, 1), |b| (*b, 0)).unwrap_err();
                    ans = ans.max(fix + (p - q) as i32);
                }
            }
            ans
        };
        let ans = solve(al, bl) + solve(ar, br);
        writeln!(out, "{}", ans).ok();
    }
}