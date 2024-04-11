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

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let m = 20_000;
    let mut divisor = vec![vec![]; m + 1];
    for i in 1..=m {
        for j in 1.. {
            if j * j > i {
                break;
            }
            if i % j == 0 {
                divisor[i].push(j);
                divisor[i].push(i / j);
            }
        }
    }
    for d in divisor.iter_mut() {
        d.sort();
        d.dedup();
        d.push(3 * m);
    }
    input! {
        t: usize,
        p: [(usize, usize, usize); t],
    }
    let diff = |a: usize, b: usize| -> usize {
        std::cmp::max(a, b) - std::cmp::min(a, b)
    };
    for (a, b, c) in p {
        let mut ans = (std::usize::MAX, 1, 1, 1);
        for i in 1..=m {
            let mut x = a;
            let y = i;
            let mut z = std::cmp::max(c, i);
            let mut cost = diff(b, i);
            let div = &divisor[i];
            if let Err(k) = div.binary_search(&a) {
                let p = div[k] - a;
                let q = a - div[k - 1];
                if p <= q {
                    cost += p;
                    x = div[k];
                } else {
                    cost += q;
                    x = div[k - 1];
                }
            }
            let p = diff(c, z / i * i);
            let q = diff(c, z / i * i + i);
            if p <= q {
                cost += p;
                z = z / i * i;
            } else {
                cost += q;
                z = z / i * i + i;
            }
            ans = std::cmp::min(ans, (cost, x, y, z));
        }
        writeln!(out, "{}\n{} {} {}", ans.0, ans.1, ans.2, ans.3).ok();
    }
}

fn main() {
    run();
}