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
        n: u32,
        m: u32,
        q: usize,
        p: [(u32, u32); q],
    }
    let mut p = p;
    p.sort();
    let mut ans = 0;
    let mut state = vec![(1, 1)];
    while state[0] != (n, m) {
        ans += 1;
        let mut next = vec![];
        for (a, b) in state {
            let mut s = a + b;
            if p.binary_search(&(a, b)).is_ok() {
                s += 1;
            }
            next.push((s.min(n), b));
            next.push((a, s.min(m)));
        }
        state = next;
        state.sort_by_key(|p| p.0);
        state.dedup_by(|a, b| {
            a.0 == b.0 && {
                b.1 = a.1.max(b.1);
                true
            }
        });
        state.reverse();
        state.dedup_by(|a, b| a.1 <= b.1);
        state.sort_by_key(|p| p.1);
        state.dedup_by(|a, b| {
            a.1 == b.1 && {
                b.0 = a.0.max(b.0);
                true
            }
        });
        state.reverse();
        state.dedup_by(|a, b| a.0 <= b.0);
    }
    println!("{}", ans);
}

fn main() {
    run();
}