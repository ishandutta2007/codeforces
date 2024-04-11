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
        m: i64,
        a: [i64; n],
    }
    if a.iter().fold(0, |s, a| s + *a) < m {
        println!("-1");
        return;
    }
    let mut a = a;
    a.sort();
    a.reverse();
    let mut ok = n;
    let mut ng = 0;
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        let mut sum = 0;
        let mut sub = 0;
        for a in a.chunks(mid) {
            for a in a.iter() {
                sum += std::cmp::max(0, *a - sub);
            }
            sub += 1;
        }
        if sum >= m {
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