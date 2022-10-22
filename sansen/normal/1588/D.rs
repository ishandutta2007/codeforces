// ---------- begin recurse ----------
// reference
// https://twitter.com/noshi91/status/1393952665566994434
// https://twitter.com/shino16_cp/status/1393933468082397190
pub fn recurse<A, R, F>(f: F) -> impl Fn(A) -> R
where
    F: Fn(&dyn Fn(A) -> R, A) -> R,
{
    fn call<A, R, F>(f: &F, a: A) -> R
    where
        F: Fn(&dyn Fn(A) -> R, A) -> R,
    {
        f(&|a| call(f, a), a)
    }
    move |a| call(&f, a)
}
// ---------- end recurse ----------
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
        let s = (0..n).map(|_| sc.next_bytes()).collect::<Vec<_>>();
        let map = std::cell::RefCell::new(std::collections::BTreeMap::<[usize; 10], Vec<u8>>::new());
        let s = recurse(|rec, pos: [usize; 10]| -> Vec<u8> {
            if let Some(v) = map.borrow().get(&pos) {
                return v.clone();
            }
            let mut p = vec![];
            for a in "aA".bytes() {
                for i in 0..26 {
                    let c = a + i;
                    let mut pos = pos;
                    let mut ok = true;
                    for (pos, s) in pos.iter_mut().zip(&s) {
                        if let Some(x) = s[*pos..].iter().position(|s| *s == c) {
                            *pos += x + 1;
                        } else {
                            ok = false;
                        }
                    }
                    if ok {
                        let mut s = rec(pos);
                        s.insert(0, c);
                        if s.len() > p.len() {
                            p = s;
                        }
                    }
                }
            }
            map.borrow_mut().insert(pos, p.clone());
            p
        })([0; 10]);
        println!("{}", s.len());
        println!("{}", s.iter().map(|s| *s as char).collect::<String>());
    }
}