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
        h: usize,
        w: usize,
        s: [bytes; h],
    }
    let mut a = vec![];
    for s in s {
        let mut b = vec![];
        for s in s {
            if s == b'W' {
                b.push(1);
            } else {
                b.push(-1);
            }
        }
        a.push(b);
    }
    let mut ans = 0;
    let mut dp = vec![vec![0i64; w]; h];
    while dp != a {
        ans += 1;
        let (x, y) = || -> (usize, usize) {
            for i in (0..h).rev() {
                for j in (0..w).rev() {
                    if dp[i][j] != a[i][j] {
                        return (i, j);
                    }
                }
            }
            unreachable!();
        }();
        let d = a[x][y] - dp[x][y];
        for dp in dp.iter_mut().take(x + 1) {
            for dp in dp.iter_mut().take(y + 1) {
                *dp += d;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}