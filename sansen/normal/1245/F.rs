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

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        p: [(usize, usize); t],
    }
    for (l, r) in p {
        let mut dp = vec![vec![vec![0u64; 2]; 2]; 2];
        dp[0][0][0] = 1;
        for b in (0..30).rev() {
            let mut next = vec![vec![vec![0; 2]; 2]; 2];
            let l = (l >> b) & 1;
            let r = (r >> b) & 1;
            for i in 0..2 {
                for j in 0..2 {
                    for k in 0..2 {
//                        print!("{} ", dp[i][j][k]);
                        //0, 0
                        if i == 1 || l == 0 {
                            next[i][j | r][k] += dp[i][j][k];
                        }
                        //0, 1
                        if (i == 1 || l == 0) && (j == 1 || r == 1) {
                            next[i][j][1] += dp[i][j][k];
                        }
                        //1, 0
                        if k == 1 {
                            next[i | (l ^ 1)][j | r][k] += dp[i][j][k];
                        }
                    }
                }
            }
//            println!();
            dp = next;
        }
        let mut ans = 0;
        for i in 0..2 {
            for j in 0..2 {
                for k in 0..2 {
                    if k == 0 {
                        ans += dp[i][j][k];
                    } else {
                        ans += 2 * dp[i][j][k];
                    }
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}