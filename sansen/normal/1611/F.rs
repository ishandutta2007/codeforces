// ---------- begin Foldable Deque ----------
pub struct FoldableDeque<T, F> {
    front: Vec<(T, T)>,
    back: Vec<(T, T)>,
    op: F,
}

impl<T, F> FoldableDeque<T, F>
where
    T: Clone,
    F: FnMut(&T, &T) -> T,
{
    pub fn new(op: F) -> Self {
        FoldableDeque {
            front: Vec::new(),
            back: Vec::new(),
            op: op,
        }
    }
    pub fn find(&mut self) -> Option<T> {
        match (self.front.last(), self.back.last()) {
            (Some(a), Some(b)) => Some((self.op)(&a.1, &b.1)),
            (x, y) => x.or(y).map(|p| p.1.clone()),
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
        let sum = match self.back.last() {
            Some(p) => (self.op)(&p.1, &val),
            None => val.clone(),
        };
        self.back.push((val, sum));
    }
    pub fn push_front(&mut self, val: T) {
        let sum = match self.front.last() {
            Some(p) => (self.op)(&val, &p.1),
            None => val.clone(),
        };
        self.front.push((val, sum));
    }
    pub fn pop_front(&mut self) -> Option<T> {
        if self.front.is_empty() {
            let mut back = std::mem::take(&mut self.back);
            let m = (back.len() + 1) / 2;
            for (v, _) in back.drain(..m).rev() {
                self.push_front(v);
            }
            if !back.is_empty() {
                back[0].1 = back[0].0.clone();
                let (f, t) = back.split_at_mut(1);
                let mut pre = &f[0].1;
                for b in t.iter_mut() {
                    b.1 = (self.op)(pre, &b.0);
                    pre = &b.1;
                }
            }
            self.back = back;
        }
        self.front.pop().map(|p| p.0)
    }
    pub fn pop_back(&mut self) -> Option<T> {
        if self.back.is_empty() {
            let mut front = std::mem::take(&mut self.front);
            let m = (front.len() + 1) / 2;
            for (v, _) in front.drain(..m).rev() {
                self.push_back(v);
            }
            if !front.is_empty() {
                front[0].1 = front[0].0.clone();
                let (t, f) = front.split_at_mut(1);
                let mut pre = &t[0].1;
                for f in f.iter_mut() {
                    f.1 = (self.op)(&f.0, pre);
                    pre = &f.1;
                }
            }
            self.front = front;
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
        let s: i64 = sc.next();
        let a: Vec<i64> = sc.next_vec(n);
        // min
        type T = (i64, i64);
        let merge = |a: &T, b: &T| -> T {
            (a.0 + b.0, a.1.min(a.0 + b.1))
        };
        let mut deq = FoldableDeque::new(merge);
        let mut ans = None;
        for (i, a) in a.iter().enumerate() {
            let r = i + 1;
            deq.push_back((*a, std::cmp::min(*a, 0)));
            while deq.find().map_or(false, |p| s + p.1 < 0) {
                deq.pop_front();
            }
            if deq.len() > 0 {
                let l = r - deq.len();
                ans = match ans {
                    Some((a, b)) if b - a > r - l => ans,
                    _ => Some((l, r)),
                };
            }
        }
        if let Some((l, r)) = ans {
            writeln!(out, "{} {}", l + 1, r).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}