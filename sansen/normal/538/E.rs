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
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut topo = vec![0];
    for i in 0..n {
        let v = topo[i];
        let c = std::mem::take(&mut g[v]);
        for &u in c.iter() {
            let k = g[u].iter().position(|p| *p == v).unwrap();
            g[u].remove(k);
            topo.push(u);
        }
        g[v] = c;
    }
    let mut dp_max = vec![(0, 0); n];
    let mut dp_min = vec![(0, 0); n];
    let mut size = vec![0; n];
    for &v in topo.iter().rev() {
        let c = &g[v];
        if c.is_empty() {
            dp_max[v] = (1, 1);
            dp_min[v] = (1, 1);
            size[v] = 1;
            continue;
        }
        for &u in g[v].iter() {
            size[v] += size[u];
        }
        let mut max = (n, 0);
        let mut sum_max = 0;
        let mut min = (n, 0);
        let mut sum_min = 0;
        for &u in g[v].iter() {
            let rem = size[v] - size[u];
            max.1.chmax(dp_max[u].0 + rem);
            min.0.chmin(dp_min[u].1);
            sum_max += size[u] - dp_max[u].1 + 1;
            sum_min += dp_min[u].0 - 1 + 1;
        }
        max.0 = size[v] - sum_max + 1;
        min.1 = sum_min;
        dp_max[v] = max;
        dp_min[v] = min;
    }
    let max = dp_max[0].1;
    let min = dp_min[0].1;
    println!("{} {}", max, min);
}

fn main() {
    run();
}