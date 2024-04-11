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
pub trait Monoid<S> {
    fn merge(&self, rhs: &Self) -> Self;
    fn e() -> Self;
}

pub struct SegmentTree<S, T> {
    data: Vec<T>,
    size: usize,
    phantom: std::marker::PhantomData<S>,
}

impl<S, T> SegmentTree<S, T>
where
    T: Monoid<S> + Clone,
{
    pub fn new(size: usize) -> Self {
        let size = size.next_power_of_two();
        Self {
            data: vec![T::e(); 2 * size],
            size: size,
            phantom: std::marker::PhantomData
        }
    }
    pub fn build(a: &[T]) -> Self {
        let size = a.len().next_power_of_two();
        let mut data = vec![T::e(); 2 * size];
        data[size..(size + a.len())].clone_from_slice(a);
        for i in (1..size).rev() {
            data[i] = data[2 * i].merge(&data[2 * i + 1]);
        }
        Self { data, size, phantom: std::marker::PhantomData }
    }
}

impl<S, T> SegmentTree<S, T>
where
    T: Monoid<S>,
{
    pub fn find(&self, l: usize, r: usize) -> T {
        assert!(l <= r && r <= self.size);
        if l == r {
            return T::e();
        }
        let mut x = l + self.size;
        let mut y = r + self.size;
        let mut p = T::e();
        let mut q = T::e();
        let data = &self.data;
        while x < y {
            if x & 1 == 1 {
                p = p.merge(&data[x]);
                x += 1;
            }
            if y & 1 == 1 {
                y -= 1;
                q = data[y].merge(&q);
            }
            x >>= 1;
            y >>= 1;
        }
        p.merge(&q)
    }
    pub fn set_at(&mut self, x: usize, v: T) {
        assert!(x < self.size);
        let mut x = x + self.size;
        let data = &mut self.data;
        data[x] = v;
        x >>= 1;
        while x >= 1 {
            data[x] = data[2 * x].merge(&data[2 * x + 1]);
            x >>= 1;
        }
    }
    pub fn max_right<F>(&mut self, l: usize, f: F) -> usize
    where
        F: Fn(&T) -> bool,
    {
        assert!(f(&T::e()));
        if l == self.size {
            return self.size;
        }
        assert!(l <= self.size);
        let mut l = l + self.size;
        let mut r = 2 * self.size;
        let mut s = T::e();
        while l < r {
            if l & 1 == 1 {
                let v = s.merge(&self.data[l]);
                if !f(&v) {
                    while l < self.size {
                        l *= 2;
                        let p = s.merge(&self.data[l]);
                        if f(&p) {
                            s = p;
                            l += 1;
                        }
                    }
                    return l - self.size;
                } else {
                    s = v;
                }
                l += 1;
            }
            l >>= 1;
            r >>= 1;
        }
        self.size
    }
}

struct GCD;
impl Monoid<GCD> for u32 {
    fn merge(&self, rhs: &Self) -> Self {
        binary_gcd(*self, *rhs)
    }
    fn e() -> Self {
        0
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

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

// 1gcdx
// 1gcdx
// 

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let mut a = vec![0u32; n];
    for a in a.iter_mut() {
        *a = sc.next();
    }
    let mut seg = SegmentTree::<GCD, u32>::build(&a);
    let q: u32 = sc.next();
    for _ in 0..q {
        let op: u8 = sc.next();
        if op == 1 {
            let mut l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            let x = sc.next::<u32>();
            for i in 0..2 {
                let p = seg.max_right(l, |v| *v % x == 0);
                if p >= r {
                    writeln!(out, "YES").ok();
                    break;
                }
                if i == 1 {
                    writeln!(out, "NO").ok();
                }
                l = p + 1;
            }
        } else {
            let x = sc.next::<usize>() - 1;
            let y = sc.next::<u32>();
            seg.set_at(x, y);
        }
    }
}