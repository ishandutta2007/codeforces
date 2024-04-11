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
    let mut cnt = vec![(0u64, 0u64, 0u64); n + 1];
    cnt[n].1 = 1;
    for i in (0..n).rev() {
        cnt[i] = cnt[i + 1];
        let v = a[i].count_ones() as u64;
        cnt[i].0 += v;
        if cnt[i].0 % 2 == 0 {
            cnt[i].1 += 1;
        } else {
            cnt[i].2 += 1;
        }
    }
    let mut ans = 0u64;
    let m = 64;
    for i in 0..n {
        if i + m + 1 <= n {
            ans += if cnt[i].0 % 2 == 0 {cnt[i + m + 1].1} else {cnt[i + m + 1].2};
        }
        let mut cnt = 0;
        let mut max = 0;
        for j in i..std::cmp::min(n, i + m) {
            let v = a[j].count_ones();
            cnt += v;
            max = std::cmp::max(max, v);
            if 2 * max <= cnt && cnt % 2 == 0 {
                ans += 1;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}