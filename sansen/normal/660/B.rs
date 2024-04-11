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
    }
    let mut i = 1;
    let mut ans = vec![vec![0; 4]; n];
    for ans in ans.iter_mut() {
        if i <= m {
            ans[0] = i;
            i += 1;
        }
        if i <= m {
            ans[3] = i;
            i += 1;
        }
    }
    for ans in ans.iter_mut() {
        if i <= m {
            ans[1] = i;
            i += 1;
        }
        if i <= m {
            ans[2] = i;
            i += 1;
        }
    }
    let mut out = String::new();
    for ans in ans {
        for &k in [1, 0, 2, 3].iter() {
            if ans[k] > 0 {
                out.push_str(&format!("{} ", ans[k]));
            }
        }
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}