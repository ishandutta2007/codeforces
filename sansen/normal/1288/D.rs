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
        a: [[u32; m]; n],
    }
    let mut ok = 0;
    let mut ng = 1_000_000_001;
    while ng - ok > 1 {
        let mid = (ok + ng) / 2;
        let mut elem = vec![false; 1 << m];
        for a in a.iter() {
            let mut bit = 0;
            for (j, a) in a.iter().enumerate() {
                if *a >= mid {
                    bit |= 1 << j;
                }
            }
            elem[bit] = true;
        }
        let mut cond = false;
        for i in 0..(1 << m) {
            for j in 0..=i {
                if elem[i] && elem[j] && (i | j) == (1 << m) - 1 {
                    cond = true;
                }
            }
        }
        if cond {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    let mut elem = vec![n; 1 << m];
    for (i, a) in a.iter().enumerate() {
        let mut bit = 0;
        for (j, a) in a.iter().enumerate() {
            if *a >= ok {
                bit |= 1 << j;
            }
        }
        elem[bit] = i;
    }
    let mut pair = (n, n);
    for i in 0..(1 << m) {
        for j in 0..=i {
            if elem[i] < n && elem[j] < n && (i | j) == (1 << m) - 1 {
                pair = (elem[i], elem[j]);
            }
        }
    }
    println!("{} {}", pair.0 + 1, pair.1 + 1);
}

fn main() {
    run();
}