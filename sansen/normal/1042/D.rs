// ---------- begin fenwick tree ----------
#[allow(dead_code)]
mod fenwick {
    type T = i64;
    const ZERO: T = 0;
    pub struct Tree {
        a: Vec<T>,
    }
    impl Tree {
        pub fn new(n: usize) -> Tree {
            Tree {
                a: vec![ZERO; n + 1],
            }
        }
        pub fn add(&mut self, mut x: usize, v: T) {
            while x < self.a.len() {
                self.a[x] += v;
                x += x & (!x + 1);
            }
        }
        pub fn sum(&self, mut x: usize) -> T {
            debug_assert!(x < self.a.len());
            let mut res = ZERO;
            while x > 0 {
                res += self.a[x];
                x -= x & (!x + 1);
            }
            res
        }
        pub fn search(&self, s: T) -> usize {
            debug_assert!(self.sum(self.a.len() - 1) >= s);
            let mut k = 1;
            while 2 * k < self.a.len() {
                k *= 2;
            }
            let mut x = 0;
            let mut w = ZERO;
            while k > 0 {
                if k + x < self.a.len() && w + self.a[x + k] < s {
                    w += self.a[x + k];
                    x += k;
                }
                k >>= 1;
            }
            x + 1
        }
    }
}
// ---------- end fenwick tree ----------
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

fn run() {
    input! {
        n: usize,
        t: i64,
        a: [i64; n],
    }
    let mut sum = a.clone();
    sum.push(0);
    let mut z = vec![];
    z.push(0);
    for i in (0..n).rev() {
        sum[i] += sum[i + 1];
        z.push(sum[i]);
        z.push(sum[i] - t);
    }
    z.push(std::i64::MIN);
    z.push(std::i64::MAX);
    z.sort();
    z.dedup();
    let mut bit = fenwick::Tree::new(z.len());
    bit.add(z.binary_search(&0).unwrap(), 1);
    let mut ans = 0i64;
    for i in (0..n).rev() {
        let k = z.binary_search(&(sum[i] - t)).unwrap();
        ans += bit.sum(z.len()) - bit.sum(k);
        let k = z.binary_search(&sum[i]).unwrap();
        bit.add(k, 1);
    }
    println!("{}", ans);
}

fn main() {
    run();
}