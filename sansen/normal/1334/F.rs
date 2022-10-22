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
        a: [usize; n],
        p: [i64; n],
        m: usize,
        b: [usize; m],
    }
    let mut b = b;
    b.reverse();
    b.push(0);
    b.reverse();
    let sup = 500_000i64 * 1_000_000_000;
    let inf = std::i64::MAX / 2;
    let mut seg = segment_tree::RUPQ::new(m + 2, 0, |a, b| a + b);
    seg.update(1, m + 2, inf);
    for (a, p) in a.iter().zip(p.iter()) {
        match b.binary_search(a) {
            Ok(k) => {
                let v = seg.find(k - 1);
                seg.update(0, k, *p);
                seg.update(k, m + 1, std::cmp::min(*p, 0));
                let u = seg.find(k);
                if u > v {
                    seg.update(k, k + 1, -(u - v));
                }
            },
            Err(k) => {
                seg.update(0, k, *p);
                seg.update(k, m + 1, std::cmp::min(*p, 0));
            },
        }
    }
    let ans = seg.find(m);
    if ans >= sup {
        println!("NO");
    } else {
        println!("YES\n{}", ans);
    }
}

fn main() {
    run();
}