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

use std::cmp::*;

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let topological = |root: usize| -> Vec<(usize, usize)> {
        let mut ans = vec![(root, root)];
        for i in 0..n {
            let (v, p) = ans[i];
            for &u in g[v].iter() {
                if u != p {
                    ans.push((u, v));
                }
            }
        }
        ans
    };
    let topo = topological(0);
    let mut size = vec![1; n];
    for &(v, p) in topo.iter().rev() {
        for &u in g[v].iter() {
            if u != p {
                size[v] += size[u];
            }
        }
    }
    let mut c = 0;
    loop {
        let mut max = (0, 0);
        for &u in g[c].iter() {
            if size[u] < size[c] {
                max.chmax((size[u], u));
            }
        }
        if 2 * max.0 <= n {
            break;
        }
        c = max.1;
    }
    let c = c;
    let topo = topological(c);
    let mut size = vec![1; n];
    let mut dp = vec![0; n];
    for &(v, p) in topo.iter().rev() {
        let mut val = 0;
        for &u in g[v].iter() {
            if u != p {
                val.chmax(dp[u]);
                if 2 * size[u] <= n {
                    val.chmax(size[u]);
                }
                size[v] += size[u];
            }
        }
        dp[v] = val;
    }
    let mut down = vec![0; n];
    for &(v, p) in topo.iter() {
        let mut stack = vec![down[v]];
        for &u in g[v].iter().rev() {
            if u != p {
                let mut val = *stack.last().unwrap();
                val.chmax(dp[u]);
                if 2 * size[u] <= n {
                    val.chmax(size[u]);
                }
                stack.push(val);
            }
        }
        let mut val = 0;
        for &u in g[v].iter() {
            if u != p {
                stack.pop();
                down[u] = max(*stack.last().unwrap(), val);
                if 2 * (n - size[u]) <= n {
                    down[u].chmax(n - size[u]);
                }
                val.chmax(dp[u]);
                if 2 * size[u] <= n {
                    val.chmax(size[u]);
                }
            }
        }
    }
    let mut ans = String::new();
    for i in 0..n {
        let x = if i == c {
            1
        } else if 2 * (n - size[i] - down[i]) <= n {
            1
        } else {
            0
        };
        ans.push_str(&format!("{} ", x));
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}