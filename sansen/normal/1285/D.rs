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

fn calc(a: &[usize], k: usize) -> usize {
    let b = ((a[0] ^ *a.last().unwrap()) >> k) & 1;
    if k == 0 {
        return b;
    }
    if b == 0 {
        return calc(a, k - 1);
    }
    let m = a.iter().position(|p| (*p >> k) & 1 == 1).unwrap();
    (1 << k) + std::cmp::min(calc(&a[..m], k - 1), calc(&a[m..], k - 1))
}

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let mut a = a;
    a.sort();
    let ans = calc(&a, 29);
    println!("{}", ans);
}

fn main() {
    run();
}