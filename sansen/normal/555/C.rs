// ---------- begin SegmentTree Range update Point query ----------
mod segment_tree {
    pub struct RUPQ<T, F> {
        n: usize,
        b: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    impl<T: Copy, F: Fn(T, T) -> T> RUPQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> RUPQ<T, F> {
            let mut k = 0;
            while (1 << k) < n {
                k += 1;
            }
            RUPQ {
                n: 1 << k,
                b: k,
                a: vec![id; 2 << k],
                id: id,
                op: op,
            }
        }
        fn down(&mut self, x: usize) {
            let k = x + self.n;
            let a = &mut self.a;
            for i in (1..(self.b + 1)).rev() {
                let y = k >> i;
                a[2 * y] = (self.op)(a[2 * y], a[y]);
                a[2 * y + 1] = (self.op)(a[2 * y + 1], a[y]);
                a[y] = self.id;
            }
        }
        pub fn update(&mut self, mut l: usize, mut r: usize, v: T) {
            self.down(l);
            self.down(r - 1);
            l += self.n;
            r += self.n;
            let a = &mut self.a;
            while l < r {
                if (l & 1) == 1 {
                    a[l] = (self.op)(a[l], v);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    a[r] = (self.op)(a[r], v);
                }
                l >>= 1;
                r >>= 1;
            }
        }
        pub fn find(&mut self, mut x: usize) -> T {
            x += self.n;
            let mut y = self.a[x];
            x >>= 1;
            while x > 0 {
                y = (self.op)(y, self.a[x]);
                x >>= 1;
            }
            y
        }
    }
}
// ---------- end SegmentTree Range update Point query ----------
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
        n: usize,
        q: usize,
        ask: [(usize, usize, String); q],
    }
    let mut z = vec![0, n + 1];
    for p in ask.iter() {
        z.push(p.0);
        z.push(p.1);
    }
    z.sort();
    z.dedup();
    let mut row = segment_tree::RUPQ::new(z.len(), 0, |a, b| std::cmp::max(a, b));
    let mut col = segment_tree::RUPQ::new(z.len(), 0, |a, b| std::cmp::max(a, b));
    let mut used = std::collections::BTreeSet::new();
    for (x, y, op) in ask {
        if !used.insert((x, y)) {
            writeln!(out, "0").ok();
            continue;
        }
        let x = z.binary_search(&x).unwrap();
        let y = z.binary_search(&y).unwrap();
        if op == "U" {
            let ans = z[y] - col.find(x);
            writeln!(out, "{}", ans).ok();
            let k = z.binary_search_by_key(&(z[y].saturating_sub(ans), 0), |p| (*p, 1)).unwrap_err();
            row.update(k, y, z[x]);
        } else {
            let ans = z[x] - row.find(y);
            writeln!(out, "{}", ans).ok();
            let k = z.binary_search_by_key(&(z[x].saturating_sub(ans), 0), |p| (*p, 1)).unwrap_err();
            col.update(k, x, z[y]);
        }
    }
}

fn main() {
    run();
}