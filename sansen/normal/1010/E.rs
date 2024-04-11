// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
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
    input! {
        x: i32,
        y: i32,
        z: i32,
        n: usize,
        m: usize,
        q: usize,
        inner: [[i32; 3]; n],
        outer: [[i32; 3]; m],
        query: [[i32; 3]; q],
    }
    let inf = x.max(y).max(z);
    let mut range = [(inf, 0); 3];
    for p in inner {
        for (range, p) in range.iter_mut().zip(p) {
            range.0.chmin(p);
            range.1.chmax(p);
        }
    }
    let range = range;
    let inner = |p: &[i32]| range.iter().zip(p).all(|(a, x)| a.0 <= *x && *x <= a.1);
    if outer.iter().any(|p| inner(p)) {
        println!("INCORRECT");
        return;
    }
    let mut outer = outer
        .into_iter()
        .map(|p| [p[0], p[1], p[2]])
        .collect::<Vec<_>>();
    let mut ask = vec![];
    let mut ans = vec!["UNKNOWN"; q];
    for (i, p) in query.into_iter().enumerate() {
        if inner(&p) {
            ans[i] = "OPEN";
        } else {
            ask.push(([p[0], p[1], p[2]], i));
        }
    }
    let mut range = range;
    let mut x = x;
    let mut y = y;
    for _ in 0..2 {
        for _ in 0..4 {
            #[derive(Clone, Copy, Ord, Eq, PartialEq, PartialOrd)]
            enum Event {
                QUERY(i32, i32, usize),
                ADD(i32, i32),
            }
            let mut event = vec![];
            for a in outer.iter() {
                if range.iter().zip(a.iter()).all(|(r, x)| *x <= r.1) {
                    event.push((a[2], Event::ADD(a[0], a[1])));
                }
            }
            for a in ask.iter() {
                if range.iter().zip(a.0.iter()).all(|(r, x)| *x <= r.1) {
                    event.push((a.0[2], Event::QUERY(a.0[0], a.0[1], a.1)));
                }
            }
            event.sort();
            let mut set = std::collections::BTreeSet::<(i32, i32)>::new();
            for e in event.into_iter().rev() {
                match e.1 {
                    Event::ADD(x, y) => {
                        if set.range((x, y)..).next().map_or(false, |p| y <= p.1) {
                            continue;
                        }
                        while let Some(&p) = set.range(..=(x, y)).next_back() {
                            if p.1 <= y {
                                set.remove(&p);
                            } else {
                                break;
                            }
                        }
                        set.insert((x, y));
                    }
                    Event::QUERY(x, y, k) => {
                        if set.range((x, y)..).next().map_or(false, |p| y <= p.1) {
                            ans[k] = "CLOSED";
                        }
                    }
                }
            }
            for p in outer.iter_mut() {
                *p = [p[1], x - p[0], p[2]];
            }
            for p in ask.iter_mut() {
                p.0 = [p.0[1], x - p.0[0], p.0[2]];
            }
            let a = range[0];
            let b = range[1];
            range[0] = (b.0, b.1);
            range[1] = (x - a.1, x - a.0);
            std::mem::swap(&mut x, &mut y);
        }
        range[2] = (z - range[2].1, z - range[2].0);
        for a in outer.iter_mut() {
            a[2] = z - a[2];
        }
        for a in ask.iter_mut() {
            a.0[2] = z - a.0[2];
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "CORRECT").ok();
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}