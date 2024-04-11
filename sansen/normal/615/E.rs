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
        n: i64,
    }
    if n == 0 {
        println!("0 0");
        return;
    }
    let func = |m: i64| 1 + m * (m + 1) / 2 * 6;
    let mut ng = 1;
    while func(ng) <= n {
        ng *= 2;
    }
    let mut ok = ng / 2;
    while ng - ok > 1 {
        let m = (ok + ng) / 2;
        if func(m) <= n {
            ok = m;
        } else {
            ng = m;
        }
    }
    let mut rem = n - func(ok) + 1;
    let mut pos = (2 * ok, 0);
    let dir = [(1, 2, 1), (-1, 2, ok), (-2, 0, ng), (-1, -2, ng), (1, -2, ng), (2, 0, ng), (1, 2, ng)];
    for &(x, y, d) in dir.iter() {
        let v = d.min(rem);
        rem -= v;
        pos = (pos.0 + v * x, pos.1 + v * y);
    }
    println!("{} {}", pos.0, pos.1);
}

fn main() {
    run();
}