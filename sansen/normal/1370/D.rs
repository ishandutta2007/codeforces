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

//

fn chmax<T: PartialOrd>(x: &mut T, a: T) -> bool {
    if *x < a {
        *x = a;
        true
    } else {
        false
    }
}

fn run() {
    input! {
        n: usize,
        k: i32,
        a: [u32; n],
    }
    let valid = |v: u32| -> bool {
        for p in 0..2 {
            let mut dp = [0, std::i32::MIN];
            for a in a.iter() {
                let mut next = dp;
                if *a <= v {
                    chmax(&mut next[p ^ 1], dp[p] + 1);
                }
                chmax(&mut next[p], dp[p ^ 1] + 1);
                dp = next;
            }
            if dp[0] >= k || dp[1] >= k {
                return true;
            }
        }
        false
    };
    let mut ng = 0;
    let mut ok = *a.iter().max().unwrap();
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        if valid(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    println!("{}", ok);
}

fn main() {
    run();
}