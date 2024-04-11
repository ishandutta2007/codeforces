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
        v: u32,
        a: [u32; n],
    }
    let mut a = a;
    a.push(0);
    for i in (0..n).rev() {
        a[i] ^= a[i + 1];
    }
    a.sort_unstable();
    let mut ans = 0u64;
    let a = a.as_slice();
    let mut dfs = vec![(a, a, 30)];
    while let Some((x, y, k)) = dfs.pop() {
        if x.is_empty() || y.is_empty() {
            continue;
        }
        if k == 0 {
            ans += x.len() as u64 * y.len() as u64;
            continue
        }
        let k = k - 1;
        let m = x.iter().position(|x| *x >> k & 1 == 1).unwrap_or(x.len());
        let (xl, xr) = x.split_at(m);
        let m = y.iter().position(|x| *x >> k & 1 == 1).unwrap_or(y.len());
        let (yl, yr) = y.split_at(m);
        if v >> k & 1 == 1 {
            dfs.push((xl, yr, k));
            dfs.push((xr, yl, k));
        } else {
            ans += xl.len() as u64 * yr.len() as u64;
            ans += xr.len() as u64 * yl.len() as u64;
            dfs.push((xl, yl, k));
            dfs.push((xr, yr, k));
        }
    }
    ans /= 2;
    println!("{}", ans);
}

fn main() {
    run();
}