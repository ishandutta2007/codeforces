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

const INF: u32 = 1000000;

fn run() {
    input! {
        n: usize,
        a: [u64; n],
    }
    let a = a.into_iter().filter(|a| *a > 0).collect::<Vec<_>>();
    let n = a.len();
    let w = 60;
    let mut cnt = vec![0; w];
    for a in a.iter() {
        for (j, cnt) in cnt.iter_mut().enumerate() {
            *cnt += *a >> j & 1;
        }
    }
    if cnt.iter().any(|c| *c >= 3) {
        println!("3");
        return;
    }
    let mut g = vec![vec![]; n];
    let mut id = 0;
    let mut e = vec![];
    for (i, x) in a.iter().enumerate() {
        for (j, y) in a.iter().enumerate().take(i) {
            if *x & *y != 0 {
                g[i].push((j, id));
                g[j].push((i, id));
                e.push((i, j, id));
                id += 1;
            }
        }
    }
    let mut ans = INF;
    for &(a, b, k) in e.iter() {
        let mut dp = vec![INF; n];
        dp[a] = 0;
        let mut q = std::collections::VecDeque::new();
        q.push_back(a);
        while let Some(v) = q.pop_front() {
            let d = dp[v] + 1;
            for &(u, i) in g[v].iter() {
                if i != k && dp[u].chmin(d) {
                    q.push_back(u);
                }
            }
        }
        ans.chmin(dp[b] + 1);
    }
    if ans == INF {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}

fn main() {
    run();
}