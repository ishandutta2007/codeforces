// ---------- begin enumerate prime ----------
fn enumerate_prime(n: usize) -> Vec<usize> {
    assert!(n <= 10usize.pow(8));
    if n <= 1 {
        return vec![];
    }
    let batch = (n as f64).sqrt() as usize + 1;
    let mut is_prime = vec![true; batch + 1];
    for i in (2..).take_while(|p| p * p <= batch) {
        if is_prime[i] {
            let mut j = i * i;
            while let Some(p) = is_prime.get_mut(j) {
                *p = false;
                j += i;
            }
        }
    }
    let mut prime = vec![];
    let mut small_prime = vec![];
    for (i, p) in is_prime.iter().enumerate().skip(2) {
        if *p && i <= n {
            prime.push(i);
            small_prime.push(i);
        }
    }
    let mut l = batch;
    while l <= n {
        let r = std::cmp::min(l + batch, n + 1);
        is_prime.clear();
        is_prime.resize(r - l, true);
        for &p in small_prime.iter() {
            let mut j = (l + p - 1) / p * p - l;
            while let Some(is_prime) = is_prime.get_mut(j) {
                *is_prime = false;
                j += p;
            }
        }
        for (i, p) in is_prime.iter().enumerate().filter(|p| *p.1) {
            if *p {
                prime.push(i + l);
            }
        }
        l += batch;
    }
    prime
}
// ---------- end enumerate prime ----------
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

use std::cmp::*;

#[derive(Clone, Debug)]
struct Top2<T> {
    a: T,
    b: T,
}

impl<T: Ord + Copy> Top2<T> {
    fn new(a: T, b: T) -> Self {
        assert!(a < b);
        Top2 { a, b }
    }
    fn merge(&self, rhs: &Self) -> Self {
        use std::cmp::Ordering::*;
        let (a, b) = match self.a.cmp(&rhs.a) {
            Equal => (self.a, min(self.b, rhs.b)),
            Less => (self.a, min(self.b, rhs.a)),
            Greater => (rhs.a, min(self.a, rhs.b)),
        };
        Top2::new(a, b)
    }
}

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let m = *a.iter().max().unwrap();
    let mut dp = vec![Top2::new((m + 1, n), (m + 2, n)); m + 1];
    for (i, &a) in a.iter().enumerate() {
        let dp = &mut dp[a];
        if dp.a.1 == n {
            dp.a = (a, i);
        } else if dp.b.1 == n {
            dp.b = (a, i);
        }
    }
    let prime = enumerate_prime(m);
    for &p in prime.iter() {
        for i in (1..=(m / p)).rev() {
            dp[i] = dp[i].merge(&dp[i * p]);
        }
    }
    let mut ans = (std::u64::MAX, n, n);
    for (i, dp) in dp.iter().enumerate().skip(1) {
        if dp.a.1 < n && dp.b.1 < n {
            let val = dp.a.0 as u64 * dp.b.0 as u64 / i as u64;
            ans = min(ans, (val, dp.a.1, dp.b.1));
        }
    }
    let x = min(ans.1, ans.2);
    let y = max(ans.1, ans.2);
    println!("{} {}", x + 1, y + 1);
}

fn main() {
    run();
}