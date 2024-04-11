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

fn calc(used: usize, m: usize, memo: &mut [Option<f64>], cnt: &[usize]) -> f64 {
    if let Some(v) = memo[used] {
        return v;
    }
    if cnt[used] == 0 {
        return 0f64;
    }
    let mut ans = 0f64;
    let mut d = 0;
    for i in 0..m {
        if used >> i & 1 == 0 {
            let x = used | (1 << i);
            ans += calc(x, m, memo, cnt) * cnt[x] as f64 / cnt[used] as f64;
            d += 1;
        }
    }
    ans = 1f64 + ans / d as f64;
    memo[used] = Some(ans);
    ans
}

fn run() {
    input! {
        n: usize,
        s: [bytes; n],
    }
    let m = s[0].len();
    let mut cnt = vec![0; 1 << m];
    for a in s.chunks(7) {
        let mut buf = vec![0u64; 1 << m];
        for (i, a) in a.iter().enumerate() {
            for s in s.iter() {
                let mut bit = 0;
                for (i, (a, s)) in a.iter().zip(s.iter()).enumerate() {
                    if *a == *s {
                        bit |= 1 << i;
                    }
                }
                if bit == (1 << m) - 1 {
                    continue;
                }
                buf[bit] += 1u64 << (8 * i);
            }
        }
        for i in 0..m {
            for j in 0..(1 << m) {
                if j >> i & 1 == 1 {
                    buf[j ^ (1 << i)] += buf[j];
                }
            }
        }
        for (cnt, bit) in cnt.iter_mut().zip(buf.iter()) {
            let mask = (1 << 8) - 1;
            let mut bit = *bit;
            for _ in 0..a.len() {
                if bit & mask > 0 {
                    *cnt += 1;
                }
                bit >>= 8;
            }
        }
    }
    let mut dp = vec![None; 1 << m];
    let ans = calc(0, m, &mut dp, &cnt);
    println!("{:.10}", ans);
}

fn main() {
    run();
}