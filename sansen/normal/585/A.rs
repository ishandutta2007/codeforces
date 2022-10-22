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
        a: [(i64, i64, i64); n],
    }
    let mut q = std::collections::VecDeque::new();
    for (i, &(v, d, p)) in a.iter().enumerate() {
        q.push_back((v, d, p, i + 1));
    }
    let mut ans = vec![];
    while let Some((v, _d, _p, k)) = q.pop_front() {
        ans.push(k);
        let mut del = vec![];
        for i in (0..q.len()).rev() {
            let d = i as i64;
            if d > v {
                continue;
            }
            let po = q.get_mut(i).unwrap();
            po.2 -= v - d;
            if po.2 < 0 {
                del.push(q.remove(i).unwrap());
            }
        }
        while let Some((_, d, _, k)) = del.pop() {
            for i in (0..q.len()).rev() {
                let po = q.get_mut(i).unwrap();
                if po.3 < k {
                    break;
                } else {
                    po.2 -= d;
                    if po.2 < 0 {
                        del.push(q.remove(i).unwrap());
                    }
                }
            }
        }
    }
    let mut s = String::new();
    s.push_str(&format!("{}\n", ans.len()));
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}