// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
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

use std::collections::*;

type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        h: usize,
        w: usize,
        s: [bytes; h],
    }
    let inf = 2 * h * w + 1;
    let bfs = |src: u8| -> Vec<Vec<usize>> {
        let mut dp = vec![vec![inf; w]; h];
        let mut q = Deque::new();
        for (i, s) in s.iter().enumerate() {
            for (j, s) in s.iter().enumerate() {
                if *s == src {
                    dp[i][j].chmin(0);
                    q.push_back((i, j));
                }
            }
        }
        while let Some((x, y)) = q.pop_front() {
            let d = dp[x][y];
            for &(x, y) in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)].iter() {
                if x < h && y < w {
                    if s[x][y] == b'#' {
                    } else if s[x][y] == b'.' {
                        if dp[x][y].chmin(d + 1) {
                            q.push_back((x, y));
                        }
                    } else {
                        if dp[x][y].chmin(d) {
                            q.push_front((x, y));
                        }
                    }
                }
            }
        }
        dp
    };
    let a = bfs(b'1');
    let b = bfs(b'2');
    let c = bfs(b'3');
    let mut ans = inf;
    for p in [(&a, b'2', b'3'), (&b, b'3', b'1'), (&c, b'1', b'2')].iter() {
        let mut a = inf;
        let mut b = inf;
        for i in 0..h {
            for j in 0..w {
                if s[i][j] == p.1 {
                    a.chmin(p.0[i][j]);
                }
                if s[i][j] == p.2 {
                    b.chmin(p.0[i][j]);
                }
            }
        }
        ans.chmin(a + b);
    }
    for i in 0..h {
        for j in 0..w {
            if s[i][j] == b'.' {
                ans.chmin(a[i][j] + b[i][j] + c[i][j] - 2);
            }
        }
    }
    if ans < h * w {
        println!("{}", ans);
    } else {
        println!("-1");
    }
}

fn main() {
    run();
}