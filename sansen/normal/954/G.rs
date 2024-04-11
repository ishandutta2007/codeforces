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
        r: usize,
        k: u64,
        a: [u64; n],
    }
    let mut b = vec![0; n + 2 * r + 1];
    for (i, &a) in a.iter().enumerate() {
        if i <= r {
            b[0] += a;
        } else {
            b[i - r] += a;
        }
        b[i + r + 1] -= a;
    }
    for i in 1..n {
        b[i] += b[i - 1];
    }
    let a = b;
    let mut imos = Vec::with_capacity(n + 2 * r + 1);
    let mut valid = |m: u64| -> bool {
        imos.clear();
        imos.resize(n + 2 * r + 1, 0);
        let mut sum = 0;
        for i in 0..n {
            if i > 0 {
                imos[i] += imos[i - 1];
            }
            if a[i] + imos[i] < m {
                let v = m - (a[i] + imos[i]);
                imos[i] += v;
                imos[i + 2 * r + 1] -= v;
                sum += v;
            }
            if sum > k {
                break;
            }
        }
        sum <= k
    };
    let mut ok = 0;
    let mut ng = 1_000_000_000_000_000_000 + 500_000 * 1_000_000_000 + 1;
    while ng - ok > 1 {
        let mid = (ok + ng) / 2;
        if valid(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    println!("{}", ok);
}

fn main() {
    run();
}