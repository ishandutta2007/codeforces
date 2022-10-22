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

// b
// b
// b
//
// m
// (1)
//
// OK
// 
//
// 
// A X 
// (A + X) / A 
// 1 + X / A
// 1
// 2
// X, Y
// 1 + X / A
// (A + X + Y) / (A + X)
// = 1 + Y / (A + X)
//
// 
// OK
// ()
// 1
// 
// 
//
// 
// 
// k
// k or 1k-1
// k=1
// 
// 
// k
// 
// ...
// 
// 
//
// 
// k=1
//
// m
// log 
//
// 
//
// WA 147
// 
//

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        a: [u64; n],
        upgrade: [(u8, usize1, u64); m],
    }
    let mut assign = vec![None; n];
    let mut add = vec![vec![]; n];
    let mut mul = vec![];
    for (i, &(op, x, b)) in upgrade.iter().enumerate() {
        if op == 1 && b > a[x] {
            assign[x] = Some(assign[x].map_or((b, i), |p: (u64, usize)| (b, i).max(p)));
        } else if op == 2 {
            add[x].push((b, i));
        } else if op == 3 && b > 1 {
            mul.push((b, i));
        }
    }
    let mut all = vec![];
    for (b, k) in mul {
        all.push((b - 1, 1, k));
    }
    type T = (u64, u64);
    use std::cmp::*;
    let compare = |(a, b): T, (c, d): T| -> Ordering {
        let a = a as u128;
        let b = b as u128;
        let c = c as u128;
        let d = d as u128;
        ((a + b) * d).cmp(&(b * (c + d)))
    };
    for (a, (assign, add)) in a.iter().zip(assign.iter().zip(add.iter_mut())) {
        add.sort();
        add.reverse();
        if let Some((v, index)) = *assign {
            let mut val = (v - *a, *a);
            let mut used = false;
            let mut s = *a;
            for &(b, k) in add.iter() {
                if !used && compare(val, (b, s)) == Ordering::Greater {
                    all.push((val.0, val.1, index));
                    s += val.0;
                    used = true;
                }
                all.push((b, s, k));
                s += b;
                val.1 += b;
            }
            if !used {
                all.push((val.0, val.1, index));
            }
        } else {
            let mut s = *a;
            for &(b, k) in add.iter() {
                all.push((b, s, k));
                s += b;
            }
        }
    }
    all.sort_by(|a, b| compare((a.0, a.1), (b.0, b.1)));
    all.reverse();
    all.truncate(k);
    let mut ans = vec![];
    for (_, _, k) in all {
        let op = upgrade[k].0;
        if op == 1 {
            ans.push((0, k + 1));
        } else if op == 2 {
            ans.push((1, k + 1));
        } else {
            ans.push((2, k + 1));
        }
    }
    ans.sort();
    let mut s = String::new();
    s.push_str(&format!("{}\n", ans.len()));
    for a in ans {
        s.push_str(&format!("{} ", a.1));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}