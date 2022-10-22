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

use std::io::Write;

fn run() {
    input! {
        t: usize,
        ask: [(u64, u64); t],
    }
    let mut dp = vec![1, 1u64];
    let inf = 10u64.pow(18) + 1;
    while *dp.last().unwrap() < inf {
        let val = dp.iter().sum::<u64>();
        dp.push(val);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, k) in ask {
        if n < dp.len() as u64 && dp[n as usize] < k {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut rem = k - 1;
        let mut s = 1;
        let mut ans = vec![];
        while s <= n {
            if n - s + 1 >= dp.len() as u64 {
                ans.push(s);
                s += 1;
                continue;
            }
            let mut v = vec![s];
            let mut x = (n - s) as usize;
            s += 1;
            while x < dp.len() && dp[x] <= rem {
                v.push(s);
                s += 1;
                rem -= dp[x];
                x -= 1;
            }
            v.reverse();
            ans.append(&mut v);
        }
        for (i, a) in ans.iter().enumerate() {
            if i > 0 {
                write!(out, " ").ok();
            }
            write!(out, "{}", *a).ok();
        }
        writeln!(out).ok();
    }
}

fn main() {
    run();
}