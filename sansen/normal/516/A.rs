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
        s: bytes,
    }
    let mut cnt = vec![0; 4];
    let p = [2, 3, 5, 7];
    for c in s {
        let k = (c - b'0') as usize;
        match k {
            2 => cnt[0] += 1,
            3 => cnt[1] += 1,
            4 => {
                cnt[0] += 2;
                cnt[1] += 1;
            },
            5 => cnt[2] += 1,
            6 => {
                cnt[2] += 1;
                cnt[1] += 1;
            },
            7 => cnt[3] += 1,
            8 => {
                cnt[3] += 1;
                cnt[0] += 3;
            },
            9 => {
                cnt[3] += 1;
                cnt[1] += 2;
                cnt[0] += 1;
            },
            _ => (),
        }
    }
    for (p, c) in p.iter().zip(cnt.iter()).rev() {
        for _ in 0..*c {
            print!("{}", *p)
        }
    }
    println!();
}

fn main() {
    run();
}