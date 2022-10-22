fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    let mut deg = vec![0; n];
    for (a, b) in e {
        g[a].push(b);
        deg[b] += 1;
    }
    let deg = deg;
    let mut d = deg.clone();
    let mut topo = vec![];
    for i in 0..n {
        if d[i] == 0 {
            topo.push(i);
        }
    }
    for i in 0..n {
        let v = topo[i];
        for &u in g[v].iter() {
            d[u] -= 1;
            if d[u] == 0 {
                topo.push(u);
            }
        }
    }
    let mut dp = vec![1i32; n];
    for &v in topo.iter().rev() {
        if g[v].len() <= 1 {
            continue;
        }
        let mut val = 0;
        for &u in g[v].iter() {
            if deg[u] > 1 {
                val = val.max(dp[u]);
            }
        }
        dp[v] += val;
    }
    println!("{}", dp.iter().max().unwrap());
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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