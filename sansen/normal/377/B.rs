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

use std::io::Write;

// 
// 
// 
// 
// 
// k
// 

fn run() {
    input! {
        n: usize,
        m: usize,
        s: i64,
        a: [i64; m],
        b: [i64; n],
        c: [i64; n],
    }
    let mut p = vec![];
    for (i, (b, c)) in b.iter().zip(&c).enumerate() {
        p.push((*b, c, i));
    }
    p.sort();
    let mut q = a.iter().cloned().enumerate().collect::<Vec<_>>();
    q.sort_by_key(|p| p.1);
    let calc = |w: usize| -> Option<Vec<usize>> {
        let mut ans = vec![n; m];
        let mut p = p.clone();
        let mut h = std::collections::BinaryHeap::new();
        let mut sum = 0;
        for q in q.rchunks(w) {
            let v = q[q.len() - 1].1;
            while p.last().map_or(false, |p| p.0 >= v) {
                let (_, c, k) = p.pop().unwrap();
                h.push((-c, k));
            }
            if let Some((c, k)) = h.pop() {
                sum += -c;
                for q in q.iter() {
                    ans[q.0] = k;
                }
            } else {
                return None;
            }
        }
        if sum <= s {
            Some(ans)
        } else {
            None
        }
    };
    let mut ng = 0;
    let mut ok = m + 1;
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        if calc(mid).is_some() {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    if ok > m {
        println!("NO");
        return;
    }
    println!("YES");
    let a = calc(ok).unwrap();
    let mut s = String::new();
    for a in a {
        s.push_str(&format!("{} ", a + 1));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}