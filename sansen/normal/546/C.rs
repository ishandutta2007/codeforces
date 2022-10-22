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
        _n: usize,
        a: usize,
        x: [u8; a],
        b: usize,
        y: [u8; b],
    }
    let mut x = x.into_iter().collect::<std::collections::VecDeque<_>>();
    let mut y = y.into_iter().collect::<std::collections::VecDeque<_>>();
    let mut set = std::collections::BTreeSet::new();
    let mut ans = 0;
    while x.len() * y.len() > 0 {
        if !set.insert((x.clone(), y.clone())) {
            println!("-1");
            return;
        }
        ans += 1;
        let a = x.pop_front().unwrap();
        let b = y.pop_front().unwrap();
        if a < b {
            y.push_back(a);
            y.push_back(b);
        } else {
            x.push_back(b);
            x.push_back(a);
        }
    }
    print!("{} ", ans);
    if x.len() > 0 {
        println!("1");
    } else {
        println!("2");
    }
}

fn main() {
    run();
}