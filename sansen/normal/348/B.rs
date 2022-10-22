// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: u64, b: u64) -> u64 {
    if a == 0 || b == 0 {
        return a + b;
    }
    let x = a.trailing_zeros();
    let y = b.trailing_zeros();
    let mut a = a >> x;
    let mut b = b >> y;
    while a != b {
        let x = (a ^ b).trailing_zeros();
        if a < b {
            std::mem::swap(&mut a, &mut b);
        }
        a = (a - b) >> x;
    }
    a << x.min(y)
}
// ---------- end binary_gcd ----------
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
        a: [u64; n],
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
        for u in g[v].clone() {
            let x = g[u].iter().position(|p| *p == v).unwrap();
            g[u].remove(x);
            topo.push(u);
        }
    }
    let mut dp = vec![(0, 0); n];
    for &v in topo.iter().rev() {
        if g[v].is_empty() {
            dp[v] = (a[v], 1);
            continue;
        }
        let mut min = std::u64::MAX;
        let mut lcm = 1;
        for &u in g[v].iter() {
            let (a, c) = dp[u];
            min = min.min(a);
            let g = binary_gcd(c, lcm);
            lcm = (lcm / g).saturating_mul(c);
        }
        let mut sum = 0;
        for &u in g[v].iter() {
            sum += min / lcm * lcm;
        }
        let c = g[v].len() as u64;
        lcm = lcm.saturating_mul(c);
        dp[v] = (sum, lcm);
    }
    let ans = a.iter().sum::<u64>() - dp[0].0;
    println!("{}", ans);
}

fn main() {
    run();
}