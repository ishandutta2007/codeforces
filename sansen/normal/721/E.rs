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
        _l: u32,
        n: usize,
        p: u32,
        t: u32,
        a: [(u32, u32); n],
    }
    let inf = std::u32::MAX;
    let mut max = 0;
    let mut set = std::collections::BTreeSet::<(u32, u32)>::new();
    for (l, r) in a {
        let del = set.range(..=(l, l)).cloned().collect::<Vec<_>>();
        for p in del {
            max = max.max(p.1);
            set.remove(&p);
        }
        let q = (r - l) / p;
        if q > 0 {
            let next = (l + q * p + t, max + q);
            if set
                .range(..=(next.0, inf))
                .next_back()
                .map_or(true, |p| p.1 < next.1)
            {
                let d = set
                    .range(next..)
                    .take_while(|p| p.1 <= next.1)
                    .cloned()
                    .collect::<Vec<_>>();
                for d in d {
                    set.remove(&d);
                }
                set.insert(next);
            }
        }
        let d = set.range((l, 0)..=(r, inf)).cloned().collect::<Vec<_>>();
        for (l, v) in d {
            set.remove(&(l, v));
            max = max.max(v);
            let q = (r - l) / p;
            if q > 0 {
                let next = (l + q * p + t, max + q);
                if set
                    .range(..=(next.0, inf))
                    .next_back()
                    .map_or(true, |p| p.1 < next.1)
                {
                    let d = set
                        .range(next..)
                        .take_while(|p| p.1 <= next.1)
                        .cloned()
                        .collect::<Vec<_>>();
                    for d in d {
                        set.remove(&d);
                    }
                    set.insert(next);
                }
            }
        }
    }
    for a in set {
        max = max.max(a.1);
    }
    let ans = max;
    println!("{}", ans);
}

fn main() {
    run();
}