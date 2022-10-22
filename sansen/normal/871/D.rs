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

// 3
// 1~3
// 1
// gcd > 1 
// 2
// gcd = 1 N 
// 3
// N
// 
// 1
// 
// 2, 3
// ?
// 2 * p > N 
// ...
// N
// 
// ?
// 
// N

fn run() {
    input! {
        n: usize,
    }
    let mut factor = (0..=n).collect::<Vec<_>>();
    let mut mobius = vec![1i8; n + 1];
    let mut prime = vec![];
    let mut cnt = vec![];
    for i in 2..=n {
        if i == factor[i] {
            prime.push(i);
            let mut c = 0;
            for j in 1..=(n / i) {
                let p = &mut factor[j * i];
                if i <= *p {
                    *p = i;
                    c += 1;
                }
                mobius[j * i] *= -1;
            }
            cnt.push(c);
            let pp = i.saturating_mul(i);
            for j in 1..=(n / pp) {
                mobius[j * pp] = 0;
            }
        }
    }
    while prime.last().map_or(false, |p| 2 * *p > n) {
        prime.pop();
        cnt.pop();
    }
    let mut all = cnt.iter().sum::<i64>();
    all = all * (all - 1) / 2;
    let mut ans = 0i64;
    for (i, mobius) in mobius.iter().enumerate().skip(2) {
        let s = *mobius as i64;
        if s != 0 {
            let cnt = (n / i) as i64;
            all += s * cnt * (cnt - 1) / 2;
            ans -= cnt * (cnt - 1) / 2 * s;
        }
    }
    let mut sum = 0;
    let mut x = 0;
    let mut two = 0;
    for (i, (c, p)) in cnt.iter().zip(prime.iter()).enumerate() {
        while x < i && *p * prime[x] <= n {
            two += cnt[x];
            x += 1;
        }
        while x > 0 && *p * prime[x - 1] > n {
            x -= 1;
            two -= cnt[x];
        }
        ans += (sum - two) * *c * 3;
        all -= (sum - two) * *c;
        sum += *c;
    }
    ans += 2 * all;
    println!("{}", ans);
}

fn main() {
    run();
}