//---------- begin SegmentTree Range update Point query ----------
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
//---------- end SegmentTree Range update Point query ----------
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

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        q: usize,
        a: [usize; n],
    }
    let mut l = vec![n; q + 1];
    let mut r = vec![0; q + 1];
    for i in 0..n {
        l[a[i]] = std::cmp::min(l[a[i]], i);
        r[a[i]] = i;
    }
    let mut s = segment_tree::RUPQ::new(n, 0, |a, b| if b == 0 {a} else {b});
    for i in 1..=q {
        if l[i] <= r[i] {
            s.update(l[i], r[i] + 1, i);
        }
    }
    let mut b = vec![0; n];
    for i in 0..n {
        b[i] = s.find(i);
    }
    if !b.contains(&q) && !a.contains(&0) {
        writeln!(out, "NO").unwrap();
        return;
    }
    for i in 0..n {
        if a[i] > 0 && b[i] > a[i] {
            writeln!(out, "NO").unwrap();
            return;
        }
    }
    if !b.contains(&q) {
        for i in 0..n {
            if a[i] == 0 {
                b[i] = q;
                break;
            }
        }
    }
    for i in 1..n {
        if b[i] == 0 {
            b[i] = b[i - 1];
        }
    }
    for i in (1..n).rev() {
        if b[i - 1] == 0 {
            b[i - 1] = b[i];
        }
    }
    writeln!(out, "YES").unwrap();
    for i in 0..n {
        if i > 0 {
            write!(out, " ").unwrap();
        }
        write!(out, "{}", b[i]).unwrap();
    }
    writeln!(out, "").unwrap();
}

fn main() {
    run();
}