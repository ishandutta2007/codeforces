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

fn calc(set: &mut [std::collections::BTreeSet<usize>], root: usize, n: usize, dp: &mut [usize], fib: &[usize]) -> bool {
    if n <= 3 {
        return true;
    }
    let mut topo = vec![(root, root)];
    for i in 0.. {
        if i >= topo.len() {
            break;
        }
        let (v, p) = topo[i];
        for &u in set[v].iter() {
            if u != p {
                topo.push((u, v));
            }
        }
    }
    let x = fib.iter().position(|f| *f == n).unwrap();
    for &(v, p) in topo.iter().rev() {
        let mut s = 1;
        for &u in set[v].iter() {
            if u != p {
                s += dp[u];
            }
        }
        dp[v] = s;
        if s == fib[x - 1] || s == fib[x - 2] {
            set[v].remove(&p);
            set[p].remove(&v);
            return calc(set, v, s, dp, fib) && calc(set, p, n - s, dp, fib);
        }
    }
    false
}

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
    }
    let mut fib = vec![1; 2];
    while *fib.last().unwrap() < n {
        let i = fib.len();
        let v = fib[i - 1] + fib[i - 2];
        fib.push(v);
    }
    if n != *fib.last().unwrap() {
        println!("NO");
        return;
    }
    let mut set = vec![std::collections::BTreeSet::new(); n];
    for (a, b) in e {
        set[a].insert(b);
        set[b].insert(a);
    }
    if calc(&mut set, 0, n, &mut vec![0; n], &fib) {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    run();
}