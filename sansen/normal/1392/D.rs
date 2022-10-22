// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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

//

use std::io::Write;

fn run() {
    input! {
        t: usize,
        ask: [(usize, chars); t],
    }
    let mut op = vec![];
    op.push(vec!['R', 'L']);
    op.push(vec!['R', 'R', 'L']);
    op.push(vec!['R', 'L', 'L']);
    op.push(vec!['R', 'R', 'L', 'L']);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, mut s) in ask {
        let mut ans = n;
        for _ in 0..4 {
            let cost = |k: usize, op: &[char]| -> usize {
                if s[k..].len() < op.len() {
                    200000
                } else {
                    s[k..]
                        .iter()
                        .zip(op.iter())
                        .filter(|p| *p.0 != *p.1)
                        .count()
                }
            };
            let mut dp = vec![n; n + 4];
            dp[0] = 0;
            for i in 0..n {
                let v = dp[i];
                for op in op.iter() {
                    dp[i + op.len()].chmin(v + cost(i, op));
                }
            }
            ans.chmin(dp[n]);
            s.rotate_left(1);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}