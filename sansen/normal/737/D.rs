// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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

//

type Map = Vec<Vec<Vec<i32>>>;

fn calc(l: usize, diff: usize, k: usize, dp: &mut Map, s: &[i32]) -> i32 {
    let n = s.len() - 1;
    let r = n - l - diff;
    if r - l < k {
        return 0;
    }
    if dp[k][diff][l] != std::i32::MIN {
        return dp[k][diff][l];
    }
    let mut res = std::i32::MIN;
    for &x in [k, k + 1].iter() {
        if r - l >= x {
            let add = s[l] - s[l + x];
            let l = l + x;
            if r - l < x {
                res.chmax(add);
                continue;
            }
            let mut p = std::i32::MIN;
            for &y in [x, x + 1].iter() {
                if r - l >= y {
                    let v = s[r - y] - s[r] - calc(l, diff + y - x, y, dp, s);
                    p.chmax(v);
                }
            }
            res.chmax(add - p);
        }
    }
    dp[k][diff][l] = res;
    res
}

fn run() {
    input! {
        n: usize,
        a: [i32; n],
    }
    let mut w = 1;
    let mut sum = 0;
    while sum < n {
        sum += w;
        w += 1;
    }
    let mut x = 1;
    let mut sum = 0;
    while sum < n {
        sum += x + x + 1;
        x += 1;
    }
    let mut s = a.clone();
    s.push(0);
    for i in (0..n).rev() {
        s[i] += s[i + 1];
    }
    let mut dp = vec![vec![vec![std::i32::MIN; n / 2 + 5]; x + 1]; w + 1];
    let ans = calc(0, 0, 1, &mut dp, &s);
    println!("{}", ans);
}

fn main() {
    run();
}