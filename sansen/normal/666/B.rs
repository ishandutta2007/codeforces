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

use std::collections::*;

const SIZE: usize = 3;

#[derive(Clone, Copy)]
struct Top3<T> {
    val: [T; SIZE],
}

impl<T: Ord + Copy> Top3<T> {
    fn new(ini: T) -> Self {
        Top3 {
            val: [ini; SIZE],
        }
    }
    fn update(&mut self, val: T) {
        for i in 0..SIZE {
            if val > self.val[i] {
                self.val[i..].rotate_right(1);
                self.val[i] = val;
                break;
            }
        }
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for &(a, b) in e.iter() {
        g[a].push(b);
    }
    let inf = n;
    let mut memo = vec![];
    for i in 0..n {
        let mut dp = vec![inf; n];
        dp[i] = 0;
        let mut q = VecDeque::new();
        q.push_back(i);
        while let Some(v) = q.pop_front() {
            let d = dp[v] + 1;
            for &u in g[v].iter() {
                if dp[u] > d {
                    dp[u] = d;
                    q.push_back(u);
                }
            }
        }
        memo.push(dp);
    }
    let mut inv = vec![Top3::new((0, n)); n];
    let mut to = vec![Top3::new((0, n)); n];
    for (i, dp) in memo.iter().enumerate() {
        for (j, &v) in dp.iter().enumerate() {
            if v < n {
                inv[j].update((v, i));
                to[i].update((v, j));
            }
        }
    }
    let mut ans = (0, 0, 0, 0, 0);
    for b in 0..n {
        for c in 0..n {
            if b == c || memo[b][c] == inf {
                continue;
            }
            let w = memo[b][c];
            for &(x, a) in inv[b].val.iter() {
                if a == b || a == c || a == n {
                    continue;
                }
                for &(y, d) in to[c].val.iter() {
                    if d == b || d == c || d == a || d == n {
                        continue;
                    }
                    ans = std::cmp::max(ans, (x + w + y, a, b, c, d));
                }
            }
        }
    }
    println!("{} {} {} {}", ans.1 + 1, ans.2 + 1, ans.3 + 1, ans.4 + 1);
}

fn main() {
    run();
}