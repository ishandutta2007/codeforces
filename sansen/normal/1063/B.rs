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
        h: usize,
        w: usize,
        src: (usize1, usize1),
        left: i32,
        right: i32,
        s: [bytes; h],
    }
    let mut dp = vec![vec![(-1, -1); w]; h];
    let mut used = vec![vec![false; w]; h];
    dp[src.0][src.1] = (left, right);
    let mut q = std::collections::VecDeque::new();
    q.push_back(src);
    while let Some((x, y)) = q.pop_front() {
        if used[x][y] {
            continue;
        }
        used[x][y] = true;
        let (l, r) = dp[x][y];
        for &x in [x - 1, x + 1].iter() {
            if x < h && s[x][y] != b'*' && dp[x][y].chmax((l, r)) {
                q.push_front((x, y));
            }
        }
        if l > 0 && y > 0 && s[x][y - 1] != b'*' && dp[x][y - 1].chmax((l - 1, r)) {
            q.push_back((x, y - 1));
        }
        if r > 0 && y + 1 < w && s[x][y + 1] != b'*' && dp[x][y + 1].chmax((l, r - 1)) {
            q.push_back((x, y + 1));
        }
    }
    let ans = used.iter().flatten().filter(|p| **p).count();
    println!("{}", ans);
}

fn main() {
    run();
}