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

use std::cmp::{max, min};

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        p: [(usize, usize); k],
    }
    let mut row = vec![vec![]; n + 1];
    let mut col = vec![vec![]; m + 1];
    for (x, y) in p {
        row[x].push(y);
        col[y].push(x);
    }
    for i in 1..=n {
        row[i].push(0);
        row[i].push(m + 1);
        row[i].sort();
    }
    for i in 1..=m {
        col[i].push(0);
        col[i].push(n + 1);
        col[i].sort();
    }
    let mut dir = 0;
    let mut now = (1usize, 1usize);
    let mut bound = [m + 1, n + 1, 0, 0];
    let mut sum = 1i64;
    let mut update = true;
    loop {
        if dir == 0 {
            let mut v = bound[0];
            for &c in &row[now.0] {
                if c > now.1 {
                    v = min(c, v);
                    break;
                }
            }
            if now.1 + 1 < v {
                update = true;
            }
            sum += (v - now.1 - 1) as i64;
            now.1 = v - 1;
            bound[3] = now.0;
        } else if dir == 1 {
            let mut v = bound[1];
            for &c in &col[now.1] {
                if c > now.0 {
                    v = min(c, v);
                    break;
                }
            }
            if now.0 + 1 < v {
                update = true;
            }
            sum += (v - now.0 - 1) as i64;
            now.0 = v - 1;
            bound[0] = now.1;
        } else if dir == 2 {
            let mut v = bound[2];
            for &c in row[now.0].iter().rev() {
                if c < now.1 {
                    v = max(c, v);
                    break;
                }
            }
            if now.1 > v + 1 {
                update = true;
            }
            sum += (now.1 - v - 1) as i64;
            now.1 = v + 1;
            bound[1] = now.0;
        } else {
            let mut v = bound[3];
            for &c in col[now.1].iter().rev() {
                if c < now.0 {
                    v = max(c, v);
                    break;
                }
            }
            if now.0 > v + 1 {
                update = true;
            }
            sum += (now.0 - v - 1) as i64;
            now.0 = v + 1;
            bound[2] = now.1;
        }
        if !update {
            break;
        }
        update = false;
        dir = (dir + 1) % 4;
    }
    let mut ans = 0i64;
    for i in 1..=n {
        ans += (m - row[i].len() + 2) as i64;
    }
    if ans != sum {
        println!("No");
    } else {
        println!("Yes");
    }
}

fn main() {
    run();
}