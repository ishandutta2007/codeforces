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
        s: bytes,
    }
    let mut fill = [[false; 3]; 4];
    for c in s.iter() {
        let k = (*c - b'0') as usize;
        if k == 0 {
            fill[3][1] = true;
        } else {
            fill[(k - 1) / 3][(k - 1) % 3] = true;
        }
    }
    let mut ok = true;
    ok &= !fill[0].iter().all(|c| !*c);
    ok &= !(!fill[3][1] && !fill[2][0] && !fill[2][2]);
    ok &= !((0..4).all(|k| !fill[k][0]) && !fill[3][1]);
    ok &= !((0..4).all(|k| !fill[k][2]) && !fill[3][1]);
    if ok {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    run();
}