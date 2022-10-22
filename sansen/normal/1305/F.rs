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

struct RNG(usize);

impl RNG {
    fn new() -> Self {
        RNG(2463534242)
    }
    fn next(&mut self) -> usize {
        let x = &mut self.0;
        *x = *x ^ (*x << 13);
        *x = *x ^ (*x >> 17);
        *x = *x ^ (*x << 5);
        *x
    }
}

fn factorize(mut n: u64) -> Vec<u64> {
    let mut ans = vec![];
    for k in 2.. {
        if k * k > n {
            break;
        }
        if n % k == 0 {
            while n % k == 0 {
                n /= k;
            }
            ans.push(k);
        }
    }
    if n > 1 {
        ans.push(n);
    }
    ans
}

fn run() {
    input! {
        n: usize,
        a: [u64; n],
    }
    let mut ans = 0;
    for a in a.iter() {
        ans += *a % 2;
    }
    let mut rng = RNG::new();
    for _ in 0..10000 {
        rng.next();
    }
    for _ in 0..50 {
        let k = rng.next() % n;
        let x = a[k];
        for v in (x - 1)..=(x + 1) {
            let f = factorize(v);
            for p in f {
                let mut sum = 0;
                for a in a.iter() {
                    if *a < p {
                        sum += p - *a;
                    } else {
                        let y = *a % p;
                        sum += std::cmp::min(y, p - y);
                    }
                }
                if sum < ans {
                    ans = sum;
                }
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}