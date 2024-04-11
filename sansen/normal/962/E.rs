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

fn run() {
    input! {
        n: usize,
        p: [(i64, chars); n],
    }
    let p: Vec<_> = p.into_iter().map(|p| (p.0, p.1[0])).collect();
    let mut a = vec![];
    let mut b = vec![];
    let mut c = vec![];
    for &(x, p) in p.iter() {
        match p {
            'B' => {
                a.push(x);
            }
            'R' => {
                b.push(x);
            }
            _ => {
                c.push(x);
            }
        }
    }
    if c.is_empty() {
        let mut ans = 0;
        if a.len() > 0 {
            ans += *a.last().unwrap() - a[0];
        }
        if b.len() > 0 {
            ans += *b.last().unwrap() - b[0];
        }
        println!("{}", ans);
        return;
    }
    let mut ans = 0;
    let x = *c.last().unwrap();
    for a in [&mut a, &mut b].iter_mut() {
        if let Some(&v) = a.last() {
            if v >= x {
                ans += v - x;
                while let Some(&v) = a.last() {
                    if v >= x {
                        a.pop();
                    } else {
                        break;
                    }
                }
            }
        }
    }
    let x = c[0];
    for a in [&mut a, &mut b].iter_mut() {
        if a.len() == 0 {
            continue;
        }
        let v = a[0];
        if v < x {
            ans += x - v;
            let mut s = 0;
            while s < a.len() && a[s] < x {
                s += 1;
            }
            a.rotate_left(s);
            for _ in 0..s {
                a.pop();
            }
        }
    }
    for c in c.windows(2).rev() {
        let mut p = vec![];
        let mut q = vec![];
        while let Some(&v) = a.last() {
            if c[0] < v && v < c[1] {
                p.push(v);
                a.pop();
            } else {
                break;
            }
        }
        while let Some(&v) = b.last() {
            if c[0] < v && v < c[1] {
                q.push(v);
                b.pop();
            } else {
                break;
            }
        }
        p.push(c[0]);
        p.reverse();
        p.push(c[1]);
        q.push(c[0]);
        q.reverse();
        q.push(c[1]);
        let mut sum = c[1] - c[0];
        for p in [&p, &q].iter() {
            let mut v = 0;
            for p in p.windows(2) {
                v = std::cmp::max(v, p[1] - p[0]);
            }
            sum += c[1] - c[0] - v;
        }
        ans += std::cmp::min(sum, 2 * (c[1] - c[0]));
    }
    println!("{}", ans);
}

fn main() {
    run();
}