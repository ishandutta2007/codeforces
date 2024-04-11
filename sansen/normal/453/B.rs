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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

//

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let w = 53;
    let mut mask = vec![0; w + 1];
    let mut id = 0;
    for i in 2..=w {
        if mask[i] > 0 {
            continue;
        }
        let v = 1 << id;
        id += 1;
        let mut j = i;
        while let Some(p) = mask.get_mut(j) {
            *p |= v;
            j += i;
        }
    }
    let diff = |a: usize, b: usize| std::cmp::max(a, b) - std::cmp::min(a, b);
    // dp[bit]: bit 
    let inf = 30 * 100;
    let mut dp = vec![inf; 1 << id];
    dp[0] = 0;
    let mut memo = vec![];
    for &a in a.iter() {
        let mut next = vec![inf; 1 << id];
        for (i, &v) in dp.iter().enumerate() {
            if v == inf {
                continue;
            }
            for (u, bit) in mask.iter().enumerate().skip(1) {
                if bit & i > 0 {
                    continue;
                }
                let k = i | bit;
                next[k] = std::cmp::min(next[k], v + diff(u, a));
            }
        }
        memo.push(dp);
        dp = next;
    }
    let mut min = (inf, 0);
    for (i, &v) in dp.iter().enumerate() {
        min = std::cmp::min(min, (v, i));
    }
    memo.push(dp);
    let mut ans = vec![];
    for i in (1..=n).rev() {
        for (v, &bit) in mask.iter().enumerate().skip(1) {
            if min.1 & bit == bit && min.0 == memo[i - 1][bit ^ min.1] + diff(a[i - 1], v) {
                min.1 ^= bit;
                min.0 = memo[i - 1][min.1];
                ans.push(v);
                break;
            }
        }
    }
    ans.reverse();
    let mut out = String::new();
    for a in ans {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}