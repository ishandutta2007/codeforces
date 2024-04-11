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
        a: [u32; n],
    }
    let mut a = a;
    a.sort();
    let mut cnt = 0;
    for i in 1..n {
        if a[i] == a[i - 1] {
            cnt += 1;
        }
    }
    if cnt >= 2 {
        println!("cslnb");
        return;
    }
    for i in 2..n {
        if a[i] == a[i - 1] && a[i -2] == a[i] - 1 {
            println!("cslnb");
            return;
        }
    }
    if n >= 2 && a[1] == 0 {
        println!("cslnb");
        return;
    }
    let mut sum = 0;
    let mut x = 0;
    let mut i = 0;
    while i < n {
        sum ^= a[i] - x;
        x += 1;
        i += 1;
        while i < n && a[i] < x {
            i += 1;
        }
    }
    let ans = if sum & 1 == 1 {"sjfnb"} else {"cslnb"};
    println!("{}", ans);
}

fn main() {
    run();
}