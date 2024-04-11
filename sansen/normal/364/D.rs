// ---------- begin Exact Division ----------
// reference: https://min-25.hatenablog.com/entry/2017/08/20/171214
pub struct ExactDivision {
    a: u64,
    b: u64,
}

impl ExactDivision {
    pub fn new(d: u64) -> Self {
        let d = d;
        let mut m = d;
        for _ in 0..5 {
            m *= 2 - d * m;
        }
        Self { a: !0 / d, b: m ,}
    }
    pub fn division(&self, val: u64) -> Option<u64> {
        let res = val * self.b;
        if res <= self.a {
            Some(res)
        } else {
            None
        }
    }
}
// ---------- end Exact Division ----------

fn factorize(mut n: u64) -> Vec<(u64, u32)> {
    let mut res = vec![];
    for &p in [2, 3].iter() {
        let mut c = 0;
        while n % p == 0 {
            c += 1;
            n /= p;
        }
        if c > 0 {
            res.push((p, c));
        }
    }
    let mut k = 5;
    let mut add = 2;
    while k * k <= n {
        let mut c = 0;
        while n % k == 0 {
            n /= k;
            c += 1;
        }
        if c > 0 {
            res.push((k, c));
        }
        k += add;
        add ^= 6;
    }
    if n > 1 {
        res.push((n, 1));
    }
    res
}

fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> usize {
    static mut X: usize = 0;
    unsafe {
        if X == 0 {
            X = rand_memory();
        }
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------

#[target_feature(enable = "avx2")]
unsafe fn run() {
    input! {
        n: usize,
        a: [u64; n],
    }
    let mut ans = 1;
    for _ in 0..20 {
        let v = a[rand() % n];
        let f = factorize(v);
        let mut exact = vec![];
        for &(p, _) in f.iter() {
            exact.push(ExactDivision::new(p));
        }
        let mut d = Vec::with_capacity(f.iter().fold(1, |s, p| s * (p.1 + 1)) as usize);
        d.push(1);
        let mut step = vec![];
        for &(p, c) in f.iter() {
            let len = d.len();
            step.push(len);
            let mut mul = 1;
            for _ in 1..=c {
                mul *= p;
                for j in 0..len {
                    let v = d[j] * mul;
                    d.push(v);
                }
            }
        }
        let mut cnt = vec![0; d.len()];
        for a in a.iter() {
            let mut pos = 0;
            let mut x = *a;
            for ((&(p, c), exact), step) in f.iter().zip(exact.iter()).zip(step.iter()) {
                if p == 2 {
                    for _ in 0..c {
                        if x & 1 == 0 {
                            x >>= 1;
                            pos += *step;
                        } else {
                            break;
                        }
                    }
                } else {
                    for _ in 0..c {
                        if let Some(v) = exact.division(x) {
                            x = v;
                            pos += *step;
                        } else {
                            break;
                        }
                    }
                }
            }
            cnt[pos] += 1;
        }
        for &(p, _) in f.iter() {
            let mut x = d.len();
            for i in (0..d.len()).rev() {
                if d[i] % p == 0 {
                    while d[x - 1] * p != d[i] {
                        x -= 1;
                    }
                    cnt[x - 1] += cnt[i];
                }
            }
        }
        for (c, d) in cnt.iter().zip(d.iter()) {
            if 2 * *c >= n {
                ans = ans.max(*d);
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    unsafe {
    run();
    }
}