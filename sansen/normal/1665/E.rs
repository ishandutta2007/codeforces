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
        let a: Vec<u32> = sc.next_vec(n);
        let q: usize = sc.next();
        let ask = (0..q)
            .map(|_| {
                let l = sc.next::<usize>() - 1;
                let r = sc.next::<usize>();
                (l, r)
            })
            .collect::<Vec<_>>();
        let ans = solve(a, ask);
        for a in ans {
            writeln!(out, "{}", a).ok();
        }
    }
}

fn solve(a: Vec<u32>, ask: Vec<(usize, usize)>) -> Vec<u32> {
    let size = a.len().next_power_of_two();
    let mut seg = vec![vec![]; 2 * size];
    for (seg, a) in seg[size..].iter_mut().zip(a) {
        seg.push(a);
    }
    for i in (1..size).rev() {
        let mut c = seg[2 * i]
            .iter()
            .chain(seg[2 * i + 1].iter())
            .cloned()
            .collect::<Vec<_>>();
        c.sort();
        c.truncate(31);
        seg[i] = c;
    }
    ask.into_iter()
        .map(|(l, r)| {
            let mut d = vec![];
            let mut l = l + size;
            let mut r = r + size;
            while l < r {
                if l & 1 == 1 {
                    d.extend(seg[l].iter().cloned());
                    l += 1;
                }
                if r & 1 == 1 {
                    r -= 1;
                    d.extend(seg[r].iter().cloned());
                }
                l >>= 1;
                r >>= 1;
            }
            d.sort();
            d.truncate(32);
            let mut ans = (1 << 30) - 1;
            for i in (0..30).rev() {
                let mask = ans ^ (1 << i);
                if d.iter().filter(|d| **d & mask == **d).count() >= 2 {
                    ans ^= 1 << i;
                }
            }
            ans
        })
        .collect()
}