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
        m: usize,
        n: usize,
        k: usize,
        t: usize,
        a: [usize; m],
        p: [(usize, usize, usize); k],
    }
    let mut a = a;
    a.sort();
    a.reverse();
    let mut p = p;
    p.sort();
    let a = a;
    let mut ok = 0;
    let mut ng = m + 1;
    while ng - ok > 1 {
        let mid = (ok + ng) / 2;
        let v = a[mid - 1];
        let mut b = vec![];
        for p in p.iter() {
            if p.2 > v {
                b.push((p.0, p.1));
            }
        }
        let mut time = n + 1;
        let mut i = 0;
        while i < b.len() {
            let left = b[i].0;
            let mut right = b[i].1;
            while i < b.len() && right >= b[i].0 {
                right = std::cmp::max(b[i].1, right);
                i += 1;
            }
            time += 2 * (right - left + 1);
        }
        if time <= t {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    println!("{}", ok);
}

fn main() {
    run();
}