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
        m: usize,
        s: [chars; n],
    }
    let mut s = s;
    let mut ok = vec![vec![false; m]; n];
    ok[0][0] = true;
    for i in 0..n {
        for j in 0..m {
            if !ok[i][j] {
                s[i][j] = '#';
                continue;
            }
            if i + 1 < n && s[i + 1][j] == '.' {
                ok[i + 1][j] = true;
            }
            if j + 1 < m && s[i][j + 1] == '.' {
                ok[i][j + 1] = true;
            }
        }
    }
    if s[n - 1][m - 1] == '#' {
        println!("0");
        return;
    }
    let mut ok = vec![vec![false; m]; n];
    ok[n - 1][m - 1] = true;
    for i in (0..n).rev() {
        for j in (0..m).rev() {
            if !ok[i][j] {
                s[i][j] = '#';
                continue;
            }
            if i >= 1 && s[i - 1][j] == '.' {
                ok[i - 1][j] = true;
            }
            if j >= 1 && s[i][j - 1] == '.' {
                ok[i][j - 1] = true;
            }
        }
    }
    for z in 1..(n + m - 2) {
        let mut cnt = 0;
        let l = if z > n - 1 {z - n + 1} else {0};
        let r = if z > m - 1 {m - 1} else {z};
        for k in l..=r {
            assert!(z - k < n && k < m);
            if s[z - k][k] == '.' {
                cnt += 1;
            }
        }
        if cnt == 1 {
            println!("1");
            return;
        }
    }
    println!("2");
}

fn main() {
    run();
}