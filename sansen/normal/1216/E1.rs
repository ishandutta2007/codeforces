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

fn length(n: u64) -> u64 {
    let mut ans = 0;
    let mut len = 1;
    let mut cnt = 9;
    let mut sum = 0;
    let mut used = 0;
    while used + cnt <= n {
        ans += sum * cnt + len * cnt * (cnt + 1) / 2;
        sum += len * cnt;
        len += 1;
        used += cnt;
        cnt *= 10;
    }
    let cnt = n - used;
    ans += sum * cnt + len * cnt * (cnt + 1) / 2;
    ans
}

fn run() {
    input! {
        q: usize,
        a: [u64; q],
    }
    for k in a {
        let k = k - 1;
        let mut l = 0;
        let mut r = 500_000_000;
        while r - l > 1 {
            let m = (l + r) / 2;
            if k < length(m) {
                r = m;
            } else {
                l = m;
            }
        }
        let mut k = if l > 0 {
            k - length(l)
        } else {
            k
        };
        let mut len = 1;
        let mut cnt = 9;
        while k >= len * cnt {
            k -= len * cnt;
            len += 1;
            cnt *= 10;
        }
        let begin = cnt / 9;
        let d = k / len;
        let s: Vec<char> = (begin + d).to_string().chars().collect();
        println!("{}", s[(k % len) as usize]);
    }
}

fn main() {
    run();
}