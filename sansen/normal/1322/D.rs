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

// DP?
// 
// [][]
// 
// si
// 
// pop
// 
//
// OK
// i
// 
// faighter 1OK
//
// 
// 
// OK
// 3
// dp[][<-0]
// 
fn run() {
    input! {
        n: usize,
        m: usize,
        l: [usize1; n],
        s: [i64; n],
        c: [i64; n + m],
    }
    let ini = -1_000_000_000;
    let mut dp = std::collections::BTreeMap::<(usize, usize), i64>::new();
    for (l, s) in l.into_iter().zip(s.into_iter()).rev() {
        let mut next = dp.clone();
        for ((x, bit), v) in dp.into_iter() {
            if x > l {
                break;
            }
            let mut p = bit.checked_shr((l - x) as u32).unwrap_or(0);
            p += 1;
            let z = p.trailing_zeros() as usize;
            let mut val = v - s;
            for i in 0..=z {
                val += c[l + i];
            }
            let po = next.entry((l, p)).or_insert(ini);
            *po = std::cmp::max(*po, val);
        }
        let po = next.entry((l, 1)).or_insert(ini);
        *po = std::cmp::max(*po, -s + c[l]);
        dp = next;
    }
    let ans = std::cmp::max(0, dp.values().cloned().max().unwrap());
    println!("{}", ans);
}

fn main() {
    run();
}