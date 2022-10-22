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

type Point = (i64, i64);

fn norm(a: Point, b: Point) -> i64 {
    (a.0 - b.0).pow(2) + (a.1 - b.1).pow(2)
}

fn run() {
    input! {
        n: usize,
        p: [(i64, i64); n],
    }
    let mut used = vec![false; n];
    let mut ans = vec![];
    ans.push(0);
    used[0] = true;
    let mut pos = p[0];
    for _ in 1..n {
        let mut x = used.iter().position(|u| !*u).unwrap();
        for j in x..n {
            if !used[j] && norm(pos, p[x]) < norm(pos, p[j]) {
                x = j;
            }
        }
        used[x] = true;
        ans.push(x);
        pos = p[x];
    }
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a + 1));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}