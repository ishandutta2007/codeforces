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
        a: [usize; n],
    }
    let m = 2_500_000;
    let mut cnt = vec![0; m + 1];
    for a in a.iter() {
        cnt[*a] += 1;
    }
    if let Some(x) = cnt.iter().position(|c| *c >= 4) {
        let mut ans = vec![];
        for (i, a) in a.iter().enumerate() {
            if *a == x {
                ans.push(i + 1);
            }
        }
        println!("YES");
        println!("{} {} {} {}", ans[0], ans[1], ans[2], ans[3]);
        return;
    }
    if let Some(x) = cnt.iter().position(|c| *c >= 2) {
        let y = cnt.iter().rposition(|c| *c >= 2).unwrap();
        if x != y {
            let mut p = vec![];
            let mut q = vec![];
            for (i, a) in a.iter().enumerate() {
                if *a == x {
                    p.push(i + 1);
                } else if *a == y {
                    q.push(i + 1);
                }
            }
            println!("YES");
            println!("{} {} {} {}", p[0], q[0], p[1], q[1]);
            return;
        } else {
            let mut p = vec![];
            let mut b = vec![];
            for (i, a) in a.iter().enumerate() {
                if *a == x {
                    p.push(i + 1);
                } else {
                    b.push((*a, i + 1));
                }
            }
            b.sort();
            for i in 0..b.len() {
                let v = b[i].0;
                if v < 2 * x {
                    if let Ok(q) = b.binary_search_by_key(&(2 * x - v), |b| b.0) {
                        println!("YES");
                        println!("{} {} {} {}", p[0], p[1], b[i].1, b[q].1);
                        return;
                    }
                }
            }
        }
    }
    let mut a = a.into_iter().enumerate().collect::<Vec<_>>();
    a.sort_by_key(|p| p.1);
    a.dedup_by(|a, b| a.1 == b.1);
    let mut dp = vec![(n, n); 2 * m + 1];
    for (i, x) in a.iter().enumerate() {
        for y in a.iter().take(i) {
            let p = x.1 + y.1;
            if dp[p] != (n, n) {
                println!("YES");
                println!("{} {} {} {}", dp[p].0 + 1, dp[p].1 + 1, x.0 + 1, y.0 + 1);
                return;
            }
            dp[p] = (x.0, y.0);
        }
    }
    println!("NO");
}

fn main() {
    run();
}