fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn main() {
    let n = read();
    let (small, large) = prime_count(n);
    let pi = |m: usize| -> usize {
        if m < small.len() {
            small[m]
        } else {
            large[n / m]
        }
    };
    let mut ans = 0;
    for i in 2..small.len() {
        if small[i - 1] == small[i] {
            continue;
        }
        ans += pi(n / i) - small[i];
        if i.pow(3) <= n {
            ans += 1;
        }
    }
    println!("{}", ans);
}

// ---------- begin prime count ----------
pub fn prime_count(n: usize) -> (Vec<usize>, Vec<usize>) {
    let sqrt = (1..).find(|p| p * p > n).unwrap() - 1;
    let mut large = vec![0; sqrt + 1];
    let mut small = vec![0; sqrt + 1];
    for (i, (large, small)) in large.iter_mut().zip(&mut small).enumerate().skip(1) {
        *large = n / i - 1;
        *small = i - 1;
    }
    let mut up = sqrt;
    for p in 2..=sqrt {
        if small[p] == small[p - 1] {
            continue;
        }
        let pi = small[p] - 1;
        let q = p * p;
        let d = sqrt / p;
        for i in 1..=d {
            large[i] -= large[i * p] - pi;
        }
        let m = n / p;
        while up * up > m {
            up -= 1;
        }
        let r = sqrt.min(n / q);
        for i in (d + 1)..=r.min(up) {
            large[i] -= small[m / i] - pi;
        }
        let mut q = up;
        for i in (up + 1)..=r {
            if q * i > m {
                q -= 1;
            }
            large[i] -= small[q] - pi;
        }
        for i in (p..=d).rev() {
            let sub = small[i] - pi;
            small[(i * p)..].iter_mut().take(p).for_each(|p| *p -= sub);
        }
    }
    (small, large)
}
// ---------- end prime count ----------
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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