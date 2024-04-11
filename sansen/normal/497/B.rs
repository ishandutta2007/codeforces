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

use std::cmp::*;

fn run() {
    input! {
        n: usize,
        a: [usize1; n],
    }
    let mut x = vec![vec![]; 2];
    for (i, a) in a.iter().enumerate() {
        x[*a].push(i);
    }
    let last = a[n - 1];
    let mut ans = vec![];
    for t in 1..=n {
        let mut s = [0; 2];
        let mut win = [0; 2];
        loop {
            let mut v = (std::usize::MAX, 2);
            if s[0] + t - 1 < x[0].len() {
                v = (x[0][s[0] + t - 1], 0);
            }
            if s[1] + t - 1 < x[1].len() {
                v = min(v, (x[1][s[1] + t - 1], 1));
            }
            if v.0 == std::usize::MAX {
                if s[0] == x[0].len() && s[1] == x[1].len() && win[last] > win[last ^ 1] {
                    ans.push((t, win[last]));
                }
                break;
            } else {
                win[v.1] += 1;
                s[0] = x[0].binary_search_by_key(&(v.0, 1), |x| (*x, 0)).unwrap_err();
                s[1] = x[1].binary_search_by_key(&(v.0, 1), |x| (*x, 0)).unwrap_err();
            }
        }
    }
    ans.sort_by_key(|p| p.1);
    println!("{}", ans.len());
    for (t, s) in ans {
        println!("{} {}", s, t);
    }
    /*
    let last = a[n - 1];
    let mut ans = vec![];
    for t in 1..=n {
        let mut win = [0; 2];
        let mut cnt = [0; 2];
        for &a in a.iter() {
            cnt[a] += 1;
            if cnt[a] == t {
                win[a] += 1;
                cnt = [0; 2];
            }
        }
        if cnt == [0; 2] && win[last] > win[last ^ 1] {
            ans.push((t, win[last]));
        }
    }
    */
}

fn main() {
    run();
}