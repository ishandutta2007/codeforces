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
        a: [u32; n],
        m: usize,
        b: [u32; m],
    }
    let mut ans = (n as i32 * 2 - m as i32 * 2, n as i32 * 2);
    let mut e = vec![];
    e.extend(a.into_iter().map(|a| (a, 0)));
    e.extend(b.into_iter().map(|a| (a, 1)));
    e.sort();
    let mut rem = [n as i32, m as i32];
    while let Some((d, op)) = e.pop() {
        rem[op] -= 1;
        while e.last().map_or(false, |p| p.0 == d) {
            rem[e.pop().unwrap().1] -= 1;
        }
        let p = rem[0] * 2 + (n as i32 - rem[0]) * 3;
        let q = rem[1] * 2 + (m as i32 - rem[1]) * 3;
        ans = (p - q, p).max(ans);
    }
    println!("{}:{}", ans.1, ans.1 - ans.0);
}

fn main() {
    run();
}