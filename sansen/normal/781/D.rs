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
        m: usize,
        e: [(usize1, usize1, usize); m],
    }
    let w = 8 * std::mem::size_of::<usize>();
    let m = (n + w - 1) / w;
    let mut mat = vec![vec![vec![0usize; m]; n]; 2];
    for (a, b, x) in e {
        mat[x][b][a / w] |= 1 << (a % w);
    }
    let mut pow = vec![];
    let size = 60;
    for _ in 0..size {
        let matmul = |a: &[Vec<usize>], b: &[Vec<usize>]| -> Vec<Vec<usize>> {
            let mut tb = vec![vec![0usize; m]; n];
            for (i, b) in b.iter().enumerate() {
                for (j, tb) in tb.iter_mut().enumerate() {
                    let x = b[j / w] >> (j % w) & 1;
                    tb[i / w] |= x << (i % w);
                }
            }
            let mut c = vec![vec![0usize; m]; n];
            for (i, a) in a.iter().enumerate() {
                for (j, b) in tb.iter().enumerate() {
                    let x = a.iter().zip(b.iter()).any(|(a, b)| *a & *b > 0) as usize;
                    c[i][j / w] |= x << (j % w);
                }
            }
            c
        };
        let p = mat[0].clone();
        let q = mat[1].clone();
        pow.push(mat.clone());
        mat[0] = matmul(&q, &p);
        mat[1] = matmul(&p, &q);
    }
    let valid = |val: u64| -> bool {
        let mut a = vec![0usize; m];
        a[0] = 1;
        let mut op = 0;
        for (i, pow) in pow.iter().enumerate().rev() {
            let pow = &pow[op];
            let i = i as u64;
            if val >> i & 1 == 1 {
                op ^= 1;
                let mut b = vec![0usize; m];
                for (i, pow) in pow.iter().enumerate() {
                    let x = pow.iter().zip(a.iter()).any(|(p, a)| *p & *a > 0) as usize;
                    b[i / w] |= x << (i % w);
                }
                a = b;
            }
            if a.iter().all(|a| *a == 0) {
                return false;
            }
        }
        true
    };
    let mut ok = 0;
    let mut ng = 10u64.pow(18) + 1;
    while ng - ok > 1 {
        let mid = (ok + ng) / 2;
        if valid(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    if ng > 10u64.pow(18) {
        println!("-1");
    } else {
        println!("{}", ok);
    }
}

fn main() {
    run();
}