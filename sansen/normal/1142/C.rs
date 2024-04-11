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

fn run() {
    input! {
        n: usize,
        p: [(i64, i64); n],
    }
    let mut p = p;
    for p in &mut p {
        *p = (p.0, p.1 - p.0 * p.0);
    }
    p.sort();
    let mut stack = vec![];
    let mut i = 0;
    while i < n {
        let mut q = p[i];
        i += 1;
        while i < n && p[i].0 == q.0 {
            q = p[i];
            i += 1;
        }
        let (a, b) = q;
        while stack.len() >= 2 {
            let n = stack.len();
            let (c, d) = stack[n - 1];
            let (e, f) = stack[n - 2];
            if (a - c) * (b - f) <= (a - e) * (b - d) {
                stack.pop();
            } else {
                break;
            }
        }
        stack.push((a, b));
    }
    println!("{}", stack.len() - 1);
}

fn main() {
    run();
}