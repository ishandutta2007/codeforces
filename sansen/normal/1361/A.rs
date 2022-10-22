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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
        t: [usize; n],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut a = t.iter().cloned().enumerate().collect::<Vec<_>>();
    a.sort_by_key(|a| a.1);
    let mut assign = vec![0; n];
    let mut ans = vec![];
    for &(v, a) in a.iter() {
        let mut set = std::collections::BTreeSet::new();
        for &u in g[v].iter() {
            set.insert(assign[u]);
        }
        let mut g = 1;
        while set.contains(&g) {
            g += 1;
        }
        if g != a {
            println!("-1");
            return;
        }
        assign[v] = g;
        ans.push(v);
    }
    let mut out = String::new();
    for a in ans {
        out.push_str(&format!("{} ", a + 1));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}