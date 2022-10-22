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

fn can(a: &Vec<i64>, k: i64, m: i64) -> bool {
    let n = a.len();
    let mut sum = a.clone();
    sum.push(0);
    for i in (0..n).rev() {
        sum[i] += sum[i + 1];
    }
    let mut r = 0;
    for l in 0..n {
        while r < n && a[r] - a[l] <= m {
            r += 1;
        }
        let mut d = l as i64 * a[l] - (sum[0] - sum[l]);
        d += sum[r] - (n - r) as i64 * (a[l] + m);
        if d <= k {
            return true;
        }
    }
    let mut l = n;
    for r in (0..n).rev() {
        while l > 0 && a[r] - a[l - 1] <= m {
            l -= 1;
        }
        let mut d = 0;
        if l > 0 {
            d += l as i64 * (a[r] - m) - (sum[0] - sum[l]);
        }
        if r < n - 1 {
            d += sum[r + 1] - (n - r - 1) as i64 * a[r];
        }
        if d <= k {
            return true;
        }
    }
    false
}

fn run() {
    input! {
        n: usize,
        k: i64,
        a: [i64; n],
    }
    let mut a = a;
    a.sort();
    let mut ng = -1;
    let mut ok = 1_000_000_000;
    while ok - ng > 1 {
        let m = (ok + ng) / 2;
        if can(&a, k, m) {
            ok = m;
        } else {
            ng = m;
        }
    }
    println!("{}", ok);
}

fn main() {
    run();
}