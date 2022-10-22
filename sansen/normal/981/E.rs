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
        q: usize,
        p: [(usize1, usize, usize); q],
    }
    let mut add = vec![vec![]; n + 1];
    let mut sub = vec![vec![]; n + 1];
    for (l, r, x) in p {
        add[l].push(x);
        sub[r].push(x);
    }
    const MOD: u64 = 4611686018427194327;
    let mut cond = vec![false; n + 1];
    let mut dp = vec![0; n + 1];
    dp[0] = 1;
    for i in 0..n {
        for &x in &sub[i] {
            for j in x..=n {
                dp[j] += MOD - dp[j - x];
                if dp[j] >= MOD {
                    dp[j] -= MOD;
                }
            }
        }
        for &x in &add[i] {
            for j in (x..=n).rev() {
                dp[j] += dp[j - x];
                if dp[j] >= MOD {
                    dp[j] -= MOD;
                }
                if dp[j] != 0 {
                    cond[j] = true;
                }
            }
        }
    }
    let mut ans = vec![];
    for i in 1..=n {
        if cond[i] {
            ans.push(i);
        }
    }
    let mut out = String::new();
    out.push_str(&format!("{}\n", ans.len()));
    for a in ans {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}