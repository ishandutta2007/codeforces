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

fn run() {
    input! {
        t: usize,
        ask: [(usize, bytes); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, s) in ask {
        let mut a = vec![];
        let mut i = 0;
        while i < n {
            let c = s[i];
            let mut val = (c, vec![]);
            while i < n && s[i] == c {
                val.1.push(i);
                i += 1;
            }
            a.push(val);
        }
        let mut ans = vec![0; n];
        for k in 1.. {
            if a.is_empty() {
                break;
            }
            for a in a.iter_mut() {
                let x = a.1.pop().unwrap();
                ans[x] = k;
            }
            a = a.into_iter().filter(|p| !p.1.is_empty()).collect();
            a.dedup_by(|a, b| {
                a.0 == b.0 && {
                    if a.1.len() > b.1.len() {
                        std::mem::swap(&mut a.1, &mut b.1);
                    }
                    b.1.append(&mut a.1);
                    true
                }
            });
        }
        let y = *ans.iter().max().unwrap();
        writeln!(out, "{}", y).ok();
        for a in ans {
            write!(out, "{} ", a).ok();
        }
        writeln!(out, "").ok();
    }
}

fn main() {
    run();
}