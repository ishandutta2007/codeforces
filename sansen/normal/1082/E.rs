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
        c: usize,
        a: [usize; n],
    }
    let mut cnt_c = vec![0i32; n + 1];
    let m = 500_000;
    let mut g = vec![vec![]; m + 1];
    for i in (0..n).rev() {
        cnt_c[i] = cnt_c[i + 1];
        if a[i] == c {
            cnt_c[i] += 1;
        } else {
            g[a[i]].push(i);
        }
    }
    let mut ans = cnt_c[0];
    for v in 1..=m {
        let mut local = 0;
        for (i, &l) in g[v].iter().enumerate() {
            let i = i as i32;
            ans = std::cmp::max(ans, cnt_c[0] - cnt_c[l] + i + 1 + local);
            local = std::cmp::max(local, cnt_c[l + 1] - i);
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}