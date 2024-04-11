// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
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

fn solve(a: Vec<u64>) -> u64 {
    let mut ans = 0;
    for r in 1..=a.len() {
        let mut max = 0;
        let mut min = std::u64::MAX;
        for l in (0..r).rev() {
            max.chmax(a[l]);
            min.chmin(a[l]);
            if max.count_ones() == min.count_ones() {
                ans += 1;
            }
        }
    }
    ans
}

fn run() {
    input! {
        n: usize,
        a: [u64; n],
    }
    // dp[i] = (x, y)
    // x: max
    // y: min
    let gen = |a: &[u64], dp: &mut Vec<(u64, u64)>, dp_pos: &mut Vec<Vec<(u64, usize)>>| {
        dp.clear();
        dp_pos.iter_mut().for_each(|p| p.clear());
        let mut max = 0;
        let mut min = std::u64::MAX;
        for (i, &a) in a.iter().enumerate() {
            max.chmax(a);
            min.chmin(a);
            dp.push((max, min));
            dp_pos[min.count_ones() as usize].push((min, i));
        }
    };
    const W: usize = 60;
    let mut a = a;
    let mut left_dp = vec![];
    let mut left_pos = vec![vec![]; W];
    let mut right_dp = vec![];
    let mut right_pos = vec![vec![]; W];
    let mut dfs = vec![a.as_mut_slice()];
    let mut ans = 0;
    while let Some(a) = dfs.pop() {
        if a.len() == 1 {
            ans += 1;
            continue;
        }
        let m = a.len() / 2;
        let (l, r) = a.split_at_mut(m);
        l.reverse();
        gen(l, &mut left_dp, &mut left_pos);
        gen(r, &mut right_dp, &mut right_pos);
        let mut lp = l.len();
        let mut rp = r.len();
        let mut left_range = left_pos.iter().map(|p| (p.len(), p.len())).collect::<Vec<_>>();
        let mut right_range = right_pos.iter().map(|p| (p.len(), p.len())).collect::<Vec<_>>();
        let mut left_min = l.len();
        let mut right_min = r.len();
        while lp > 0 && rp > 0 {
            if left_dp[lp - 1].0 >= right_dp[rp - 1].0 {
                lp -= 1;
                let (max, min) = left_dp[lp];
                let cnt = max.count_ones() as usize;
                let pos = &mut right_pos[cnt];
                let range = &mut right_range[cnt];
                let out = rp;
                let dp = &right_dp;
                let po = &mut right_min;
                while pos.get(range.0 - 1).map_or(false, |p| p.0 <= min || p.1 >= out) {
                    range.0 -= 1;
                }
                while pos.get(range.1 - 1).map_or(false, |p| p.1 >= out) {
                    range.1 -= 1;
                }
                ans += (range.1 - range.0) as u64;
                po.chmin(out);
                while *po > 0 && dp[*po - 1].1 <= min {
                    *po -= 1;
                }
                if min.count_ones() as usize == cnt {
                    ans += *po as u64;
                }
            } else {
                rp -= 1;
                let (max, min) = right_dp[rp];
                let cnt = max.count_ones() as usize;
                let pos = &mut left_pos[cnt];
                let range = &mut left_range[cnt];
                let out = lp;
                let dp = &left_dp;
                let po = &mut left_min;
                while pos.get(range.0 - 1).map_or(false, |p| p.0 <= min || p.1 >= out) {
                    range.0 -= 1;
                }
                while pos.get(range.1 - 1).map_or(false, |p| p.1 >= out) {
                    range.1 -= 1;
                }
                ans += (range.1 - range.0) as u64;
                po.chmin(out);
                while *po > 0 && dp[*po - 1].1 <= min {
                    *po -= 1;
                }
                if min.count_ones() as usize == cnt {
                    ans += *po as u64;
                }
            }
        }
        dfs.push(l);
        dfs.push(r);
    }
    println!("{}", ans);
}

fn main() {
    run();
}