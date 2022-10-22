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
        x: u64,
        d: [u64; n],
    }
    let mut ans = 0;
    let mut q = std::collections::VecDeque::new();
    let mut len = 0;
    let mut sum = 0;
    for d in d.iter().rev().cycle().take(2 * n) {
        assert!(len < x);
        q.push_front(d);
        len += d;
        sum += d * (d + 1) / 2;
        while len >= x {
            let rem = x - (len - d);
            let f = (d + 1) * rem - rem * (rem + 1) / 2;
            let s = sum - d * (d + 1) / 2;
            ans = std::cmp::max(ans, f + s);
            let v = q.pop_back().unwrap();
            len -= v;
            sum -= v * (v + 1) / 2;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}