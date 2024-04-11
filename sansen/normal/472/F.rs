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

fn calc(x: &mut [u32]) -> Vec<(usize, usize)> {
    let mut ans = vec![];
    for i in 0.. {
        let mut p: Option<usize> = None;
        for (j, &v) in x.iter().enumerate().skip(i) {
            if v == 0 {
                continue;
            }
            if p.map_or(true, |p| x[p] < v) {
                p = Some(j);
            }
        }
        if p.is_none() {
            break;
        }
        let p = p.unwrap();
        if p != i {
            ans.push((i, p));
            ans.push((p, i));
            ans.push((i, p));
            x.swap(i, p);
        }
        for j in 0..i {
            if x[j] > x[j] ^ x[i] {
                ans.push((j, i));
                x[j] ^= x[i];
            }
        }
        let v = x[i];
        for (j, x) in x.iter_mut().enumerate().skip(i + 1) {
            if *x > *x ^ v {
                ans.push((j, i));
                *x ^= v;
            }
        }
    }
    ans
}

fn run() {
    input! {
        n: usize,
        a: [u32; n],
        b: [u32; n],
    }
    let mut x = a.clone();
    let mut y = b.clone();
    let mut x_op = calc(&mut x);
    let y_op = calc(&mut y);
    let mut save = vec![false; n];
    for y in y.iter() {
        if *y == 0 {
            break;
        }
        let mut y = *y;
        let mut p = vec![];
        for (i, &x) in x.iter().enumerate() {
            if x == 0 {
                break;
            }
            if y > y ^ x {
                y ^= x;
                p.push(i);
            }
        }
        if y != 0 {
            println!("-1");
            return;
        }
        let s = p[0];
        for p in p.iter().skip(1) {
            x_op.push((s, *p));
            x[s] ^= x[*p];
        }
        save[s] = true;
    }
    for (i, save) in save.iter().enumerate() {
        if x[i] != 0 && !*save {
            x_op.push((i, i));
            x[i] ^= x[i];
        }
    }
    while let Some(p) = x.windows(2).position(|x| x[0] < x[1]) {
        x_op.push((p, p + 1));
        x_op.push((p + 1, p));
        x_op.push((p, p + 1));
        x.swap(p, p + 1);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", x_op.len() + y_op.len()).ok();
    for (a, b) in x_op {
        writeln!(out, "{} {}", a + 1, b + 1).ok();
    }
    for &(a, b) in y_op.iter().rev() {
        writeln!(out, "{} {}", a + 1, b + 1).ok();
    }
}

fn main() {
    run();
}