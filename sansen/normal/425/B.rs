// ---------- begin rotate ----------
// 1 2
// 3 4
// =>
// 3 1
// 4 2
fn rotate<T: Clone>(a: &[Vec<T>]) -> Vec<Vec<T>> {
    if a.is_empty() {
        return vec![];
    }
    let h = a.len();
    let w = a[0].len();
    assert!(a.iter().all(|a| a.len() == w));
    let mut b = (0..w).map(|_| Vec::with_capacity(h)).collect::<Vec<_>>();
    for a in a.iter().rev() {
        for (b, a) in b.iter_mut().zip(a.iter()) {
            b.push(a.clone());
        }
    }
    b
}
// ---------- end rotate ----------
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

// k <= 10
// h > k || w > k or 
// dp
// N^3
//
// h <= k && w <= k?
// 2^k * h * w
// ok?

fn run() {
    input! {
        h: usize,
        w: usize,
        k: usize,
        a: [[usize; w]; h],
    }
    let mut ans = k + 1;
    if h <= k {
        let a = rotate(&a);
        let h = a.len();
        let w = a[0].len();
        let mut b = vec![];
        for a in a.iter() {
            let mut x = 0;
            for (i, a) in a.iter().enumerate() {
                x |= *a << i;
            }
            b.push(x);
        }
        for i in 0..(1 << w) {
            let mut cnt = 0;
            for b in b.iter() {
                let x = (i ^ *b).count_ones() as usize;
                cnt += x.min(w - x);
            }
            ans = ans.min(cnt);
        }
    } else {
        for x in a.iter() {
            let mut cnt = 0;
            for a in a.iter() {
                let x = a.iter().zip(x.iter()).fold(0, |s, (a, x)| s + (*a ^ *x));
                cnt += x.min(w - x);
            }
            ans = ans.min(cnt);
        }
    }
    if ans > k {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}

fn main() {
    run();
}