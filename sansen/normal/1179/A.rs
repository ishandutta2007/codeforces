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
        q: usize,
        a: [u32; n],
        ask: [u64; q],
    }
    let mut deq: std::collections::VecDeque<_> = a.iter().cloned().collect();
    let mut ans = vec![(0, 0); n];
    for i in 0..n {
        let mut a = deq.pop_front().unwrap();
        let mut  b = deq.pop_front().unwrap();
        ans[i] = (a, b);
        if a <= b {
            std::mem::swap(&mut a, &mut b);
        }
        deq.push_front(a);
        deq.push_back(b);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for m in ask {
        let (a, b) = if m <= n as u64 {
            ans[m as usize - 1]
        } else {
            let a = *deq.get(0).unwrap();
            let d = (n - 1) as u64;
            let x = (m - n as u64 - 1) % d as u64 + 1;
            let b = *deq.get(x as usize).unwrap();
            (a, b)
        };
        writeln!(out, "{} {}", a, b).ok();
    }
}

fn main() {
    run();
}