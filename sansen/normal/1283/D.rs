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
        x: [i64; n],
    }
    let mut used = std::collections::BTreeSet::new();
    for &x in x.iter() {
        used.insert(x);
    }
    let mut queue = std::collections::VecDeque::new();
    for &x in x.iter() {
        for &v in [x - 1, x + 1].into_iter() {
            if !used.contains(&v) {
                used.insert(v);
                queue.push_back((v, 1));
            }
        }
    }
    let mut y = vec![];
    let mut sum = 0i64;
    for _ in 0..m {
        let (z, d) = queue.pop_front().unwrap();
        y.push(z);
        sum += d;
        for &v in [z - 1, z + 1].into_iter() {
            if !used.contains(&v) {
                used.insert(v);
                queue.push_back((v, d + 1));
            }
        }
    }
    let mut out = String::new();
    out.push_str(&format!("{}\n", sum));
    for y in y {
        out.push_str(&format!("{} ", y));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}