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

fn calc(a: &[u32], v: u32) -> usize {
    let n = a.len();
    let mut cnt = 0;
    let mut r = n;
    for (i, &x) in a.iter().enumerate() {
        while r > 0 && x + a[r - 1] >= v {
            r -= 1;
        }
        if r > i {
            cnt += n - r;
        } else {
            cnt += n - (i + 1);
        }
    }
    cnt
}

fn run() {
    input! {
        n: usize,
        a: [u32; n],
    }
    let mut a = a;
    let mut ans = 0;
    for i in (0..25).rev() {
        a.sort();
        let cnt = calc(&a, 1 << i) ^ calc(&a, 2 << i) ^ calc(&a, 3 << i);
        if cnt & 1 == 1 {
            ans |= 1 << i;
        }
        for a in a.iter_mut() {
            *a &= !(1 << i);
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}