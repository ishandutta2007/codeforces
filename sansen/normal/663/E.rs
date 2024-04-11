// ---------- begin bitwise transform ----------
fn bitwise_transform<T, F>(a: &mut [T], mut f: F)
where
    F: FnMut(&mut T, &mut T)
{
    let n = a.len().trailing_zeros() as usize;
    assert!(a.len() == 1 << n);
    for i in 0..n {
        for a in a.chunks_exact_mut(2 << i) {
            let (x, y) = a.split_at_mut(1 << i);
            for (x, y) in x.iter_mut().zip(y) {
                f(x, y);
            }
        }
    }
}
// ---------- end bitwise transform ----------
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
        m: usize,
        s: [bytes; n],
    }
    let mut cnt = vec![0i64; 1 << n];
    for j in 0..m {
        let x = s.iter().fold(0, |x, s| 2 * x + (s[j] - b'0') as usize);
        cnt[x] += 1;
    }
    let mut cost = (0i64..(1 << n)).map(|c| {
        let c = c.count_ones() as i64;
        c.min(n as i64 - c)
    }).collect::<Vec<_>>();
    bitwise_transform(&mut cnt, |a, b| {
        let x = *a + *b;
        let y = *a - *b;
        *a = x;
        *b = y;
    });
    bitwise_transform(&mut cost, |a, b| {
        let x = *a + *b;
        let y = *a - *b;
        *a = x;
        *b = y;
    });
    cnt.iter_mut().zip(cost).for_each(|p| *p.0 *= p.1);
    bitwise_transform(&mut cnt, |a, b| {
        let x = (*a + *b) / 2;
        let y = (*a - *b) / 2;
        *a = x;
        *b = y;
    });
    let ans = cnt.into_iter().min().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}