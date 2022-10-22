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

use std::io::Write;
use std::ops::Bound::*;

fn run() {
    input! {
        n: usize,
        m: usize,
        h: [u32; n],
        ask: [(usize1, u32); m],
    }
    let mut query = vec![vec![]; n];
    for (i, &(a, b)) in ask.iter().enumerate() {
        query[a].push((b, i));
    }
    let mut val = vec![1; m];
    let mut dp = vec![0];
    let mut set = vec![std::collections::BTreeSet::new()];
    for (i, &h) in h.iter().enumerate() {
        for &(h, k) in query[i].iter() {
            let mut ok = 0;
            let mut ng = dp.len();
            while ng - ok > 1 {
                let mid = (ok + ng) / 2;
                if dp[mid] < h {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            val[k] += ok;
        }
        let mut ok = 0;
        let mut ng = dp.len();
        while ng - ok > 1 {
            let mid = (ok + ng) / 2;
            if dp[mid] < h {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if ng >= dp.len() {
            dp.push(0);
            set.push(std::collections::BTreeSet::new());
        }
        dp[ng] = h;
        set[ng].insert((i, h));
    }
    let mut sup = vec![dp.len() - 1; n];
    let mut back = set.pop().unwrap();
    if back.len() == 1 {
        sup[back.iter().next().unwrap().0] -= 1;
    }
    while set.len() > 1 {
        let mut p = std::collections::BTreeSet::new();
        let mut q = set.pop().unwrap();
        for &(x, h) in back.iter() {
            let mut del = vec![];
            for &(y, b) in q.range((Unbounded, Included(&(x, h)))).rev() {
                if b >= h {
                    break;
                }
                del.push((y, b));
            }
            for p in del.iter() {
                q.remove(p);
            }
            for v in del {
                p.insert(v);
            }
        }
        back = p;
        assert!(!back.is_empty());
        if back.len() == 1 {
            sup[back.iter().next().unwrap().0] -= 1;
        }
    }
    let mut dp = vec![10u32.pow(9) + 1];
    for (i, &h) in h.iter().enumerate().rev() {
        for &(h, k) in query[i].iter() {
            let mut ok = 0;
            let mut ng = dp.len();
            while ng - ok > 1 {
                let mid = (ok + ng) / 2;
                if dp[mid] > h {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            val[k] += ok;
        }
        let mut ok = 0;
        let mut ng = dp.len();
        while ng - ok > 1 {
            let mid = (ok + ng) / 2;
            if dp[mid] > h {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if ng >= dp.len() {
            dp.push(0);
        }
        dp[ng] = h;
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (&(a, _), &val) in ask.iter().zip(val.iter()) {
        let ans = std::cmp::max(sup[a], val);
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}