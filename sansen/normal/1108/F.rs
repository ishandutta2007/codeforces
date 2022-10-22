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

fn root(mut x: usize, p: &Vec<i32>) -> usize {
    while p[x] >= 0 {
        x = p[x] as usize;
    }
    x
}

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1, u32); m],
    }
    let mut e = e;
    e.sort_by_key(|e| e.2);
    let mut parent = vec![-1; n];
    let mut cost = vec![1_000_000_000 + 1; n];
    let mut ans = 0;
    for (a, b, c) in e {
        if root(a, &parent) != root(b, &parent) {
            let mut a = root(a, &parent);
            let mut b = root(b, &parent);
            if parent[a] > parent[b] {
                std::mem::swap(&mut a, &mut b);
            }
            parent[a] += parent[b];
            parent[b] = a as i32;
            cost[b] = c;
        } else {
            let mut a = a;
            let mut b = b;
            let mut d = 0;
            while a != b {
                if cost[a] < cost[b] {
                    d = cost[a];
                    a = parent[a] as usize;
                } else {
                    d = cost[b];
                    b = parent[b] as usize;
                }
            }
            if d == c {
                ans += 1;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}