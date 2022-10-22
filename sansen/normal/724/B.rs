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
        a: [[usize1; w]; h],
    }
    let valid = |mut a: Vec<Vec<usize>>| -> bool {
        for a in a.iter_mut() {
            let mut cnt = 0;
            for (i, a) in a.iter().enumerate() {
                if i != *a {
                    cnt += 1;
                }
            }
            if cnt > 2 {
                return false;
            }
        }
        true
    };
    for i in 0..w {
        for j in 0..i {
            let mut a = a.clone();
            for a in a.iter_mut() {
                a.swap(i, j);
            }
            if valid(a) {
                println!("YES");
                return;
            }
        }
    }
    if valid(a) {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    run();
}