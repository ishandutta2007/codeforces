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
        h: usize,
        w: usize,
        t: usize,
        s: [chars; h],
        ask: [(usize1, usize1, u64); t],
    }
    let s: Vec<Vec<u8>> = s
        .into_iter()
        .map(|s| {
            s.into_iter()
                .map(|c| c.to_digit(10).unwrap() as u8)
                .collect()
        })
        .collect();
    let inf = 1_000_000_000_000_000_000 + 1;
    let mut dp = vec![vec![inf; w]; h];
    let mut q = std::collections::VecDeque::new();
    for i in 1..h {
        for j in 0..w {
            if s[i][j] == s[i - 1][j] {
                dp[i - 1][j] = 0;
                dp[i][j] = 0;
                q.push_back((i - 1, j));
                q.push_back((i, j));
            }
        }
    }
    for i in 0..h {
        for j in 1..w {
            if s[i][j] == s[i][j - 1] {
                dp[i][j - 1] = 0;
                dp[i][j] = 0;
                q.push_back((i, j - 1));
                q.push_back((i, j));
            }
        }
    }
    while let Some((a, b)) = q.pop_front() {
        for &(x, y) in [(a - 1, b), (a + 1, b), (a, b - 1), (a, b + 1)].iter() {
            if x < h && y < w && dp[x][y] > dp[a][b] + 1 {
                dp[x][y] = dp[a][b] + 1;
                q.push_back((x, y));
            }
        }
    }
    for (a, b, p) in ask {
        let ans = if p <= dp[a][b] {
            s[a][b] as u64
        } else {
            s[a][b] as u64 ^ ((p - dp[a][b]) & 1)
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}