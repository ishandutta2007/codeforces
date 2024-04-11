pub struct InitArray<T> {
    data: Vec<T>,
    used: Vec<bool>,
    list: Vec<usize>,
    zero: T,
}

impl<T: Copy> InitArray<T> {
    pub fn new(size: usize, zero: T) -> Self {
        Self {
            data: vec![zero; size],
            used: vec![false; size],
            list: vec![],
            zero: zero,
        }
    }
    pub fn init(&mut self) {
        for x in self.list.drain(..) {
            self.used[x] = false;
            self.data[x] = self.zero;
        }
    }
    pub fn for_each<F>(&mut self, mut f: F)
    where
        F: FnMut(usize, &mut T),
    {
        for &x in self.list.iter() {
            f(x, &mut self.data[x]);
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
            self.list.push(pos);
        }
        &mut self.data[pos]
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

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    let m = 2000000;
    let mut f = (0..=m).collect::<Vec<_>>();
    for i in (2..).take_while(|p| p * p <= m) {
        if i == f[i] {
            for j in i..=(m / i) {
                f[j * i] = i;
            }
        }
    }
    let factorize = |mut n: usize, d: &mut Vec<usize>| {
        d.clear();
        d.push(1);
        while n > 1 {
            let p = f[n];
            let mut cnt = 0;
            while n % p == 0 {
                n /= p;
                cnt += 1;
            }
            let len = d.len();
            let mut m = 1;
            for _ in 0..cnt {
                m *= p;
                for i in 0..len {
                    let v = d[i] * m;
                    d.push(v);
                }
            }
        }
    };
    let mut cnt = InitArray::new(m + 1, 0usize);
    let mut divisor = vec![];
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a: Vec<i64> = sc.next_vec(n);
        a.sort();
        let v = a[0];
        for a in a.iter_mut() {
            *a -= v;
        }
        let a = a.iter().map(|a| *a as usize).collect::<Vec<_>>();
        if a.windows((n + 1) / 2).any(|a| a.iter().all(|b| *b == a[0])) {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut ans = 1;
        for (i, x) in a.iter().enumerate() {
            cnt.init();
            let mut geta = 1;
            for y in a[(i + 1)..].iter() {
                let diff = *y - *x;
                if diff == 0 {
                    geta += 1;
                    continue;
                }
                factorize(diff, &mut divisor);
                for &d in divisor.iter() {
                    cnt[d] += 1;
                }
            }
            cnt.for_each(|x, c| {
                if 2 * (*c + geta) >= n {
                    ans = ans.max(x);
                }
            });
        }
        writeln!(out, "{}", ans).ok();
    }
}