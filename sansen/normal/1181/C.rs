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
        s: [bytes; h],
    }
    let mut down = vec![vec![0; w]; h];
    down[h - 1] = vec![1; w];
    for i in (0..(h - 1)).rev() {
        for j in 0..w {
            if s[i][j] == s[i + 1][j] {
                down[i][j] = down[i + 1][j] + 1;
            } else {
                down[i][j] = 1;
            }
        }
    }
    let mut ans = 0u64;
    for i in 0..h {
        let mut j = 0;
        while j < w {
            let d = down[i][j];
            let b = i + d;
            let c = i + 2 * d;
            if !(c < h && down[b][j] == d && down[c][j] >= d) {
                j += 1;
                continue;
            }
            let l = j;
            let mut r = j + 1;
            while r < w {
                let mut ok = true;
                ok &= s[i][l] == s[i][r];
                ok &= s[b][l] == s[b][r];
                ok &= s[c][l] == s[c][r];
                ok &= down[i][r] == d;
                ok &= down[b][r] == d;
                ok &= down[c][r] >= d;
                if ok {
                    r += 1;
                } else {
                    break;
                }
            }
            ans += ((r - l) * (r - l + 1) / 2) as u64;
            j = r;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}