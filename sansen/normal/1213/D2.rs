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
        k: usize,
        a: [usize; n],
    }
    let m = 200_000;
    let mut cnt = vec![0; m + 1];
    for &a in a.iter() {
        cnt[a] += 1;
    }
    let mut ans = 20 * n;
    let mut s = vec![vec![]; m + 1];
    let mut sum = vec![0; m + 1];
    for i in (0..=m).rev() {
        for _ in 0..cnt[i] {
            s[i].push(0);
        }
        s[i].sort();
        while s[i].len() > k {
            if let Some(v) = s[i].pop() {
                sum[i] -= v;
            }
        }
        if s[i].len() >= k {
            ans = std::cmp::min(ans, sum[i]);
        }
        if i > 0 {
            while let Some(v) = s[i].pop() {
                s[i / 2].push(v + 1);
                sum[i / 2] += v + 1;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}