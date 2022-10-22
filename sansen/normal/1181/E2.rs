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
        a: [(usize, usize, usize, usize); n],
    }
    let a = a
        .into_iter()
        .map(|a| (a.0, a.2, a.1, a.3))
        .collect::<Vec<_>>();
    let mut dfs = vec![a];
    while let Some(a) = dfs.pop() {
        let mut lr = std::collections::BTreeSet::new();
        let mut rl = std::collections::BTreeSet::new();
        let mut ud = std::collections::BTreeSet::new();
        let mut du = std::collections::BTreeSet::new();
        for (i, &(l, r, u, d)) in a.iter().enumerate() {
            lr.insert((l, r, i));
            rl.insert((r, l, i));
            ud.insert((u, d, i));
            du.insert((d, u, i));
        }
        while lr.len() > 1 {
            let del = {
                let it = lr.iter();
                let it = it.zip(rl.iter().rev());
                let it = it.zip(ud.iter());
                let it = it.zip(du.iter().rev());
                let mut p = (
                    lr.iter().next().unwrap().1,
                    rl.iter().rev().next().unwrap().1,
                    ud.iter().next().unwrap().1,
                    du.iter().rev().next().unwrap().1,
                );
                let mut del = vec![];
                for (i, (((x, y), z), w)) in it.enumerate() {
                    if x.0 >= p.0 {
                        for q in lr.iter().take(i) {
                            del.push(q.2);
                        }
                        break;
                    }
                    p.0.chmax(x.1);
                    if y.0 <= p.1 {
                        for q in rl.iter().rev().take(i) {
                            del.push(q.2);
                        }
                        break;
                    }
                    p.1.chmin(y.1);
                    if z.0 >= p.2 {
                        for q in ud.iter().take(i) {
                            del.push(q.2);
                        }
                        break;
                    }
                    p.2.chmax(z.1);
                    if w.0 <= p.3 {
                        for q in du.iter().rev().take(i) {
                            del.push(q.2);
                        }
                        break;
                    }
                    p.3.chmin(w.1);
                }
                del
            };
            if del.is_empty() {
                println!("NO");
                return;
            }
            let mut b = vec![];
            for i in del {
                b.push(a[i]);
                let (l, r, u, d) = a[i];
                lr.remove(&(l, r, i));
                rl.remove(&(r, l, i));
                ud.remove(&(u, d, i));
                du.remove(&(d, u, i));
            }
            dfs.push(b);
        }
    }
    println!("YES");
}

fn main() {
    run();
}