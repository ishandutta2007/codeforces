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
        s: bytes,
        x: u64,
        y: u64,
    }
    let n = s.len();
    let mut sum = vec![[0; 2]; n + 1];
    let mut pos = vec![];
    let mut score = 0;
    for (i, c) in s.iter().enumerate().rev() {
        let mut val = sum[i + 1];
        if *c == b'0' {
            score += val[1] * x;
            val[0] += 1;
        } else if *c == b'1' {
            score += val[0] * y;
            val[1] += 1;
        } else {
            pos.push(i);
        }
        sum[i] = val;
    }
    // 0
    for &p in pos.iter() {
        score += sum[p + 1][1] * x;
        score += (sum[0][1] - sum[p][1]) * y;
    }
    let mut ans = score;
    let save = score;
    for (i, &p) in pos.iter().enumerate() {
        score -= sum[p + 1][1] * x;
        score -= (sum[0][1] - sum[p][1]) * y;
        score += sum[p + 1][0] * y;
        score += (sum[0][0] - sum[p][0]) * x;
        score += (pos.len() - i - 1) as u64 * x;
        score -= i as u64 * x;
        ans.chmin(score);
    }
    score = save;
    for (i, &p) in pos.iter().rev().enumerate() {
        score -= sum[p + 1][1] * x;
        score -= (sum[0][1] - sum[p][1]) * y;
        score += sum[p + 1][0] * y;
        score += (sum[0][0] - sum[p][0]) * x;
        score += (pos.len() - i - 1) as u64 * y;
        score -= i as u64 * y;
        ans.chmin(score);
    }
    println!("{}", ans);
}

fn main() {
    run();
}