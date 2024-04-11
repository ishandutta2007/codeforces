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

//

fn run() {
    input! {
        h: usize,
        w: usize,
        a: [[usize; w]; h],
    }
    let mut row = a.iter().map(|a| *a.iter().max().unwrap()).collect::<Vec<_>>();
    let mut col = (0..w).map(|k| a.iter().map(|a| a[k]).max().unwrap()).collect::<Vec<_>>();
    row.sort();
    col.sort();
    let mut q = std::collections::VecDeque::new();
    let mut ans = vec![vec![0; w]; h];
    for i in (1..=(h * w)).rev() {
        let r = row.last().map_or(false, |p| *p == i);
        let c = col.last().map_or(false, |p| *p == i);
        match (r, c) {
            (true, true) => {
                row.pop();
                col.pop();
                let x = row.len();
                let y = col.len();
                ans[x][y] = i;
                for j in (y + 1)..w {
                    q.push_back((x, j));
                }
                for j in (x + 1)..h {
                    q.push_back((j, y));
                }
            },
            (true, false) => {
                row.pop();
                let x = row.len();
                let y = col.len();
                ans[x][y] = i;
                for j in (y + 1)..w {
                    q.push_back((x, j));
                }
            },
            (false, true) => {
                col.pop();
                let x = row.len();
                let y = col.len();
                ans[x][y] = i;
                for j in (x + 1)..h {
                    q.push_back((j, y));
                }
            },
            (false, false) => {
                let (x, y) = q.pop_front().unwrap();
                ans[x][y] = i;
            },
        }
    }
    let mut s = String::new();
    for a in ans {
        for a in a {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        s.push('\n');
    }
    print!("{}", s);
}

fn main() {
    run();
}