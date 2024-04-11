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
        h: usize,
        w: usize,
        k: usize,
        s: [bytes; h],
        p: [(usize, usize1); k],
    }
    let mut s = s;
    for &(x, y) in p.iter() {
        s[x - 1][y] = b'X';
    }
    let mut max = {
        let mut dp = vec![vec![0; w + 1]; h + 1];
        for (i, s) in s.iter().enumerate().rev() {
            for (j, _) in s.iter().enumerate().rev().filter(|p| *p.1 != b'X') {
                dp[i][j] = dp[i + 1][j].min(dp[i][j + 1]).min(dp[i + 1][j + 1]) + 1;
            }
        }
        *dp.iter().flatten().max().unwrap()
    };
    s.insert(0, vec![b'X'; w]);
    s.push(vec![b'X'; w]);
    let mut up = vec![vec![0; w]; h + 2];
    let mut down = vec![vec![0; w]; h + 2];
    for i in 1..=h {
        for j in 0..w {
            if s[i][j] == b'X' {
                continue;
            }
            up[i][j] = up[i - 1][j] + 1;
        }
    }
    for i in (1..=h).rev() {
        for j in 0..w {
            if s[i][j] == b'X' {
                continue;
            }
            down[i][j] = down[i + 1][j] + 1;
        }
    }
    let mut ans = vec![0; k];
    for (i, &(x, y)) in p.iter().enumerate().rev() {
        ans[i] = max;
        up[x][y] = up[x - 1][y] + 1;
        for i in (x + 1)..=h {
            if up[i][y] == 0 {
                break;
            }
            up[i][y] = up[i - 1][y] + 1;
        }
        down[x][y] = down[x + 1][y] + 1;
        for i in (1..x).rev() {
            if down[i][y] == 0 {
                break;
            }
            down[i][y] = down[i + 1][y] + 1;
        }
        let up = &up[x];
        let down = &down[x];
        let can = |k: usize| -> bool {
            let mut p = std::collections::VecDeque::new();
            let mut q = std::collections::VecDeque::new();
            let mut r = 0;
            for l in 0..w {
                if r == l {
                    p.push_back((up[r], r));
                    q.push_back((down[r], r));
                    r += 1;
                }
                while r < w && r < l + k && p.front().unwrap().0 + q.front().unwrap().0 >= k + 1 {
                    let (u, d) = (up[r], down[r]);
                    while p.back().map_or(false, |p| p.0 >= u) {
                        p.pop_back();
                    }
                    p.push_back((u, r));
                    while q.back().map_or(false, |p| p.0 >= d) {
                        q.pop_back();
                    }
                    q.push_back((d, r));
                    r += 1;
                }
                if r == l + k && p.front().unwrap().0 + q.front().unwrap().0 >= k + 1 {
                    return true;
                }
                if p.front().map_or(false, |p| p.1 == l) {
                    p.pop_front();
                }
                if q.front().map_or(false, |p| p.1 == l) {
                    q.pop_front();
                }
            }
            false
        };
        while can(max + 1) {
            max += 1;
        }
    }
    for a in ans {
        println!("{}", a);
    }
}

fn main() {
    run();
}