// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: u32, b: u32) -> u32 {
    if a == 0 || b == 0 {
        return a + b;
    }
    let x = a.trailing_zeros();
    let y = b.trailing_zeros();
    let mut a = a >> x;
    let mut b = b >> y;
    while a != b {
        let x = (a ^ b).trailing_zeros();
        if a < b {
            std::mem::swap(&mut a, &mut b);
        }
        a = (a - b) >> x;
    }
    a << x.min(y)
}
// ---------- end binary_gcd ----------
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

type Deque<T> = std::collections::VecDeque<T>;

fn concat<T>(a: &mut Deque<T>, b: &mut Deque<T>) {
    if a.len() >= b.len() {
        for b in b.drain(..) {
            a.push_back(b);
        }
    } else {
        for a in a.drain(..).rev() {
            b.push_front(a);
        }
        std::mem::swap(a, b);
    }
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut p = Deque::new();
        for i in 0..n {
            let a: u32 = sc.next();
            let mut deq = Deque::new();
            deq.push_back((a, i));
            p.push_back(deq);
        }
        let mut ans = vec![];
        while p.len() > 1 {
            let mut a = p.pop_front().unwrap();
            let mut b = p.pop_front().unwrap();
            if binary_gcd(a.back().unwrap().0, b.front().unwrap().0) == 1 {
                let (_, k) = b.pop_front().unwrap();
                ans.push(k + 1);
                p.push_back(a);
                if !b.is_empty() {
                    p.push_front(b);
                }
            } else {
                concat(&mut a, &mut b);
                p.push_front(a);
            }
        }
        if p.len() == 1 {
            let mut deq = p.pop_front().unwrap();
            while deq.len() > 0 && binary_gcd(deq.front().unwrap().0, deq.back().unwrap().0) == 1 {
                ans.push(deq.pop_front().unwrap().1 + 1);
            }
        }
        write!(out, "{}", ans.len()).ok();
        for a in ans {
            write!(out, " {}", a).ok();
        }
        writeln!(out).ok();
    }
}