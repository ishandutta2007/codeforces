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
        _m: usize,
        _k: usize,
        p: [(usize1, usize); n],
    }
    let mut z = vec![];
    for p in p.iter() {
        z.push(p.0);
        z.push(p.1);
    }
    z.sort();
    z.dedup();
    let mut g = vec![vec![]; z.len() - 1];
    let mut p = p;
    for p in p.iter_mut() {
        p.0 = z.binary_search(&p.0).unwrap();
        p.1 = z.binary_search(&p.1).unwrap();
        g[p.0].push(p.1);
    }
    let mut dp = std::collections::BTreeMap::<Vec<usize>, usize>::new();
    dp.insert(vec![], 0);
    for (i, g) in g.iter_mut().enumerate() {
        g.sort();
        g.dedup();
        let mut next = std::collections::BTreeMap::<Vec<usize>, usize>::new();
        for (k, v) in dp.iter() {
            for j in 0..(1 << g.len()) {
                let mut key = k.clone();
                for (x, v) in g.iter().enumerate() {
                    if (j >> x) & 1 == 1 {
                        key.push(*v);
                    }
                }
                key.sort();
                key.reverse();
                let po = next.entry(key).or_insert(0);
                *po = std::cmp::max(*po, *v);
            }
        }
        dp.clear();
        for (k, v) in next.into_iter() {
            let mut val = v;
            if k.len() % 2 == 1 {
                val += z[i + 1] - z[i];
            }
            let mut key = k.clone();
            while let Some(p) = key.last() {
                if *p == i + 1 {
                    key.pop();
                } else {
                    break;
                }
            }
            let po = dp.entry(key).or_insert(0);
            *po = std::cmp::max(*po, val);
        }
    }
    let mut ans = 0;
    for (_, v) in dp.into_iter() {
        ans = std::cmp::max(ans, v);
    }
    println!("{}", ans);
}

fn main() {
    run();
}