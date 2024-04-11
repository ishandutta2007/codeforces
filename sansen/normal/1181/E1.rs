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
        a: [(usize, usize, usize, usize); n],
    }
    let a = a.into_iter().map(|a| (a.0, a.2, a.1, a.3)).collect::<Vec<_>>();
    let mut ans = "YES";
    let mut dfs = vec![a];
    while let Some(mut a) = dfs.pop() {
        if a.len() <= 1 {
            continue;
        }
        let mut split = false;
        for _ in 0..2 {
            let mut z = vec![];
            let mut p = vec![];
            for (i, a) in a.iter().enumerate() {
                z.push(a.0);
                z.push(a.1);
                p.push((a.0, a.1, i));
            }
            z.sort();
            z.dedup();
            z.remove(0);
            z.pop();
            p.sort();
            p.reverse();
            let mut left = vec![];
            let mut max = 0;
            for z in z {
                while p.last().map_or(false, |p| p.0 < z) {
                    let p = p.pop().unwrap();
                    left.push(p.2);
                    max = max.max(p.1);
                }
                if max <= z {
                    split = true;
                    let mut b = vec![];
                    let mut c = vec![];
                    for &l in left.iter() {
                        b.push(a[l]);
                    }
                    for &(_, _, r) in p.iter() {
                        c.push(a[r]);
                    }
                    dfs.push(b);
                    dfs.push(c);
                    break;
                }
            }
            if split {
                break;
            }
            for a in a.iter_mut() {
                std::mem::swap(&mut a.0, &mut a.2);
                std::mem::swap(&mut a.1, &mut a.3);
            }
        }
        if !split {
            ans = "NO";
            break;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}