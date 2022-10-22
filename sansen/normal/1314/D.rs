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

struct RNG {
    x: usize,
}

impl RNG {
    fn new() -> Self {
        RNG {
            x: 2463534242,
        }
    }
    fn next(&mut self) -> usize {
        let x = &mut self.x;
        *x = *x ^ (*x << 13);
        *x = *x ^ (*x >> 17);
        *x = *x ^ (*x << 5);
        *x
    }
}

fn run() {
    input! {
        n: usize,
        k: usize,
        a: [[u32; n]; n],
    }
    let mut rng = RNG::new();
    let inf = 1_000_000_000u32 + 1;
    let mut ans = inf;
    for _ in 0..10000 {
        let mut color = vec![0; n];
        for c in color[1..].iter_mut() {
            *c = rng.next() & 1;
        }
        let mut dp = vec![inf; n];
        dp[0] = 0;
        for _ in 0..k {
            let mut next = vec![inf; n];
            for (a, (x, dp)) in a.iter().zip(color.iter().zip(dp.iter())) {
                if *dp == inf {
                    continue;
                }
                for (a, (y, next)) in a.iter().zip(color.iter().zip(next.iter_mut())) {
                    if *x != *y {
                        *next = std::cmp::min(*next, *dp + *a);
                    }
                }
            }
            dp = next;
        }
        ans = std::cmp::min(ans, dp[0]);
    }
    println!("{}", ans);
}

fn main() {
    run();
}