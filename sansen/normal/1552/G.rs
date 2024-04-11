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

fn run<W: Write>(sc: &mut scanner::Scanner, _: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let k: usize = sc.next();
    let mut trans = vec![];
    let mut ok = (1u64 << n) - 1;
    for _ in 0..k {
        let m: usize = sc.next();
        let mut mask = 0u64;
        for _ in 0..m {
            let k: usize = sc.next::<usize>() - 1;
            mask |= 1 << k;
        }
        let cnt = (mask & ok).count_ones() as usize;
        ok &= !mask;
        let mut next = vec![0u64; m + 1];
        for i in 1..=m {
            next[i] = (next[i - 1] | ((next[i - 1] | !mask) + 1)) & mask;
        }
        trans.push((mask, cnt, next));
    }
    if n > 1 && ok > 0 {
        println!("REJECTED");
        return;
    }
    let ok = recurse(|f, (pos, bit): (usize, u64)| -> bool {
        if pos == k {
            let cnt = bit.count_ones();
            return bit == (1 << cnt) - 1;
        }
        let (mask, cnt, ref trans) = trans[pos];
        let one = (mask & bit).count_ones() as usize;
        let x = bit & !mask;
        trans[one..=(one + cnt)]
            .iter()
            .all(|t| f((pos + 1, x | *t)))
    })((0, 0));
    if ok {
        println!("ACCEPTED");
    } else {
        println!("REJECTED");
    }
}