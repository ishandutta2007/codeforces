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
        s: [chars; h],
    }
    let mut cnt = vec![vec![0; w + 1]; h + 1];
    for i in (0..h).rev() {
        for j in (0..w).rev() {
            cnt[i][j] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1];
            if s[i][j] == 'X' {
                cnt[i][j] += 1;
            }
        }
    }
    let mut l = 0;
    let mut r = (std::cmp::min(h, w) - 1) / 2 + 1;
    while r - l > 1 {
        let m = (l + r) / 2;
        let mut a = vec![vec!['.'; w]; h];
        let mut q = std::collections::VecDeque::new();
        for i in m..(h - m) {
            for j in m..(w - m) {
                let x = i - m;
                let y = j - m;
                let z = i + m + 1;
                let w = j + m + 1;
                if cnt[x][y] - cnt[x][w] - cnt[z][y] + cnt[z][w] == (z - x) * (w - y) {
                    a[i][j] = 'X';
                    q.push_back((i, j, 0));
                }
            }
        }
        while let Some((i, j, d)) = q.pop_front() {
            if d == m {
                break;
            }
            for &(x, y) in [(i + 1, j), (i + 1, j + 1), (i, j + 1), (i - 1, j + 1), (i - 1, j), (i - 1, j - 1), (i, j - 1), (i + 1, j - 1)].iter() {
                if a[x][y] == '.' {
                    a[x][y] = 'X';
                    q.push_back((x, y, d + 1));
                }
            }
        }
        let mut ok = true;
        for i in 0..h {
            for j in 0..w {
                if s[i][j] != a[i][j] {
                    ok = false;
                }
            }
        }
        if ok {
            l = m;
        } else {
            r = m;
        }
    }
    let mut a = vec![vec!['.'; w]; h];
    let m = l;
    for i in m..(h - m) {
        for j in m..(w - m) {
            let x = i - m;
            let y = j - m;
            let z = i + m + 1;
            let w = j + m + 1;
            if cnt[x][y] - cnt[x][w] - cnt[z][y] + cnt[z][w] == (z - x) * (w - y) {
                a[i][j] = 'X';
            }
        }
    }
    let cnt = l;
    let mut ans = String::new();
    for i in 0..h {
        for j in 0..w {
            ans.push(a[i][j]);
        }
        ans.push('\n');
    }
    print!("{}\n{}", cnt, ans);
}

fn main() {
    run();
}