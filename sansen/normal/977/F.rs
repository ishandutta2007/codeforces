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
        a: [i32; n],
    }
    let mut z = a.clone();
    z.push(-1);
    z.sort();
    z.dedup();
    let mut dp = vec![0; z.len()];
    for a in a.iter() {
        let k = z.binary_search(a).unwrap();
        if z[k - 1] + 1 == z[k] {
            dp[k] = dp[k - 1] + 1;
        } else {
            dp[k] = 1;
        }
    }
    let (last, &len) = dp.iter().enumerate().max_by_key(|p| p.1).unwrap();
    let mut ans = String::new();
    ans.push_str(&len.to_string());
    ans.push('\n');
    let mut p = z[last] - len + 1;
    for i in 0..n {
        if a[i] == p {
            ans.push_str(&format!("{} ", i + 1));
            p += 1;
        }
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}