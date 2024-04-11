// ---------- begin enumerate prime ----------
fn enumerate_prime<F>(n: usize, mut f: F)
where
    F: FnMut(usize),
{
    assert!(1 <= n && n <= 5 * 10usize.pow(8));
    let batch = (n as f64).sqrt().ceil() as usize;
    let mut is_prime = vec![true; batch + 1];
    for i in (2..).take_while(|p| p * p <= batch) {
        if is_prime[i] {
            let mut j = i * i;
            while let Some(p) = is_prime.get_mut(j) {
                *p = false;
                j += i;
            }
        }
    }
    let mut prime = vec![];
    for (i, p) in is_prime.iter().enumerate().skip(2) {
        if *p && i <= n {
            f(i);
            prime.push(i);
        }
    }
    let mut l = batch + 1;
    while l <= n {
        let r = std::cmp::min(l + batch, n + 1);
        is_prime.clear();
        is_prime.resize(r - l, true);
        for &p in prime.iter() {
            let mut j = (l + p - 1) / p * p - l;
            while let Some(is_prime) = is_prime.get_mut(j) {
                *is_prime = false;
                j += p;
            }
        }
        for (i, _) in is_prime.iter().enumerate().filter(|p| *p.1) {
            f(i + l);
        }
        l += batch;
    }
}
// ---------- end enumerate prime ----------
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
        a: [usize; n],
    }
    let m = *a.iter().max().unwrap();
    let mut cnt = vec![0u32; m + 1];
    for a in a {
        cnt[a] += 1;
    }
    let mut prime = vec![];
    enumerate_prime(m, |p| {
        let mut elem = false;
        for i in (1..=(m / p)).rev() {
            elem |= cnt[i * p] > 0;
            cnt[i] += cnt[i * p];
        }
        if elem {
            prime.push(p);
        }
    });
    let mut dp = vec![0u64; m + 1];
    for i in (1..=m).rev() {
        if cnt[i] > 0 {
            let mut val = i as u64 * cnt[i] as u64;
            for p in prime.iter().take_while(|p| *p * i <= m) {
                val = val.max(dp[i * p] + i as u64 * (cnt[i] - cnt[i * p]) as u64);
            }
            dp[i] = val;
        }
    }
    let ans = dp.into_iter().max().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}