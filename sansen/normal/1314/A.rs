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
        a: [u64; n],
        t: [u64; n],
    }
    let mut p = vec![];
    for (&a, &t) in a.iter().zip(t.iter()) {
        p.push((a, t));
    }
    p.sort();
    let mut a = a;
    a.sort();
    a.dedup();
    let len = a.len();
    a.push(1_000_000_000 + 300_000);
    let mut x = 0;
    let mut ans = 0;
    let mut sum = 0;
    let mut h = std::collections::BinaryHeap::<(u64, u64)>::new();
    for i in 0..len {
        while x < n && p[x].0 <= a[i] {
            h.push((p[x].1, p[x].0));
            sum += p[x].1;
            x += 1;
        }
        let mut now = a[i];
        while h.len() > 0 && now < a[i + 1] {
            sum -= h.pop().unwrap().0;
            ans += sum;
            now += 1;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}