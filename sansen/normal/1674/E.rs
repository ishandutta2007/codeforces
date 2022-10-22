fn run() {
    input! {
        n: usize,
        a: [i64; n],
    }
    let mut z = a.clone();
    z.sort();
    let mut ans = (z[0] + 1) / 2 + (z[1] + 1) / 2;
    for a in a.windows(2) {
        let mut ng = 0;
        let mut ok = a[0] + a[1];
        while ok - ng > 1 {
            let mid = (ok + ng) / 2;
            if (a[0] - mid).max(0) + (a[1] - mid).max(0) <= mid {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans = ans.min(ok);
    }
    for a in a.windows(3) {
        let g = a[0].min(a[2]);
        let mut v = g;
        if a[0] > g {
            v += (a[0] - g + 1) / 2;
        }
        if a[2] > g {
            v += (a[2] - g + 1) / 2;
        }
        ans = ans.min(v);
    }
    println!("{}", ans);
}

fn main() {
    run();
}

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