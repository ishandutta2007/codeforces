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
        m: usize,
        ask: [(usize1, usize, u32); m],
    }
    let w = 30;
    let mut imos = vec![vec![0; n + 1]; w];
    for &(l, r, q) in ask.iter() {
        for (k, imos) in imos.iter_mut().enumerate() {
            if q >> k & 1 == 1 {
                imos[l] += 1;
                imos[r] -= 1;
            }
        }
    }
    for imos in imos.iter_mut() {
        for i in 1..=n {
            imos[i] += imos[i - 1];
        }
        for imos in imos.iter_mut() {
            if *imos > 0 {
                *imos = 1;
            } else {
                *imos = 0;
            }
        }
        for i in (0..n).rev() {
            imos[i] += imos[i + 1];
        }
    }
    for &(l, r, q) in ask.iter() {
        for (k, imos) in imos.iter().enumerate() {
            if q >> k & 1 == 1 {
                if imos[l] - imos[r] != r - l {
                    println!("NO");
                    return;
                }
            } else {
                if imos[l] - imos[r] == r - l {
                    println!("NO");
                    return;
                }
            }
        }
    }
    println!("YES");
    let mut ans = String::new();
    for i in 0..n {
        let mut a = 0;
        for (j, imos) in imos.iter().enumerate() {
            if imos[i] - imos[i + 1] > 0 {
                a |= 1 << j;
            }
        }
        ans.push_str(&format!("{} ", a));
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}