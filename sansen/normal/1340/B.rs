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
        s: [chars; n],
    }
    let mut a = vec![];
    for s in s {
        let mut b = 0;
        for (i, c) in s.into_iter().enumerate() {
            b |= (c.to_digit(10).unwrap() as usize) << (6 - i);
        }
        a.push(b);
    }
//    let op: [usize; 10] = [0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011];
    let op: [usize; 10] = [0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011];
    let mut dp = vec![vec![false; k + 1]; n + 1];
    dp[n][0] = true;
    for i in (0..n).rev() {
        for j in 0..=k {
            if !dp[i + 1][j] {
                continue;
            }
            for k in 0..10 {
                if op[k] & a[i] != a[i] {
                    continue;
                }
                let s = (op[k] ^ a[i]).count_ones() as usize;
                if let Some(v) = dp[i].get_mut(j + s) {
                    *v = true;
                }
            }
        }
    }
    if !dp[0][k] {
        println!("-1");
        return;
    }
    let mut ans = String::new();
    let mut now = k;
    for i in 0..n {
        assert!(dp[i][now]);
        for j in (0..10).rev() {
            if op[j] & a[i] != a[i] {
                continue;
            }
            let s = (op[j] ^ a[i]).count_ones() as usize;
            if now >= s && dp[i + 1][now - s] {
                ans.push_str(&j.to_string());
                now -= s;
                break;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}