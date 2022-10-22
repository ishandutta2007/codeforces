// ---------- begin Foldable Deque ----------
pub struct FoldableDeque<T, F> {
    front: Vec<(T, T)>,
    back: Vec<(T, T)>,
    op: F,
}

impl<T, F> FoldableDeque<T, F>
where
    T: Clone,
    F: Fn(&T, &T) -> T,
{
    pub fn new(op: F) -> Self {
        FoldableDeque {
            front: Vec::new(),
            back: Vec::new(),
            op: op,
        }
    }
    pub fn find(&self) -> Option<T> {
        match (self.front.last(), self.back.last()) {
            (Some(a), Some(b)) => Some((self.op)(&a.1, &b.1)),
            (Some(a), None) => Some(a.1.clone()),
            (None, Some(b)) => Some(b.1.clone()),
            (None, None) => None,
        }
    }
    pub fn clear(&mut self) {
        self.front.clear();
        self.back.clear();
    }
    pub fn len(&self) -> usize {
        self.front.len() + self.back.len()
    }
    pub fn push_back(&mut self, val: T) {
        let sum = self
            .back
            .last()
            .map_or_else(|| val.clone(), |p| (self.op)(&p.1, &val));
        self.back.push((val, sum));
    }
    pub fn push_front(&mut self, val: T) {
        let sum = self
            .front
            .last()
            .map_or_else(|| val.clone(), |p| (self.op)(&val, &p.1));
        self.front.push((val, sum));
    }
    pub fn pop_front(&mut self) -> Option<T> {
        if self.front.is_empty() {
            let a = self.back.clone();
            let m = (self.back.len() + 1) / 2;
            self.back.clear();
            let (f, b) = a.split_at(m);
            for v in f.iter().rev() {
                self.push_front(v.0.clone());
            }
            for v in b.iter() {
                self.push_back(v.0.clone());
            }
        }
        self.front.pop().map(|p| p.0)
    }
    pub fn pop_back(&mut self) -> Option<T> {
        if self.back.is_empty() {
            let a = self.front.clone();
            let m = (self.front.len() + 1) / 2;
            self.front.clear();
            let (f, b) = a.split_at(m);
            for v in b.iter() {
                self.push_front(v.0.clone());
            }
            for v in f.iter().rev() {
                self.push_back(v.0.clone());
            }
        }
        self.back.pop().map(|p| p.0)
    }
    pub fn front(&self) -> Option<&T> {
        self.front
            .last()
            .map_or_else(|| self.back.get(0).map(|p| &p.0), |p| Some(&p.0))
    }
    pub fn back(&self) -> Option<&T> {
        self.back
            .last()
            .map_or_else(|| self.front.get(0).map(|p| &p.0), |p| Some(&p.0))
    }
    pub fn get(&self, k: usize) -> Option<&T> {
        if let Some(po) = self.front.get(self.front.len() - 1 - k) {
            return Some(&po.0);
        }
        let k = k - self.front.len();
        self.back.get(k).map(|po| &po.0)
    }
}
// ---------- end Foldable Deque ----------
// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: u64, b: u64) -> u64 {
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

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: Vec<u64> = sc.next_vec(n);
        let d = a.windows(2).map(|d| d[0].max(d[1]) - d[0].min(d[1])).collect::<Vec<_>>();
        let mut ans = 1;
        let mut deq = FoldableDeque::new(|a, b| binary_gcd(*a, *b));
        let mut x = 0;
        for i in 0..d.len() {
            if deq.len() == 0 {
                if d[i] == 1 {
                    continue;
                }
                deq.push_back(d[i]);
                x = i + 1;
            }
            while x < d.len() && binary_gcd(deq.find().unwrap(), d[x]) > 1 {
                deq.push_back(d[x]);
                x += 1;
            }
            ans = ans.max(deq.len() + 1);
            deq.pop_front();
        }
        writeln!(out, "{}", ans).ok();
    }
}