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
        n: u64,
    }
    let mut ans = 100;
    for k in 1.. {
        if k * k > n {
            break;
        }
        let a: Vec<_> = (k * k).to_string().chars().collect();
        let b: Vec<_> = n.to_string().chars().collect();
        let mut x = 0;
        let mut y = 0;
        let mut c = 0;
        while x < a.len() && y < b.len() {
            if a[x] == b[y] {
                x += 1;
                y += 1;
            } else {
                y += 1;
                c += 1;
            }
        }
        if x >= a.len() {
            c += b.len() - y;
            ans = std::cmp::min(ans, c);
        }
    }
    if ans >= 100 {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}

fn main() {
    run();
}