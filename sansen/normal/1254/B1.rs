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

fn factor(n: i64) -> Vec<i64> {
    let mut ans = vec![1, n];
    for d in 2.. {
        if d * d >= n {
            if d * d == n {
                ans.push(d);
            }
            break;
        }
        if n % d == 0 {
            ans.push(d);
            ans.push(n / d);
        }
    }
    ans
}

fn run() {
    input! {
        n: usize,
        a: [i64; n],
    }
    let sum = a.iter().fold(0, |s, a| s + *a);
    if sum == 1 {
        println!("-1");
        return;
    }
    let mut ans = std::i64::MAX;
    let d = factor(sum);
    for &d in d.iter() {
        if d == 1 {
            continue;
        }
        let mut stack = vec![];
        let mut local = 0;
        for i in 0..n {
            if a[i] == 1 {
                stack.push(i as i64);
            }
            if stack.len() == d as usize {
                let mid = stack[(d / 2) as usize];
                for a in stack.iter() {
                    local += (*a - mid).abs();
                }
                stack.clear();
            }
        }
        assert!(stack.is_empty());
        ans = std::cmp::min(ans, local);
    }
    println!("{}", ans);
}

fn main() {
    run();
}