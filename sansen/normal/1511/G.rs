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

#[target_feature(enable = "avx2")]
unsafe fn run() {
    input! {
        n: usize,
        _m: usize,
        c: [usize1; n],
        q: usize,
        ask: [(usize1, usize); q],
    }
    let mut c = c;
    c.sort();
    let c = c;
    let mut ans = String::new();
    for (l, r) in ask {
        let s = c.binary_search_by_key(&(l, 1), |c| (*c, 0)).unwrap_err();
        let t = c.binary_search_by_key(&(r, 0), |c| (*c, 1)).unwrap_err();
        let mut xor = 0;
        for c in c[s..t].iter() {
            xor ^= *c - l;
        }
        if xor > 0 {
            ans.push('A');
        } else {
            ans.push('B');
        }
    }
    println!("{}", ans);
}

fn main() {
    unsafe {
        run();
    }
}