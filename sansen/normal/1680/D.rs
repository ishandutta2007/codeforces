fn run() {
    input! {
        n: usize,
        k: i64,
        a: [i64; n],
    }
    let zero = a.iter().filter(|a| **a == 0).count() as i64;
    let sum = a.iter().sum::<i64>();
    if sum.abs() > zero * k {
        println!("-1");
        return;
    }
    let mut a = a;
    let mut ans = 0;
    for _ in 0..2 {
        {
            let a = &a;
            let mut zero = a.iter().filter(|a| **a == 0).count() as i64;
            let mut val = vec![];
            let mut sum = a.iter().sum::<i64>();
            while sum.abs() >= k {
                zero -= 1;
                if sum >= 0 {
                    sum -= k;
                    val.push(-k);
                } else {
                    sum += k;
                    val.push(k);
                }
            }
            while zero > 2 {
                val.push(-k);
                val.push(k);
                zero -= 2;
            }
            if zero == 2 {
                if sum == 0 {
                    val.push(-k);
                    val.push(k);
                } else if sum > 0 {
                    val.push(k - sum);
                    val.push(-k);
                } else {
                    val.push(-k - sum);
                    val.push(k);
                }
            } else if zero == 1 {
                val.push(-sum);
            }
            val.sort_by_key(|p| -*p);
            for _ in 0..2 {
                for _ in 0..=val.len() {
                    let mut l = 0;
                    let mut r = 0;
                    let mut pos = 0;
                    let mut x = 0;
                    for a in a.iter() {
                        if *a == 0 {
                            pos += val[x];
                            x += 1;
                        } else {
                            pos += *a;
                        }
                        l = l.min(pos);
                        r = r.max(pos);
                    }
                    ans = ans.max(r - l + 1);
                    if val.len() > 0 {
                        val.rotate_left(1);
                    }
                }
                val.reverse();
            }
        }
        a.iter_mut().for_each(|a| *a *= -1);
    }
    println!("{}", ans);
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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