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
        u: [usize1; n],
    }
    let m = 100000;
    let mut cnt = vec![0; m];
    let mut a = vec![0; n + 2];
    let mut max = 0;
    let mut ans = 1;
    for (k, &u) in u.iter().enumerate() {
        let k = k + 1;
        if cnt[u] > 0 {
            a[cnt[u]] -= 1;
        }
        cnt[u] += 1;
        a[cnt[u]] += 1;
        let f = cnt[u];
        max = std::cmp::max(max, f);
        let mut ok = false;
        if a[1] == k {
            ok = true;
        }
        if a[1] == 1 && a[max] * max == k - 1 {
            ok = true;
        }
        if a[max] == 1 && a[max - 1] * (max - 1) + a[max] * max == k {
            ok = true;
        }
        if ok {
            ans = k;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}