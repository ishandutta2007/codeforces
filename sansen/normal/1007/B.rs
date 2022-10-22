// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: u64, b: u64) -> u64 {
    if a == 0 || b == 0 {
        return a + b;
    }
    let x = a.trailing_zeros();
    let y = b.trailing_zeros();
    let mut a = a >> x;
    let mut b = b >> y;
    while a != b {
        let x = (a ^ b).trailing_zeros();
        if a < b {
            std::mem::swap(&mut a, &mut b);
        }
        a = (a - b) >> x;
    }
    a << x.min(y)
}
// ---------- end binary_gcd ----------
// ---------- begin bitwise transform ----------
fn bitwise_transform<T, F>(a: &mut [T], mut f: F)
where
    F: FnMut(&mut T, &mut T),
{
    let n = a.len().trailing_zeros() as usize;
    assert!(a.len() == 1 << n);
    for i in 0..n {
        for a in a.chunks_exact_mut(2 << i) {
            let (x, y) = a.split_at_mut(1 << i);
            for (x, y) in x.iter_mut().zip(y) {
                f(x, y);
            }
        }
    }
}
// ---------- end bitwise transform ----------
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
    input! {
        t: usize,
        ask: [(usize, usize, usize); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let m = 100000;
    let mut d = vec![0u64; m + 1];
    for i in 1..=m {
        for j in 1..=(m / i) {
            d[j * i] += 1;
        }
    }
    let mut cond: Vec<Box<dyn Fn(&[u64; 8]) -> u64>> = vec![];
    for i in 1usize..8 {
        for j in 1..=i {
            for k in 1..=j {
                let mut ok = true;
                for x in 1..8 {
                    let mut c = 0;
                    for a in [i, j, k].iter() {
                        if x & *a != 0 {
                            c += 1;
                        }
                    }
                    ok &= x.count_ones() <= c;
                }
                if ok {
                    if i == k {
                        cond.push(Box::new(move |a| {
                            let a = a[i];
                            a * (a + 1) * (a + 2) / 6
                        }));
                    } else if i == j {
                        cond.push(Box::new(move |a| {
                            let (a, b) = (a[i], a[k]);
                            a * (a + 1) / 2 * b
                        }));
                    } else if j == k {
                        cond.push(Box::new(move |a| {
                            let (a, b) = (a[j], a[i]);
                            a * (a + 1) / 2 * b
                        }));
                    } else {
                        cond.push(Box::new(move |a| {
                            let (a, b, c) = (a[i], a[j], a[k]);
                            a * b * c
                        }));
                    }
                }
            }
        }
    }
    for (a, b, c) in ask {
        let a = [a, b, c];
        let mut cnt = [0; 8];
        for (i, c) in cnt.iter_mut().enumerate() {
            let mut x = 0;
            for (j, a) in a.iter().enumerate() {
                if i >> j & 1 == 1 {
                    x = binary_gcd(x as u64, *a as u64) as usize;
                }
            }
            *c += d[x];
        }
        bitwise_transform(&mut cnt, |a, b| *a -= *b);
        cnt[0] = 0;
        let ans = cond.iter().fold(0, |s, c| s + c(&cnt));
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}