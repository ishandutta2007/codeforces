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
        h: i64,
        w: i64,
        k: usize,
        p: [(i64, i64); k],
    }
    let p = p.into_iter().map(|p| (p.0 - 1, p.1 - 1)).collect::<Vec<_>>();
    let valid = |t: i64| -> bool {
        let mut x = vec![0, h];
        let mut y = vec![0, w];
        for &(a, b) in p.iter() {
            for (x, a, h) in vec![(&mut x, a, h), (&mut y, b, w)].into_iter() {
                x.push((a - t).max(0));
                x.push((a + t + 1).min(h));
            }
        }
        x.sort();
        x.dedup();
        y.sort();
        y.dedup();
        let mut imos = vec![vec![0; y.len()]; x.len()];
        for &(a, b) in p.iter() {
            let u = x.binary_search(&(a - t).max(0)).unwrap();
            let d = x.binary_search(&(a + t + 1).min(h)).unwrap();
            let l = y.binary_search(&(b - t).max(0)).unwrap();
            let r = y.binary_search(&(b + t + 1).min(w)).unwrap();
            imos[u][l] += 1;
            imos[d][l] -= 1;
            imos[u][r] -= 1;
            imos[d][r] += 1;
        }
        for imos in imos.iter_mut() {
            for i in 1..imos.len() {
                imos[i] += imos[i - 1];
            }
        }
        for i in 1..imos.len() {
            for j in 0..y.len() {
                imos[i][j] += imos[i - 1][j];
            }
        }
        let mut u = h;
        let mut d = 0;
        let mut l = w;
        let mut r = 0;
        for (i, imos) in imos.iter().enumerate().take(x.len() - 1) {
            for (j, imos) in imos.iter().enumerate().take(y.len() - 1) {
                if *imos == 0 {
                    u = u.min(x[i]);
                    d = d.max(x[i + 1]);
                    l = l.min(y[j]);
                    r = r.max(y[j + 1]);
                }
            }
        }
        d - u <= 2 * t + 1 && r - l <= 2 * t + 1
    };
    if valid(0) {
        println!("0");
        return;
    }
    let mut ng = 0;
    let mut ok = h.max(w);
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        if valid(mid) {
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