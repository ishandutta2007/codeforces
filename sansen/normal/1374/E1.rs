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
        n: usize,
        k: usize,
        p: [(u32, usize, usize); n],
    }
    let mut a = vec![vec![vec![]; 2]; 2];
    for (t, x, y) in p {
        a[x][y].push(t);
    }
    a[1][1].sort();
    a[1][0].sort();
    a[0][1].sort();
    let x = a[1][0].iter().zip(a[0][1].iter()).map(|p| p.0 + p.1).collect::<Vec<_>>();
    let y = a[1][1].clone();
    if x.len() + y.len() < k {
        println!("-1");
        return;
    }
    let mut sum = x.iter().sum::<u32>() + y.iter().sum::<u32>();
    let mut i = y.len();
    while i > 0 && x.len() + i > k {
        i -= 1;
        sum -= y[i];
    }
    let mut ans = sum;
    for (j, x) in x.iter().enumerate().rev() {
        sum -= x;
        while i < y.len() && i + j < k {
            sum += y[i];
            i += 1;
        }
        if i + j == k {
            ans = std::cmp::min(sum, ans);
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}