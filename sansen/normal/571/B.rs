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
        k: usize,
        a: [i64; n],
    }
    let mut a = a;
    a.sort();
    let z = n / k;
    let x = n % k;//  n / k + 1
    let y = k - x;//  n / k 
    let inf = a[n - 1] - a[0] + 1;
    let mut dp = vec![-inf; y + 1];
    dp[0] = 0;
    for i in 0..=x {
        let mut next = vec![-inf; y + 1];
        for j in 0..=y {
            let v = dp[j];
            if i + 1 <= x {
                let c = v + if (i + 1, j) == (x, y) {
                    0
                } else {
                    let k = (i + 1) * (z + 1) + j * z;
                    a[k] - a[k - 1]
                };
                next[j].chmax(c);
            }
            if j + 1 <= y {
                let c = v + if (i, j + 1) == (x, y) {
                    0
                } else {
                    let k = i * (z + 1) + (j + 1) * z;
                    a[k] - a[k - 1]
                };
                dp[j + 1].chmax(c);
            }
        }
        if i < x {
            dp = next;
        }
    }
    let ans = a[n - 1] - a[0] - dp[y];
    println!("{}", ans);
}

fn main() {
    run();
}