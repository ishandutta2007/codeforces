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
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        q: usize,
        ask: [(u32, u32); q],
    }
    /*
    let mut set = std::collections::BTreeSet::new();
    set.insert(10);
    for _ in 0..100 {
        let v = *set.iter().next().unwrap();
        set.remove(&v);
        println!("{} {:b}", v, v);
        let mut u = v;
        while u > 0 {
            set.insert(v + u);
            u = (u - 1) & v;
        }
    }
    */
    let calc = |s: u32, t: u32| -> bool {
        if s > t {
            return false;
        }
        if s.count_ones() < t.count_ones() {
            return false;
        }
        if s.trailing_zeros() > t.trailing_zeros() {
            return false;
        }
        let mut a = vec![];
        let mut b = vec![];
        for i in 0..30 {
            if s >> i & 1 == 1 {
                a.push(i);
            }
            if t >> i & 1 == 1 {
                b.push(i);
            }
        }
        a.into_iter().zip(b).all(|p| p.0 <= p.1)
    };
    for (s, t) in ask {
        if calc(s, t) {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn main() {
    run();
}