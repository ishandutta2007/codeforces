fn run() {
    input! {
        p: [(i64, i64); 3],
    }
    let mut p = p;
    let mut ans = vec![(0, 10i64.pow(18), 0, 0)];
    for i in 0..2 {
        let find = |x: i64| -> Vec<(i64, i64, i64, i64)> {
            let mut ans = vec![];
            for p in p.iter() {
                if p.0 != x {
                    ans.push((p.0, x, p.1, p.1));
                }
            }
            let u = p.iter().map(|p| p.1).max().unwrap();
            let d = p.iter().map(|p| p.1).min().unwrap();
            if u > d {
                ans.push((x, x, u, d));
            }
            ans
        };
        let len = |s: &[(i64, i64, i64, i64)]| -> i64 {
            s.iter().map(|s| (s.0 - s.1).abs() + (s.2 - s.3).abs()).sum::<i64>()
        };
        for &(x, _) in p.iter() {
            let mut res = find(x);
            if i == 1 {
                res.iter_mut().for_each(|p| *p = (p.2, p.3, p.0, p.1));
            }
            if len(&ans) > len(&res) {
                ans = res;
            }
        }
        p.iter_mut().for_each(|p| *p = (p.1, p.0));
    }
    println!("{}", ans.len());
    for (a, b, c, d) in ans {
        println!("{} {} {} {}", a, c, b, d);
    }
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