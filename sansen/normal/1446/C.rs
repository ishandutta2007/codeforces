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

fn solve(a: &[u32]) -> usize {
    if a.is_empty() {
        return 0;
    }
    let w = 30;
    let mut cnt = vec![0; w + 1];
    let mut v = vec![vec![]; w + 1];
    for a in a.iter() {
        if *a == 0 {
            cnt[0] += 1;
        } else {
            let k = ((*a + 1).next_power_of_two() / 2).trailing_zeros() as usize;
            cnt[k + 1] += 1;
            v[k + 1].push(*a ^ (1 << k));
        }
    }
    let mut ans = cnt.iter().filter(|c| **c > 0).count();
    let mut r = ans;
    let mut l = 0;
    for (i, v) in v.iter().enumerate() {
        if cnt[i] > 0 {
            r -= 1;
        }
        let v = solve(v);
        ans = ans.max(v + r + (l > 0) as usize);
        if cnt[i] > 0 {
            l += 1;
        }
    }
    ans
}

fn run() {
    input! {
        n: usize,
        a: [u32; n],
    }
    let mut a = a;
    a.sort();
    let ans = solve(&a);
    println!("{}", n - ans);
}

fn main() {
    run();
}