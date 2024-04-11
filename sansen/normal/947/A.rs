// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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

//

fn run() {
    input! {
        n: usize,
    }
    let p = enumerate_prime(n);
    let mut dp = (0..=n).collect::<Vec<_>>();
    for &p in p.iter() {
        for i in 2..=(n / p) {
            dp[i * p].chmin((i - 1) * p + 1);
        }
    }
    let mut ans = n;
    for &p in p.iter() {
        if n % p == 0 {
            let d = n / p;
            for i in ((d - 1) * p + 1)..=n {
                ans.chmin(dp[i]);
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}