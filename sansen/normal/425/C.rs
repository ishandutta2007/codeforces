// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------

fn run() {
    input! {
        n: usize,
        m: usize,
        s: usize,
        e: usize,
        a: [usize1; n],
        b: [usize1; m],
    }
    let h = s / e;
    let w = 100_000;
    let mut q = vec![vec![]; w];
    for (i, b) in b.iter().enumerate() {
        q[*b].push(i);
    }
    //dp[i][j]: iajbk
    let mut dp = vec![0; n + 1];
    dp[0] = 0;
    let mut ans = 0;
    for i in 1..=h {
        let mut next = vec![m + 1; n + 1];
        let mut min = m + 1;
        for j in 0..n {
            min = min.min(dp[j]);
            let q = &q[a[j]];
            let x = q.binary_search_by_key(&(min, 0), |p| (*p, 1)).unwrap_err();
            if x < q.len() {
                next[j + 1] = q[x] + 1;
            }
            next[j + 1] = next[j + 1].min(next[j]);
        }
        dp = next;
        for (j, dp) in dp.iter().enumerate() {
            if *dp <= m && j + *dp + i * e <= s {
                ans = i;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}