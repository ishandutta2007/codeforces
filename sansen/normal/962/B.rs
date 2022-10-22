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

fn run_length_encoding<T: Clone + Eq>(a: &[T]) -> Vec<(T, usize)> {
    if a.len() == 0 {
        return vec![];
    }
    let mut x = a[0].clone();
    let mut cnt = 1;
    let mut ans = vec![];
    for y in &a[1..] {
        if x == *y {
            cnt += 1;
        } else {
            ans.push((x, cnt));
            x = y.clone();
            cnt = 1;
        }
    }
    ans.push((x, cnt));
    ans
}

fn run() {
    input! {
        _n: usize,
        a: i64,
        b: i64,
        s: chars,
    }
    let s = run_length_encoding(&s);
    let mut p = a;
    let mut q = b;
    for (c, k) in s {
        if c == '*' {
            continue;
        }
        let x = (k / 2) as i64;
        let y = k as i64 - x;
        if p >= q {
            p -= y;
            q -= x;
        } else {
            p -= x;
            q -= y;
        }
    }
    let ans = a - std::cmp::max(0, p) + b - std::cmp::max(0, q);
    println!("{}", ans);
}

fn main() {
    run();
}