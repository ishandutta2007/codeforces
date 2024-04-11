// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: usize, b: usize) -> usize {
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
// ---------- begin init array ----------
// 
// 
// new(size, zero): zerosize
// init(&mut self): 
// init_with(&mut self, f): zero f
//
// 
// indexMut 
// 
#[derive(Clone)]
pub struct InitArray<T> {
    data: Vec<T>,
    used: Vec<bool>,
    list: Vec<u32>,
    zero: T,
}

impl<T: Copy> InitArray<T> {
    pub fn new(zero: T, size: usize) -> Self {
        InitArray {
            data: vec![zero; size],
            used: vec![false; size],
            list: vec![],
            zero: zero,
        }
    }
    pub fn init(&mut self) {
        self.init_with(|_, _| ());
    }
    pub fn init_with<F>(&mut self, mut f: F)
    where
        F: FnMut(usize, T),
    {
        for x in self.list.drain(..) {
            let x = x as usize;
            self.used[x] = false;
            let v = std::mem::replace(&mut self.data[x], self.zero);
            f(x, v);
        }
    }
}

impl<T> std::ops::Index<usize> for InitArray<T> {
    type Output = T;
    fn index(&self, pos: usize) -> &Self::Output {
        &self.data[pos]
    }
}

impl<T> std::ops::IndexMut<usize> for InitArray<T> {
    fn index_mut(&mut self, pos: usize) -> &mut Self::Output {
        if !self.used[pos] {
            self.used[pos] = true;
            self.list.push(pos as u32);
        }
        &mut self.data[pos]
    }
}
// ---------- end init array ----------

pub struct Sieve {
    size: usize,
    factor: Vec<usize>,
}

impl Sieve {
    pub fn new(size: usize) -> Self {
        let mut factor = (0..=size).collect::<Vec<_>>();
        for p in 2..=size {
            if p == factor[p] {
                for j in 1..=(size / p) {
                    factor[j * p] = p;
                }
            }
        }
        Self {
            size,
            factor,
        }
    }
    pub fn factor(&self, x: usize) -> Option<usize> {
        assert!(1 <= x && x <= self.size);
        if x == 1 {
            None
        } else {
            Some(self.factor[x])
        }
    }
}

fn read() -> Vec<usize> {
    let mut s = String::new();
    use std::io::Read;
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace().flat_map(|s| s.parse::<usize>());
    it.next();
    it.collect()
}

fn main() {
    let a = read();
    let m = *a.iter().max().unwrap();
    let mut elem = vec![false; m + 1];
    for a in a {
        elem[a] = true;
    }
    let sieve = Sieve::new(m);
    let factorize = |mut x: usize, res: &mut Vec<(usize, i32)>| {
        res.clear();
        res.push((1, 1));
        while let Some(p) = sieve.factor(x) {
            let len = res.len();
            for i in 0..len {
                let (a, b) = res[i];
                res.push((a * p, -b));
            }
            while x % p == 0 {
                x /= p;
            }
        }
    };
    let mut memo = InitArray::new(0i32, m + 1);
    let mut stack = vec![];
    let mut list = vec![];
    let mut ans = m;
    for g in 1..=m {
        memo.init();
        stack.clear();
        for x in (1..=(m / g)).rev().filter(|k| elem[*k * g]) {
            factorize(x, &mut list);
            let mut cnt = 0;
            for (x, s) in list.drain(..) {
                cnt += memo[x] * s;
            }
            while cnt > 0 {
                let y = stack.pop().unwrap();
                if binary_gcd(x, y) == 1 {
                    ans = ans.max(x * y * g);
                    cnt -= 1;
                }
                factorize(y, &mut list);
                for (x, _) in list.drain(..) {
                    memo[x] -= 1;
                }
            }
            stack.push(x);
            factorize(x, &mut list);
            for (x, _) in list.drain(..) {
                memo[x] += 1;
            }
        }
    }
    println!("{}", ans);
}