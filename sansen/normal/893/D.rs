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
        d: i64,
        a: [i64; n],
    }
    let mut sum = a.clone();
    sum.insert(0, 0);
    for i in 1..=n {
        sum[i] += sum[i - 1];
    }
    for i in (1..=n).rev() {
        sum[i - 1] = std::cmp::max(sum[i], sum[i - 1]);
    }
    let mut now = 0;
    let mut used = 0;
    let mut cnt = 0;
    for (&a, &s) in a.iter().zip(sum.iter()) {
        if a == 0 {
            if now < 0 {
                let v = d - s - used;
                now += v;
                used += v;
                cnt += 1;
                if now < 0 {
                    println!("-1");
                    return;
                }
            }
        } else {
            now += a;
            if now > d {
                println!("-1");
                return;
            }
        }
    }
    println!("{}", cnt);
}

fn main() {
    run();
}