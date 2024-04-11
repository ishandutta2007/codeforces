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
        n: usize,
        iter: usize,
        a: [usize; n],
    }
    let mut z = a.clone();
    z.sort();
    z.dedup();
    let mut a = a;
    for a in a.iter_mut() {
        *a = z.binary_search(a).unwrap();
    }
    let inf = 10i32.pow(9);
    type Mat = Vec<Vec<i32>>;
    let m = z.len();
    let mul = |a: &Mat, b: &Mat| -> Mat {
        let mut c = vec![vec![-inf; m]; m];
        for (c, a) in c.iter_mut().zip(a) {
            for (a, b) in a.iter().zip(b) {
                for (c, b) in c.iter_mut().zip(b) {
                    *c = (*a + *b).max(*c);
                }
            }
        }
        c
    };
    let mut trans = vec![vec![-inf; m]; m];
    for i in 0..m {
        trans[i][i] = 0;
    }
    for a in a.iter() {
        let mut mat = vec![vec![-inf; m]; m];
        for i in 0..m {
            mat[i][i] = 0;
        }
        for j in 0..=(*a) {
            mat[*a][j] = 1;
        }
        trans = mul(&mat, &trans);
    }
    let mut t = vec![vec![-inf; m]; m];
    for i in 0..m {
        t[i][i] = 0;
    }
    let mut s = trans;
    let mut n = iter;
    while n > 0 {
        if n & 1 == 1 {
            t = mul(&t, &s);
        }
        s = mul(&s, &s);
        n >>= 1;
    }
    let ans = t.into_iter().flatten().max().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}