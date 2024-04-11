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
        p: [(u32, u32); n],
        m: usize,
        q: [(u32, u32, usize); m],
    }
    let mut e = vec![];
    for (i, &(a, _)) in p.iter().enumerate() {
        e.push((a, 1, i));
    }
    for (i, &(c, _, _)) in q.iter().enumerate() {
        e.push((c, 0, i));
    }
    e.sort();
    let mut ans = vec![None; n];
    let mut set = std::collections::BTreeSet::new();
    for &(_, op, k) in e.iter().rev() {
        if op == 1 {
            let b = p[k].1;
            set.insert((b, k));
        } else {
            let (_, d, cnt) = q[k];
            let del = set.range(..=(d, n + m)).rev().cloned().take(cnt).collect::<Vec<_>>();
            for p in del {
                set.remove(&p);
                ans[p.1] = Some(k);
            }
        }
    }
    if ans.iter().any(|a| a.is_none()) {
        println!("NO");
    } else {
        println!("YES");
        let mut s = String::new();
        for a in ans {
            s.push_str(&format!("{} ", a.unwrap() + 1));
        }
        s.pop();
        println!("{}", s);
    }
}

fn main() {
    run();
}