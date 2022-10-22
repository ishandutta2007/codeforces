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
        k: usize,
        p: [(usize, usize, i32); n],
        e: [(usize1, usize1); m],
    }
    let mut g: Vec<usize> = (0..n).collect();
    for (u, v) in e {
        g[v] = std::cmp::max(g[v], u);
    }
    let mut portal = vec![vec![]; n];
    for i in 0..n {
        portal[g[i]].push(i);
    }
    let mut dp = vec![0; k + 1];
    for (i, &(a, b, _)) in p.iter().enumerate() {
        let mut next = vec![std::i32::MIN; dp.len() + b];
        let mut q = vec![];
        for &k in portal[i].iter() {
            q.push(p[k].2);
        }
        q.sort();
        for i in 0..dp.len() {
            if i < a {
                continue;
            }
            let v = dp[i];
            next[i + b] = std::cmp::max(next[i + b], v);
            let mut sum = 0;
            let mut j = 0;
            for &c in q.iter().rev() {
                sum += c;
                j += 1;
                if i + b >= j {
                    next[i + b - j] = std::cmp::max(next[i + b - j], v + sum);
                }
            }
        }
        dp = next;
    }
    let ans = dp.into_iter().max().unwrap();
    if ans < 0 {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}

fn main() {
    run();
}