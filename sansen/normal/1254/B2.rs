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

fn factor(mut n: i64) -> Vec<i64> {
    let mut ans = vec![];
    for d in 2.. {
        if d * d > n {
            break;
        }
        if n % d == 0 {
            ans.push(d);
            while n % d == 0 {
                n /= d;
            }
        }
    }
    if n > 1 {
        ans.push(n);
    }
    ans
}

fn run() {
    input! {
        n: usize,
        a: [i64; n],
    }
    let m = a.iter().fold(0, |s, a| s + *a);
    if m == 1 {
        println!("-1");
        return;
    }
    let p = factor(m);
    let mut ans = std::i64::MAX;
    for &p in p.iter() {
        let mut stack = vec![];
        let mut sum = 0;
        let mut local = 0i64;
        for i in 0..n {
            assert!(sum < p);
            let v = a[i] % p;
            if v > 0 {
                sum += v;
                stack.push((i as i64, v));
            }
            if sum >= p {
                assert!(stack.len() > 1);
                stack.last_mut().unwrap().1 -= sum - p;
                let l = stack[0].0;
                let r = stack.last().unwrap().0;
                let mut right = p;
                let mut left = 0;
                let mut d = 0;
                for &(k, v) in stack.iter() {
                    d += (k - l) * v;
                }
                let mut val = d;
                let mut po = 0;
                for i in l..=r {
                    val = std::cmp::min(val, d);
                    if stack[po].0 == i {
                        left += stack[po].1;
                        right -= stack[po].1;
                        po += 1;
                    }
                    d -= right;
                    d += left;
                }
                local += val;
                stack.clear();
                sum %= p;
                if sum > 0 {
                    stack.push((i as i64, sum));
                }
            }
        }
        ans = std::cmp::min(ans, local);
    }
    println!("{}", ans);
}

fn main() {
    run();
}