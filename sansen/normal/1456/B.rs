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
    let w = 30;
    let mut cnt = vec![0; w];
    let mut k = 0;
    for a in a.iter() {
        while (2 << k) <= *a {
            k += 1;
        }
        cnt[k] += 1;
    }
    if cnt.iter().any(|c| *c > 2) {
        println!("1");
        return;
    }
    let mut ans = n;
    let mut xor = a;
    xor.push(0);
    for i in (0..n).rev() {
        xor[i] ^= xor[i + 1];
    }
    for l in 0..n {
        for m in (l + 1)..n {
            for r in (m + 1)..=n {
                if xor[l] ^ xor[m] > xor[m] ^ xor[r] {
                    ans = ans.min(m - l - 1 + r - m - 1);
                }
            }
        }
    }
    if ans == n {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}

fn main() {
    run();
}