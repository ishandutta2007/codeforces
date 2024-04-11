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

// dp[...001.. 0][...1000 0][] = protection 
// dp[a][b][c] 

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let mut v = vec![vec![]; 2];
    for (i, a) in a.iter().enumerate() {
        v[*a].push(i);
    }
    let mut cost = vec![];
    {
        let mut memo = vec![vec![0; v[1].len() + 1]; v[0].len()];
        for (i, &x) in v[0].iter().enumerate() {
            for one in 0..=v[1].len() {
                let mut cnt = 0;
                let mut val = 0;
                for &v in v[1].iter() {
                    if cnt < one {
                        cnt += 1;
                    } else if v < x {
                        val += 1;
                    } else {
                        break;
                    }
                }
                memo[i][one] = val;
            }
        }
        cost.push(memo);
    }
    {
        let mut memo = vec![vec![0; v[0].len() + 1]; v[1].len()];
        for (i, &x) in v[1].iter().enumerate() {
            for one in 0..=v[0].len() {
                let mut cnt = 0;
                let mut val = 0;
                for &v in v[0].iter() {
                    if cnt < one {
                        cnt += 1;
                    } else if v < x {
                        val += 1;
                    } else {
                        break;
                    }
                }
                memo[i][one] = val;
            }
        }
        cost.push(memo);
    }
    type Map = std::collections::BTreeMap<usize, usize>;
    let k = v[0].len();
    let mut dp = vec![vec![Map::new(); k + 1]; k + 1];
    dp[0][0].insert(0, 0);
    for i in 0..n {
        let mut next = vec![vec![Map::new(); k + 1]; k + 1];
        for (a, dp) in dp.into_iter().enumerate() {
            for (b, dp) in dp.into_iter().enumerate() {
                for (c, val) in dp {
                    let one = i - a - b;
                    if v[0].len() > a + b {
                        let cost = cost[0][a + b][one];
                        next[a][b + 1].entry(c + cost).or_insert(0).chmax(val + a);
                    }
                    if v[1].len() > one {
                        let cost = cost[1][one][a + b];
                        next[a + b][0].entry(c + cost).or_insert(0).chmax(val);
                    }
                }
            }
        }
        dp = next;
    }
    let mut ans = vec![0; n * (n - 1) / 2 + 1];
    for (c, v) in dp.into_iter().flatten().flatten() {
        ans[c].chmax(v);
    }
    for i in 1..ans.len() {
        ans[i] = std::cmp::max(ans[i], ans[i - 1]);
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