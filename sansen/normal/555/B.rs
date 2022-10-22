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

// X L_{i + 1} - R_i <= X <= R_{i + 1} - L_i
// 
// 

fn run() {
    input! {
        n: usize,
        m: usize,
        p: [(i64, i64); n],
        a: [i64; m],
    }
    let mut e = vec![];
    for (i, p) in p.windows(2).enumerate() {
        e.push((p[1].1 - p[0].0, 1, i));
    }
    for (i, a) in a.iter().enumerate() {
        e.push((*a, 0, i));
    }
    e.sort();
    let mut set = std::collections::BTreeSet::new();
    let mut ans = vec![0; n - 1];
    for (v, op, k) in e {
        if op == 0 {
            set.insert((v, k));
        } else {
            let y = p[k + 1].0 - p[k].1;
            if let Some(&v) = set.range((y, 0)..).next() {
                set.remove(&v);
                ans[k] = v.1 + 1;
            } else {
                println!("No");
                return;
            }
        }
    }
    println!("Yes");
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}