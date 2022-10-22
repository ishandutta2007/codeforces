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

// ...
// 
// kk
// ceil(n / k) 
// k2
// push
// push
// 
// 1
// push

fn run() {
    input! {
        t: usize,
        ask: [(usize, usize, chars); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, k, s) in ask {
        let mut cnt = std::collections::BTreeMap::new();
        for c in s {
            *cnt.entry(c).or_insert(0) += 1;
        }
        let mut a: Vec<_> = cnt.into_iter().collect();
        let mut ans = String::new();
        if a.len() == 1 {
            let (c, v) = a[0];
            for _ in 0..((v + k - 1) / k) {
                ans.push(c);
            }
        } else if a[0].1 < k {
            let mut s = 0;
            for (c, v) in a {
                if s + v >= k {
                    ans.push(c);
                    break;
                }
                s += v;
            }
        } else {
            ans.push(a[0].0);
            a[0].1 -= k;
            if a[0].1 > 0 {
                for (c, v) in a {
                    for _ in 0..v {
                        ans.push(c);
                    }
                }
            } else {
                a.remove(0);
                if a.len() == 1 {
                    let (c, v) = a[0];
                    for _ in 0..((v + k - 1) / k) {
                        ans.push(c);
                    }
                } else {
                    for (c, v) in a {
                        for _ in 0..v {
                            ans.push(c);
                        }
                    }
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}