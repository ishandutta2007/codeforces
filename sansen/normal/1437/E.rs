// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------

fn run() {
    input! {
        n: usize,
        k: usize,
        a: [usize; n],
        b: [usize; k],
    }
    let mut a = a.into_iter().enumerate().map(|(i, a)| a + n - i).collect::<Vec<_>>();
    let mut b = b;
    a.insert(0, 0);
    a.push(1000000000 + n);
    b.insert(0, 0);
    b.push(a.len() - 1);
    if b.windows(2).any(|b| a[b[0]] > a[b[1]]) {
        println!("-1");
        return;
    }
    let mut ans = 0;
    for b in b.windows(2) {
        let s = a[b[0]];
        let last = a[b[1]];
        let a = &a[(b[0] + 1)..b[1]];
        let mut dp = vec![s];
        for &a in a.iter() {
            if !(s <= a && a <= last) {
                continue;
            }
            if *dp.last().unwrap() <= a {
                dp.push(a);
                continue;
            }
            let x = dp.binary_search_by_key(&(a, 1), |dp| (*dp, 0)).unwrap_err();
            dp[x] = a;
        }
        ans += a.len() - (dp.len() - 1);
    }
    println!("{}", ans);
}

fn main() {
    run();
}