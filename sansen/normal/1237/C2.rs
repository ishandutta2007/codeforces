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
    input! {
        n: usize,
        p: [(i64, i64, i64); n],
    }
    let mut q = vec![];
    for i in 0..n {
        q.push((p[i].0, p[i].1, p[i].2, i + 1));
    }
    q.sort();
    let mut s = vec![];
    while let Some((x, y, z, k)) = q.pop() {
        let mut p = vec![(y, z, k)];
        while let Some((a, b, c, i)) = q.pop() {
            if a != x {
                q.push((a, b, c, i));
                break;
            }
            p.push((b, c, i));
        }
        let mut u = vec![];
        while p.len() >= 2 {
            let (a, b, i) = p.pop().unwrap();
            let (c, d, j) = p.pop().unwrap();
            if a == c {
                writeln!(out, "{} {}", i, j).ok();
            } else {
                u.push((a, b, i));
                p.push((c, d, j));
            }
        }
        if let Some((a, b, i)) = p.pop() {
            u.push((a, b, i));
        }
        u.sort();
        while u.len() >= 2 {
            let (_, _, i) = u.pop().unwrap();
            let (_, _, j) = u.pop().unwrap();
            writeln!(out, "{} {}", i, j).ok();
        }
        if let Some((a, b, i)) = u.pop() {
            s.push((x, a, b, i));
        }
    }
    s.sort();
    for i in 0..(s.len() / 2) {
        writeln!(out, "{} {}", s[2 * i].3, s[2 * i + 1].3).ok();
    }
}

fn main() {
    run();
}