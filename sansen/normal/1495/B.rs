// ---------- begin Run Length Encoding ----------
fn run_length_encoding<T: Clone + Eq>(a: &[T]) -> Vec<(T, usize)> {
    let mut a = a.iter().map(|a| (a.clone(), 1)).collect::<Vec<_>>();
    a.dedup_by(|a, b| {
        a.0 == b.0 && {
            b.1 += a.1;
            true
        }
    });
    a
}
// ---------- end Run Length Encoding ----------
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
        p: [u32; n],
    }
    let a = p.windows(2).map(|p| p[0] < p[1]).collect::<Vec<_>>();
    let z = run_length_encoding(&a);
    let max = z.iter().map(|p| p.1).max().unwrap();
    let p = z.iter().enumerate().filter(|p| (p.1).1 == max).map(|p| p.0).collect::<Vec<_>>();
    let ans = if p.len() == 2 && p[1] - p[0] == 1 && z[p[0]].0 && max % 2 == 0 {
        1
    } else {
        0
    };
    println!("{}", ans);
}

fn main() {
    run();
}