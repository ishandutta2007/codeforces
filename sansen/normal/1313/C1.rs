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
    }
    let mut left = vec![0; n];
    let mut stack: Vec<(u64, u64)> = vec![];
    let mut score = 0;
    for (&a, dp) in a.iter().zip(left.iter_mut()) {
        let mut cnt = 1;
        while let Some(p) = stack.pop() {
            if p.0 >= a {
                score -= p.0 * p.1;
                cnt += p.1;
            } else {
                stack.push(p);
                break;
            }
        }
        stack.push((a, cnt));
        score += a * cnt;
        *dp = score;
    }
    let mut right = vec![0; n];
    let mut stack: Vec<(u64, u64)> = vec![];
    let mut score = 0;
    for (&a, dp) in a.iter().rev().zip(right.iter_mut().rev()) {
        let mut cnt = 1;
        while let Some(p) = stack.pop() {
            if p.0 >= a {
                score -= p.0 * p.1;
                cnt += p.1;
            } else {
                stack.push(p);
                break;
            }
        }
        stack.push((a, cnt));
        score += a * cnt;
        *dp = score;
    }
    let mut ans = (right[0], 0);
    ans = std::cmp::max(ans, (left[n - 1], n));
    for i in 1..n {
        ans = std::cmp::max(ans, (left[i - 1] + right[i], i));
    }
    let mut stack: Vec<(u64, u64)> = vec![];
    for &a in a.iter().take(ans.1) {
        let mut cnt = 1;
        while let Some(p) = stack.pop() {
            if p.0 >= a {
                score -= p.0 * p.1;
                cnt += p.1;
            } else {
                stack.push(p);
                break;
            }
        }
        stack.push((a, cnt));
        score += a * cnt;
    }
    let l = stack;
    let mut stack: Vec<(u64, u64)> = vec![];
    for &a in a.iter().rev().take(n - ans.1) {
        let mut cnt = 1;
        while let Some(p) = stack.pop() {
            if p.0 >= a {
                score -= p.0 * p.1;
                cnt += p.1;
            } else {
                stack.push(p);
                break;
            }
        }
        stack.push((a, cnt));
        score += a * cnt;
    }
    let mut out = String::new();
    for l in l {
        for _ in 0..l.1 {
            out.push_str(&format!("{} ", l.0));
        }
    }
    for r in stack.into_iter().rev() {
        for _ in 0..r.1 {
            out.push_str(&format!("{} ", r.0));
        }
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}