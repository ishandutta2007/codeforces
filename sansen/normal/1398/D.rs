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

fn run() {
    input! {
        n: usize,
        m: usize,
        l: usize,
        a: [u64; n],
        b: [u64; m],
        c: [u64; l],
    }
    let mut a = a;
    a.sort();
    let mut b = b;
    b.sort();
    let mut c = c;
    c.sort();
    let mut dp = vec![vec![vec![0; l + 2]; m + 2]; n + 2];
    for i in (0..=n).rev() {
        for j in (0..=m).rev() {
            for k in (0..=l).rev() {
                let mut val = 0;
                val.chmax(dp[i + 1][j][k]);
                val.chmax(dp[i][j + 1][k]);
                val.chmax(dp[i][j][k + 1]);
                if i < n && j < m {
                    val.chmax(a[i] * b[j] + dp[i + 1][j + 1][k]);
                }
                if j < m && k < l {
                    val.chmax(b[j] * c[k] + dp[i][j + 1][k + 1]);
                }
                if k < l && i < n {
                    val.chmax(c[k] * a[i] + dp[i + 1][j][k + 1]);
                }
                dp[i][j][k] = val;
            }
        }
    }
    let ans = dp[0][0][0];
    println!("{}", ans);
}

fn main() {
    run();
}