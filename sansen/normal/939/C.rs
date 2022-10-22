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
        a: [i64; n],
        s: usize1,
        f: usize1,
    }
    let mut imos = vec![0; 2 * n];
    for (i, a) in a.iter().enumerate() {
        imos[n - i + s] += *a;
        imos[n - i + f] -= *a;
    }
    for i in 1..(2 * n) {
        imos[i] += imos[i - 1];
    }
    let mut ans = (-(imos[0] + imos[n]), 0);
    for i in 1..n {
        let v = imos[i] + imos[i + n];
        ans = std::cmp::min(ans, (-v, i));
    }
    println!("{}", ans.1 + 1);
}

fn main() {
    run();
}