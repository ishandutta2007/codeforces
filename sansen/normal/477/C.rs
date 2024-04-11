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

// dp[x, y, z]:
// xyc
// 2000*500*2000, 
// 
// next[x]: s[x..r] pr
// dp[x, y]: xy, 
// 2000 * (2000 / |P|), 

fn run() {
    input! {
        s: bytes,
        p: bytes,
    }
    let mut next = vec![None; s.len()];
    for i in 0..s.len() {
        let mut x = 0;
        let mut j = i;
        while x < p.len() && j < s.len() {
            if p[x] == s[j] {
                x += 1;
            }
            j += 1;
        }
        if x == p.len() {
            next[i] = Some(j);
        }
    }
    let w = s.len() / p.len();
    let inf = s.len() + 1;
    let mut dp = vec![vec![inf; w + 1]; s.len() + 1];
    dp[0][0] = 0;
    for (i, &next) in next.iter().enumerate() {
        for j in 0..=w {
            let v = dp[i][j];
            if v == inf {
                continue;
            }
            dp[i + 1][j].chmin(v);
            if let Some(r) = next {
                dp[r][j + 1].chmin(v + r - i - p.len());
            }
        }
    }
    let mut ans = vec![0; s.len() + 1];
    for (i, &v) in dp[s.len()].iter().enumerate() {
        if v < inf {
            let need = v;
            let up = s.len() - i * p.len();
            for k in need..=up {
                ans[k].chmax(i);
            }
        }
    }
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}