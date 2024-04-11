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
        s: chars,
    }
    let s: Vec<usize> = s.into_iter().map(|c| c.to_digit(36).unwrap() as usize - 10).collect();
    let mut color = vec![0; n];
    for i in 1.. {
        let mut id = vec![0; i];
        for j in 0..n {
            color[j] = 0;
            for k in 0..i {
                if id[k] <= s[j] {
                    color[j] = k + 1;
                    id[k] = s[j];
                    break;
                }
            }
            if color[j] == 0 {
                break;
            }
        }
        if color[n - 1] > 0 {
            break;
        }
    }
    let mut out = String::new();
    out.push_str(&format!("{}\n", *color.iter().max().unwrap()));
    for k in color {
        out.push_str(&format!("{} ", k));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}