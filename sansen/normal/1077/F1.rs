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
        x: usize,
        a: [i64; n],
    }
    let mut dp = vec![std::i64::MIN; n + 1];
    dp[n] = 0;
    for _ in 0..x {
        let mut next = dp.clone();
        let mut q = std::collections::VecDeque::new();
        q.push_back((0, n));
        for i in (0..n).rev() {
            if q.front().unwrap().1 > i + k {
                q.pop_front();
            }
            next[i] = q.front().unwrap().0 + a[i];
            let v = dp[i];
            while let Some(p) = q.back() {
                if p.0 <= v {
                    q.pop_back();
                } else {
                    break;
                }
            }
            q.push_back((v, i));
        }
        dp = next;
    }
    let ans = *dp[..k].iter().max().unwrap();
    if ans < 0 {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}

fn main() {
    run();
}