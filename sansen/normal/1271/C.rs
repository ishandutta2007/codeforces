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

fn solve(a: &[u32], s: u32) -> (i32, u32) {
    let mut z = vec![];
    z.push(s);
    z.push(s + 1);
    for &x in a.iter() {
        if x < s {
            z.push(x);
        } else if x > s {
            z.push(x + 1);
        }
    }
    z.sort();
    z.dedup();
    let mut imos = vec![0; z.len()];
    for &x in a.iter() {
        if x < s {
            let l = z.binary_search(&x).unwrap();
            let r = z.binary_search(&s).unwrap();
            imos[l] += 1;
            imos[r] -= 1;
        } else if x > s {
            let l = z.binary_search(&(s + 1)).unwrap();
            let r = z.binary_search(&(x + 1)).unwrap();
            imos[l] += 1;
            imos[r] -= 1;
        }
    }
    for i in 1..z.len() {
        imos[i] += imos[i - 1];
    }
    let mut ans = (0, 0);
    for i in 0..z.len() {
        ans = std::cmp::max(ans, (imos[i], z[i]));
    }
    ans
}

fn run() {
    input! {
        n: usize,
        s: (u32, u32),
        p: [(u32, u32); n],
    }
    let mut a = vec![];
    let mut b = vec![];
    for (x, y) in p {
        a.push(x);
        b.push(y);
    }
    let mut ans = (0, 0, 0);
    let (c, x) = solve(&a, s.0);
    ans = std::cmp::max(ans, (c, x, s.1));
    let (c, y) = solve(&b, s.1);
    ans = std::cmp::max(ans, (c, s.0, y));
    println!("{}\n{} {}", ans.0, ans.1, ans.2);
}

fn main() {
    run();
}