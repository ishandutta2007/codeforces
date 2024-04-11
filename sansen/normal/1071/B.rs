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
        s: [bytes; n],
    }
    let inf = 3 * n;
    let mut dp = vec![vec![inf; n]; n];
    dp[0][0] = 0;
    if s[0][0] != b'a' {
        dp[0][0] = 1;
    }
    for i in 0..n {
        for j in 0..n {
            let v = dp[i][j];
            for &(x, y) in [(i + 1, j), (i, j + 1)].iter() {
                if x < n && y < n {
                    let mut v = v;
                    if s[x][y] != b'a' {
                        v += 1;
                    }
                    dp[x][y].chmin(v);
                }
            }
        }
    }
    if dp[n - 1][n - 1] <= k {
        println!("{}", "a".repeat(2 * n - 1));
        return;
    }
    let mut max = 0;
    let mut pos = vec![];
    for (i, dp) in dp.iter().enumerate() {
        for (j, v) in dp.iter().enumerate() {
            if *v <= k {
                if max.chmax(i + j) {
                    pos.clear();
                }
                if max == i + j {
                    pos.push((i, j));
                }
            }
        }
    }
    let mut ans = "a".repeat(max + 1);
    if pos.is_empty() {
        ans.clear();
        ans.push(s[0][0] as char);
        pos.push((0, 0));
    }
    while pos[0] != (n - 1, n - 1) {
        let mut next_c = b'z' + 1;
        for &(x, y) in pos.iter() {
            for &(x, y) in [(x + 1, y), (x, y + 1)].iter() {
                if x < n && y < n {
                    next_c.chmin(s[x][y]);
                }
            }
        }
        ans.push(next_c as char);
        let mut next = vec![];
        for &(x, y) in pos.iter() {
            for &(x, y) in [(x + 1, y), (x, y + 1)].iter() {
                if x < n && y < n && s[x][y] == next_c {
                    next.push((x, y));
                }
            }
        }
        next.sort();
        next.dedup();
        pos = next;
    }
    println!("{}", ans);
}

fn main() {
    run();
}