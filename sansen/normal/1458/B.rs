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

// S
// i \in S
// min(sum a_i, sum(b_i) + sum(b_j) / 2)
// dp[i][k][sa][sb][sbj]
// sb, sbj 
// dp[i][k][sa] = sb + sbj

fn run() {
    input! {
        n: usize,
        p: [(usize, usize); n],
    }
    let mut p = p;
    for p in p.iter_mut() {
        p.0 *= 2;
        p.1 *= 2;
    }
    let mut dp = std::collections::BTreeMap::new();
    dp.insert((0, 0), 0);
    for &(a, b) in p.iter() {
        let mut update = vec![];
        for (&(cnt, sa), &sb) in dp.iter() {
            update.push(((cnt + 1, sa + a), sb + b));
            update.push(((cnt, sa), sb + b / 2));
        }
        for (k, v) in update {
            dp.entry(k).or_insert(0).chmax(v);
        }
    }
    let mut ans = vec![0; n + 1];
    for ((k, sa), sb) in dp {
        ans[k].chmax(sa.min(sb));
    }
    let mut s = String::new();
    for a in ans[1..].iter() {
        s.push_str(&format!("{:.10} ", *a as f64 * 0.5));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}