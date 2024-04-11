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
        s: [bytes; n],
    }
    let mut ans = vec![vec![b'x'; 2 * n - 1]; 2 * n - 1];
    ans[n - 1][n - 1] = b'o';
    let mut pos = vec![];
    for (i, s) in s.iter().enumerate() {
        for (j, c) in s.iter().enumerate() {
            if *c == b'o' {
                pos.push((i, j));
            }
        }
    }
    for &(x, y) in pos.iter() {
        for (i, s) in s.iter().enumerate() {
            for (j, c) in s.iter().enumerate() {
                if *c == b'.' {
                    ans[n - 1 + i - x][n - 1 + j - y] = b'.';
                }
            }
        }
    }
    let mut tmp = vec![vec![b'.'; n]; n];
    for &(x, y) in pos.iter() {
        for (i, ans) in ans.iter().enumerate() {
            for (j, ans) in ans.iter().enumerate() {
                if *ans == b'x' {
                    let x = x + i - (n - 1);
                    let y = y + j - (n - 1);
                    if x < n && y < n {
                        tmp[x][y] = b'x';
                    }
                }
            }
        }
    }
    for (x, y) in pos {
        tmp[x][y] = b'o';
    }
    if tmp != s {
        println!("NO");
        return;
    }
    println!("YES");
    for s in ans {
        let s = s.into_iter().map(|c| c as char).collect::<String>();
        println!("{}", s);
    }
}

fn main() {
    run();
}