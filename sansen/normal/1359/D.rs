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

fn calc(a: &[i32]) -> i32 {
    if a.len() <= 1 {
        return 0;
    }
    let x = *a.iter().max().unwrap();
    if x < 0 {
        return 0;
    }
    let mut ans = 0;
    let mut min = 0;
    let mut s = 0;
    for &a in a.iter() {
        s += a;
        ans = std::cmp::max(ans, s - min - x);
        min = std::cmp::min(s, min);
    }
    let mut p = 0;
    for (i, &y) in a.iter().enumerate() {
        if x == y {
            ans = std::cmp::max(ans, calc(&a[p..i]));
            p = i + 1;
        }
    }
    std::cmp::max(ans, calc(&a[p..]))
}

fn run() {
    input! {
        n: usize,
        a: [i32; n],
    }
    let ans = calc(&a);
    println!("{}", ans);
}

fn main() {
    run();
}