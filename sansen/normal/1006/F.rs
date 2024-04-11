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
        h: usize,
        w: usize,
        k: u64,
        a: [[u64; w]; h],
    }
    let m = 19;
    let mut up = vec![vec![vec![]; w]; h];
    up[0][0].push((0, 1u64));
    for i in 0..h {
        for j in 0..w {
            up[i][j].sort();
            up[i][j].dedup_by(|a, b| {
                let cond = a.0 == b.0;
                if cond {
                    b.1 += a.1;
                }
                cond
            });
            for u in up[i][j].iter_mut() {
                u.0 ^= a[i][j];
            }
            if i + j >= m {
                continue;
            }
            let v = up[i][j].clone();
            if i + 1 < h {
                up[i + 1][j].extend_from_slice(&v);
            }
            if j + 1 < w {
                up[i][j + 1].extend_from_slice(&v);
            }
        }
    }
    let mut down = vec![vec![vec![]; w]; h];
    down[h - 1][w - 1].push((0, 1u64));
    for i in (0..h).rev() {
        for j in (0..w).rev() {
            down[i][j].sort();
            down[i][j].dedup_by(|a, b| {
                let cond = a.0 == b.0;
                if cond {
                    b.1 += a.1;
                }
                cond
            });
            for u in down[i][j].iter_mut() {
                u.0 ^= a[i][j];
            }
            if (h - 1 - i) + (w - 1 - j) >= m {
                continue;
            }
            let v = down[i][j].clone();
            if i > 0 {
                down[i - 1][j].extend_from_slice(&v);
            }
            if j > 0 {
                down[i][j - 1].extend_from_slice(&v);
            }
        }
    }
    if h - 1 + w - 1 <= m {
        let mut ans = 0;
        for &(x, c) in up[h - 1][w - 1].iter() {
            if x == k {
                ans = c;
            }
        }
        println!("{}", ans);
        return;
    }
    let mut ans = 0u64;
    for i in 0..=m {
        let j = m - i;
        if i < h && j < w {
            let mut map = std::collections::BTreeMap::new();
            for &(x, c) in up[i][j].iter() {
                map.insert(x, c);
            }
            for &(a, b) in [(i + 1, j), (i, j + 1)].iter() {
                if a < h && b < w {
                    for &(x, c) in down[a][b].iter() {
                        ans += c * map.get(&(x ^ k)).map_or(0, |u| *u);
                    }
                }
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}