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
        a: [[u64; w]; h],
    }
    let mut h = h;
    let mut w = w;
    let mut a = a;
    if h > w {
        let mut b = vec![vec![0u64; h]; w];
        for i in 0..h {
            for j in 0..w {
                b[j][i] = a[i][j];
            }
        }
        a = b;
        std::mem::swap(&mut h, &mut w);
    }
    let (h, w) = (h, w);
    let a = a;
    if h <= 4 {
        let mut ans = 0;
        for a in a {
            for a in a {
                ans += a;
            }
        }
        println!("{}", ans);
        return;
    }
    let mut ta = vec![vec![0; h]; w];
    for i in 0..h {
        for j in 0..w {
            ta[j][i] = a[i][j];
        }
    }
    let ta = ta;
    let mut row_sum = vec![0; h];
    let mut col_sum = vec![0; w];
    for i in 0..h {
        for j in 0..w {
            row_sum[i] += a[i][j];
            col_sum[j] += a[i][j];
        }
    }
    let (row_sum, col_sum) = (row_sum, col_sum);
    let mut ans = 0;
    for x in [row_sum.clone(), col_sum.clone()].iter_mut() {
        x.sort();
        let mut sum = 0;
        for _ in 0..4 {
            sum += x.pop().unwrap();
        }
        ans = std::cmp::max(ans, sum);
    }
    for &(row, col, a) in [(&row_sum, &col_sum, &a), (&col_sum, &row_sum, &ta)].iter() {
        for i in 0..row.len() {
            let mut sum = row[i];
            let mut b = vec![];
            for j in 0..col.len() {
                let v = col[j] - a[i][j];
                b.push(v);
            }
            b.sort();
            for _ in 0..3 {
                sum += b.pop().unwrap();
            }
            ans = std::cmp::max(ans, sum);
        }
    }
    for i in 1..h {
        for j in 0..i {
            let mut x = 0;
            let mut y = 0;
            for k in 0..w {
                let v = col_sum[k] - a[i][k] - a[j][k];
                if v > x {
                    y = x;
                    x = v;
                } else if v > y {
                    y = v;
                }
            }
            let sum = row_sum[i] + row_sum[j] + x + y;
            ans = std::cmp::max(ans, sum);
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}