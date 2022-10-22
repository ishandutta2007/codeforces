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

// 3^n
// N=25
//
// 
// 3^13 = 1_594_323

fn run() {
    input! {
        n: usize,
        p: [(i64, i64, i64); n],
    }
    let m = n / 2;
    let (l, r) = p.split_at(m);
    let enumerate = |p: &[(i64, i64, i64)]| -> Vec<(i64, i64, i64, usize)> {
        let mut dp = vec![(0, 0, 0, 0)];
        for &(l, m, w) in p.iter().rev() {
            let mut next = vec![];
            for &(a, b, c, k) in dp.iter() {
                next.push((a + l, b + m, c, 3 * k + 0));
                next.push((a + l, b, c + w, 3 * k + 1));
                next.push((a, b + m, c + w, 3 * k + 2));
            }
            dp = next;
        }
        dp
    };
    let left = enumerate(l);
    let right = enumerate(r);
    let mut dp = vec![];
    for (a, b, c, k) in left {
        dp.push((a - b, b - c, c - a, a + b + c, k));
    }
    dp.sort();
    dp.dedup_by(|a, b| {
        a.0 == b.0 && a.1 == b.1 && a.2 == b.2 && {
            if b.3 < a.3 {
                b.3 = a.3;
                b.4 = a.4;
            }
            true
        }
    });
    let mut ans = (std::i64::MIN, 0, 0);
    for (x, y, z, w) in right {
        if let Ok(k) = dp.binary_search_by_key(&(y - x, z - y, x - z), |p| (p.0, p.1, p.2)) {
            let (_, _, _, d, e) = dp[k];
            ans = std::cmp::max(ans, (d + x + y + z, e, w));
        }
    }
    if ans.0 == std::i64::MIN {
        println!("Impossible");
    } else {
        for &(mut v, k) in [(ans.1, l.len()), (ans.2, r.len())].iter() {
            for _ in 0..k {
                let r = v % 3;
                let s = match r {
                    0 => "LM",
                    1 => "LW",
                    _ => "MW",
                };
                println!("{}", s);
                v /= 3;
            }
        }
    }
}

fn main() {
    run();
}