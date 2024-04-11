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
        s: [i32; n],
        m: usize,
        p: [(bytes, usize); m],
    }
    let mut s = s;
    s.sort();
    s.reverse();
    s.truncate(m);
    let n = m;
    let inf = 1_000_000_000;
    let mut dp = vec![0; 1 << n];
    for i in (0usize..((1 << n) - 1)).rev() {
        let x = i.count_ones() as usize;
        let (op, team) = (p[x].0[0], p[x].1);
        let mut val = inf;
        if team == 1 {
            val = -inf;
        }
        for j in 0..n {
            if i >> j & 1 == 1 {
                continue;
            }
            let y = i | (1 << j);
            match (team, op) {
                (1, b'p') => val = val.max(dp[y] + s[j]),
                (1, b'b') => val = val.max(dp[y]),
                (2, b'p') => val = val.min(dp[y] - s[j]),
                (2, b'b') => val = val.min(dp[y]),
                _ => unreachable!(),
            }
        }
        dp[i] = val;
    }
    println!("{}", dp[0]);
}

fn main() {
    run();
}