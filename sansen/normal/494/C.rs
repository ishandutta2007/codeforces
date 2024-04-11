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

// 
// 0
// 2q+1
// geta, dp[k]: geta+k 
// 

fn run() {
    input! {
        n: usize,
        q: usize,
        a: [usize; n],
        ask: [(usize1, usize, f64); q],
    }
    let mut ask = ask;
    ask.sort_by_key(|p| (p.0, !p.1));
    let mut prob = vec![0f64; q + 1];
    let mut geta = vec![0; q + 1];
    let mut g = vec![vec![]; q + 1];
    let mut stack = vec![(0, n, 0)];// l, r, index
    let mut index = 1;
    let mut x = 0;
    for i in 0..n {
        while x < q && ask[x].0 == i {
            let (l, r, p) = ask[x];
            g[stack.last().unwrap().2].push(index);
            prob[index] = p;
            stack.push((l, r, index));
            index += 1;
            x += 1;
        }
        geta[stack.last().unwrap().2].chmax(a[i]);
        while stack.last().map_or(false, |p| p.1 == i + 1) {
            stack.pop();
        }
    }
    let mut dp = vec![(0, vec![]); g.len()];
    for (i, g) in g.iter().enumerate().rev() {
        let mut now = (geta[i], vec![1f64]);
        for &u in g.iter() {
            let mut c = std::mem::take(&mut dp[u]);
            if c.0 > now.0 {
                std::mem::swap(&mut c, &mut now);
            }
            let mut next = (now.0, vec![0f64; std::cmp::max(now.1.len(), c.1.len())]);
            for (i, a) in now.1.iter().enumerate() {
                for (j, b) in c.1.iter().enumerate() {
                    let x = std::cmp::max(now.0 + i, c.0 + j) - now.0;
                    next.1[x] += a * b;
                }
            }
            now = next;
        }
        let p = prob[i];
        now.1.push(0f64);
        for i in (1..now.1.len()).rev() {
            now.1[i] = p * now.1[i - 1] + (1f64 - p) * now.1[i];
        }
        now.1[0] *= 1f64 - p;
        dp[i] = now;
    }
    let ans = dp[0].1.iter().enumerate().fold(0f64, |s, a| a.0 as f64 * a.1 + s) + dp[0].0 as f64;
    println!("{:.7}", ans);
}

fn main() {
    run();
}