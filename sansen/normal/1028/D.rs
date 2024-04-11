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
        p: [(chars, i32); n],
    }
    const MOD: u64 = 1_000_000_007;
    let mut way = 1;
    let mut small = std::collections::BinaryHeap::<i32>::new();
    let mut large = std::collections::BinaryHeap::<i32>::new();
    let mut tmp = vec![];
    for (s, v) in p {
        if s[1] == 'D' {
            if !small.is_empty() && *small.peek().unwrap() > v {
                small.push(v);
            } else if !large.is_empty() && *large.peek().unwrap() > -v {
                large.push(-v);
            } else {
                tmp.push(v);
            }
        } else if tmp.contains(&v) {
            way = 2 * way % MOD;
            for &u in tmp.iter() {
                if u < v {
                    small.push(u);
                }
                if u > v {
                    large.push(-u);
                }
            }
            tmp.clear();
        } else if !small.is_empty() && *small.peek().unwrap() == v {
            small.pop();
            for &v in tmp.iter() {
                large.push(-v);
            }
            tmp.clear();
        } else if !large.is_empty() && *large.peek().unwrap() == -v {
            large.pop();
            for &v in tmp.iter() {
                small.push(v);
            }
            tmp.clear();
        } else {
            println!("0");
            return;
        }
    }
    way = way * (tmp.len() + 1) as u64 % MOD;
    println!("{}", way);
}

fn main() {
    run();
}