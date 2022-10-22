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
        a: [usize; n],
    }
    let mut b = a.clone();
    b.sort();
    b.dedup();
    if b.len() == n {
        println!("0");
        return;
    }
    let mut a = a;
    for a in a.iter_mut() {
        *a = b.binary_search(a).unwrap();
    }
    let mut cnt = vec![0; b.len()];
    let mut l = 0;
    while l < n && cnt[a[l]] == 0 {
        cnt[a[l]] += 1;
        l += 1;
    }
    let mut r = n - 1;
    while r >= l && cnt[a[r]] == 0 {
        cnt[a[r]] += 1;
        r -= 1;
    }
    let mut ans = r - l + 1;
    while l > 0 {
        l -= 1;
        cnt[a[l]] -= 1;
        while r >= l && cnt[a[r]] == 0 {
            cnt[a[r]] += 1;
            r -= 1;
        }
        ans = std::cmp::min(ans, r - l + 1);
    }
    println!("{}", ans);
}

fn main() {
    run();
}