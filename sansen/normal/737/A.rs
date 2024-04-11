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

//

fn run() {
    input! {
        n: usize,
        k: usize,
        s: i64,
        t: i64,
        p: [(u32, i64); n],
        g: [i64; k],
    }
    let mut g = g;
    g.push(0);
    g.push(s);
    g.sort();
    let mut d = g.windows(2).map(|g| g[1] - g[0]).collect::<Vec<_>>();
    d.sort();
    let mut ng = 0;
    let mut ok = std::i64::MAX / 100;
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        let mut sum = 0;
        let mut valid = true;
        for &d in d.iter() {
            if d > mid {
                valid = false;
                break;
            }
            sum += d;
            if 2 * d > mid {
                let x = 2 * d - mid;
                sum += x;
            }
        }
//        println!("{}: {}", mid, sum);
        if valid && sum <= t {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    let mut ans = std::u32::MAX;
    for (c, v) in p {
        if v >= ok {
            ans = std::cmp::min(c, ans);
        }
    }
    if ans < std::u32::MAX {
        println!("{}", ans);
    } else {
        println!("-1");
    }
}

fn main() {
    run();
}