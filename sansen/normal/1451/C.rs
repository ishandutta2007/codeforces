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


use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [(usize, i32, bytes, bytes); t],
    }
    for (_n, k, a, b) in ask {
        let w = 26;
        let calc = |s: &[u8]| -> Vec<i32> {
            let mut cnt = vec![0; w];
            for c in s.iter() {
                cnt[(*c - b'a') as usize] += 1;
            }
            cnt
        };
        let ca = calc(&a);
        let cb = calc(&b);
        let mut rem = 0;
        let mut ok = true;
        for i in 0..(w - 1) {
            let a = ca[i];
            let b = cb[i];
            if a >= b {
                ok &= (a - b) % k == 0;
                rem += (a - b) / k;
            } else {
                ok &= (b - a) % k == 0 && (b - a) / k <= rem;
                rem -= (b - a) / k;
            }
            ok &= rem >= 0;
        }
        ok &= cb[w - 1] >= ca[w - 1] && (cb[w - 1] - ca[w - 1]) % k == 0;
        let ans = if ok {
            "Yes"
        } else {
            "No"
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}