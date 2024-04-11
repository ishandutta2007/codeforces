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
        n: usize,
        p: usize,
        a: [(usize, u32, usize1); n],
        q: usize,
        ask: [(usize1, usize); q],
    }
    let m = 20000;
    let mut item = vec![vec![]; m];
    for (c, h, t) in a {
        item[t].push((c, h));
    }
    let mut query = vec![vec![]; m];
    for (i, &(a, b)) in ask.iter().enumerate() {
        query[a].push((b, i));
    }
    let mut res = vec![0; q];
    let w = 4000;
    let mut front: Vec<Vec<u32>> = vec![];
    let mut back: Vec<Vec<u32>> = vec![];
    let push = |stack: &mut Vec<Vec<u32>>, c: usize, h: u32| {
        let mut dp = stack.last().map_or_else(|| vec![0; w + 1], |p| p.clone());
        for i in (c..=w).rev() {
            let v = dp[i - c] + h;
            dp[i].chmax(v);
        }
        stack.push(dp);
    };
    for i in 0..m {
        if i >= p {
            for _ in item[i - p].iter() {
                if front.is_empty() {
                    back.clear();
                    for &(c, h) in item[(i - p + 1)..i].iter().flatten().rev() {
                        push(&mut front, c, h);
                    }
                    break;
                } else {
                    front.pop();
                }
            }
        }
        for &(c, h) in item[i].iter() {
            push(&mut back, c, h);
        }
        for &(b, k) in query[i].iter() {
            let mut ans = 0;
            for i in 0..=b {
                let x = front.last().map_or(0, |p| p[i]);
                let y = back.last().map_or(0, |p| p[b - i]);
                ans.chmax(x + y);
            }
            res[k] = ans;
        }
    }
    for a in res {
        println!("{}", a);
    }
}

fn main() {
    run();
}