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
        t: usize,
        ask: [(usize, usize, usize, bytes); t],
    }
    for (n, a, b, s) in ask {
        let pos = |x: usize, y: usize, z: usize, w: usize| -> usize {
            ((x * (n + 1) + y) * a + z) * b + w
        };
        let mut dp = vec![None; pos(n + 2, 0, 0, 0)];
        dp[pos(0, 0, 0, 0)] = Some((0, b'.'));
        // dp[][a][mod a][mod b] = parent
        for (x, s) in s.iter().enumerate() {
            let d = (*s - b'0') as usize;
            for y in 0..=x {
                for z in 0..a {
                    for w in 0..b {
                        if dp[pos(x, y, z, w)].is_none() {
                            continue;
                        }
                        dp[pos(x + 1, y + 1, (10 * z + d) % a, w)] = Some((pos(x, y, z, w), b'R'));
                        dp[pos(x + 1, y, z, (10 * w + d) % b)] = Some((pos(x, y, z, w), b'B'));
                    }
                }
            }
        }
        let mut ans = (n, 0);
        for i in 1..n {
            let d = i.max(n - i) - i.min(n - i);
            if dp[pos(n, i, 0, 0)].is_some() && ans.0 > d {
                ans = (d, pos(n, i, 0, 0));
            }
        }
        if ans.0 == n {
            println!("-1");
            continue;
        }
        let mut p = ans.1;
        let mut ans = vec![];
        while p > 0 {
            ans.push(dp[p].unwrap().1);
            p = dp[p].unwrap().0;
        }
        ans.reverse();
        for a in ans {
            print!("{}", a as char);
        }
        println!();
    }
}

fn main() {
    run();
}