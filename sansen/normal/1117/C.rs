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
        s: (i64, i64),
        t: (i64, i64),
        n: i64,
        a: chars,
    }
    let mut map = std::collections::BTreeMap::new();
    map.insert('U', (0, 1));
    map.insert('D', (0, -1));
    map.insert('L', (-1, 0));
    map.insert('R', (1, 0));
    let map = map;
    let p = (t.0 - s.0, t.1 - s.1);
    let inf = 1_000_000_000i64 * 100_000 + 1;
    let mut ng = -1;
    let mut ok = inf;
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        let q = mid / n;
        let r = (mid % n) as usize;
        let mut center = (0, 0);
        for (i, c) in a.iter().enumerate() {
            let (x, y) = *map.get(c).unwrap();
            center.0 += q * x;
            center.1 += q * y;
            if i < r {
                center.0 += x;
                center.1 += y;
            }
        }
        let d = (p.0 - center.0).abs() + (p.1 - center.1).abs();
        if d <= mid {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    if ok == inf {
        println!("{}", -1);
    } else {
        println!("{}", ok);
    }
}

fn main() {
    run();
}