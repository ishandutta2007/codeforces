// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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

//

fn run() {
    input! {
        n: usize,
        m: usize,
        x: [i64; n],
        p: [(i64, usize); m],
    }
    let mut e = vec![];
    for x in x.iter() {
        e.push((*x, 0));
    }
    for p in p.iter() {
        e.push(*p);
    }
    e.sort_by_key(|p| p.0);
    let inf = 2_000_000_000i64 * 5000 + 1;
    let mut free = vec![inf; n + 1];
    let mut need = vec![inf; n + 1];
    free[0] = 0;
    need[0] = 0;
    let mut pre = e[0].0;
    for &(x, c) in e.iter() {
        let d = x - pre;
        for (i, f) in free.iter_mut().enumerate() {
            *f += i as i64 * d;
        }
        for (i, n) in need.iter_mut().enumerate() {
            *n += i as i64 * d;
        }
        pre = x;
        let mut next_free = vec![inf; n + 1];
        let mut next_need = vec![inf; n + 1];
        if c == 0 {
            for (next, now) in next_free.iter_mut().zip(free.iter_mut().skip(1)) {
                next.chmin(*now);
            }
            for (next, now) in next_need.iter_mut().skip(1).zip(need.iter_mut()) {
                next.chmin(*now);
            }
        } else {
            for (i, now) in free.iter().enumerate() {
                let k = std::cmp::min(n, i + c);
                next_free[k].chmin(*now);
            }
            for (i, now) in need.iter().enumerate() {
                if i >= c {
                    next_need[i - c].chmin(*now);
                } else {
                    next_need[0].chmin(*now);
                    next_free[std::cmp::min(n, c - i)].chmin(*now);
                }
            }
        }
        for i in (0..n).rev() {
            let v = next_free[i + 1];
            next_free[i].chmin(v);
        }
        let v = std::cmp::min(next_need[0], next_free[0]);
        next_free[0].chmin(v);
        next_need[0].chmin(v);
        free = next_free;
        need = next_need;
    }
    let ans = free[0];
    if ans >= inf {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}

fn main() {
    run();
}