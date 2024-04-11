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
    input! {
        n: usize,
        d: [usize; n],
    }
    let mut x = Vec::with_capacity(n);
    for (i, &d) in d.iter().enumerate() {
        x.push((d, i + 1));
    }
    x.sort();
    x.reverse();
    let mut path = vec![];
    for &(_, v) in x.iter() {
        path.push(2 * v - 1);
    }
    let mut ans = vec![];
    for i in 1..n {
        ans.push((path[i - 1], path[i]));
    }
    for i in 0..n {
        let (d, v) = x[i];
        if i + d == path.len() {
            let &u = path.last().unwrap();
            ans.push((2 * v, u));
            path.push(2 * v);
        } else {
            let u = path[i + d - 1];
            ans.push((2 * v, u));
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (a, b) in ans {
        writeln!(out, "{} {}", a, b).unwrap();
    }
}

fn main() {
    run();
}