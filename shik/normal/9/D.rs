// {{{ by shik

use std::io;

#[allow(dead_code)]
fn gets() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

macro_rules! R {
    ( $ty:ty, ... ) => {
        gets().split_whitespace().map(|x| x.parse::<$ty>().unwrap()).collect::<Vec<_>>()
    };
    ( $($ty:ty),* ) => {{
        let line = gets();
        let mut it = line.split_whitespace();
        ( $(it.next().unwrap().parse::<$ty>().unwrap(),)* )
    }}
}

macro_rules! W {
    ( $x:expr ) => {{
        println!("{}", $x);
    }};
    ( $x:expr, $($xs:expr),* ) => {{
        print!("{} ", $x);
        W!($($xs),*);
    }}
}

macro_rules! debug {
    ( $x:expr ) => {{
        println!("{} = {:?}", stringify!($x), $x);
    }};
    ( $x:expr, $($xs:expr),* ) => {{
        print!("{} = {:?}, ", stringify!($x), $x);
        debug!($($xs),*);
    }}
}

// }}}

fn main() {
    let (n, h) = R!(usize, usize);
    let mut dp = vec![vec![0i64; n + 1]; n + 1];
    dp[0][0] = 1;
    for i in 1..n + 1 {
        for j in 1..i + 1 {
            let mut s = 0i64;
            for k in 1..i + 1 {
                let l = k - 1;
                let r = i - k;
                for jl in 0..j {
                    for jr in 0..j {
                        if jl == j - 1 || jr == j - 1 {
                            s += dp[l][jl] * dp[r][jr];
                        }
                    }
                }
            }
            dp[i][j] = s;
        }
    }
    let ans = (h..n + 1).fold(0i64, |s, i| s + dp[n][i]);
    W!(ans);
}