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

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        x: [i64; n],
        ask: [(usize1, i64); m],
    }
    let mut z = vec![];
    for (i, x) in x.iter().enumerate() {
        z.push((*x, i + 1));
    }
    z.sort();
    for (mut k, mut l) in ask {
        k = z.binary_search(&(x[k], k + 1)).unwrap();
        let mut sign = 1;
        let mut cnt = 0;
        let mut deq = std::collections::VecDeque::new();
        let mut fst = true;
        loop {
            let p = if sign == 1 {
                z.binary_search(&(z[k].0 + sign * l, n + 1)).unwrap_err() - 1
            } else {
                z.binary_search(&(z[k].0 + sign * l, 0)).unwrap_err()
            };
            if p == k {
                cnt += 1;
            } else {
                cnt = 0;
            }
            if cnt == 2 {
                break;
            }
            l -= (z[p].0 - z[k].0).abs();
            if !fst {
                deq.push_back(k);
            }
            fst = false;
            k = p;
            sign *= -1;
            if deq.len() > 3 {
                if deq.pop_front().unwrap() == k {
                    let u = *deq.front().unwrap();
                    l %= (z[u].0 - z[k].0).abs() * 2;
                    deq.clear();
                }
            }
        }
        writeln!(out, "{}", z[k].1).ok();
    }
}

fn main() {
    run();
}