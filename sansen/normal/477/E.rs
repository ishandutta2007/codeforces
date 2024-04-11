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
// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T, F> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(&T, &T) -> T> PURQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> PURQ<T, F> {
            let mut k = 1;
            while k < n {
                k *= 2;
            }
            PURQ {
                n: k,
                a: vec![id.clone(); 2 * k],
                id: id,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.n + x;
            let a = &mut self.a;
            a[k] = v;
            k >>= 1;
            while k > 0 {
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            let a = &mut self.a;
            for k in (1..(self.n)).rev() {
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            let a = &self.a;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(&p, &a[l]);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(&a[r], &q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(&p, &q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
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

// O(NQ) 
// HOME, END 1
// HOME
// END
// END
// ()->(END0or1)->()->()
// 
// O(NQ)
//
// 
// END
// 
// -> END
// or
// (R_1 C_1) -> (R_2, C_2)
// R_1 <= R_2, A_i 
// C_1 = min(C_1, min(A_i)(R_1 <= i <= R_2)) 
// END
// min(|A_i - C_2|) + R_2 - R_1 + 1
// (R_1 <= i <= R_2)
// 
// min(|A_i - C_2| + 2 * (R_1 - i) + (C_1 < A_i)) + R_2 - R_1
// (i <= R_2)
//
// A_i 
// 
// min(|A_i - C_2| + i - R_1 + i - R_2 + (C_1 < A_i))
//
// 
//
// R_2 
// 
// R1>R2 

fn run() {
    input! {
        n: usize,
        a: [i32; n],
        q: usize,
        ask: [(usize1, i32, usize1, i32); q],
    }
    let inf = 500_000_000i32;
    let mut ask = ask;
    let mut ans = vec![std::i32::MAX; q];
    // HOME, 
    // c1
    {
        let mut seg = segment_tree::PURQ::new(n, inf, |a, b| std::cmp::min(*a, *b));
        for (i, a) in a.iter().enumerate() {
            seg.update_tmp(i, *a);
        }
        seg.update_all();
        for (ans, p) in ans.iter_mut().zip(ask.iter_mut()) {
            let (x, y) = (p.0, p.2);
            let (l, r) = (x.min(y), x.max(y));
            p.1.chmin(seg.find(l, r + 1));
            ans.chmin((r - l) as i32 + (p.3 - p.1).abs());
            ans.chmin((r - l) as i32 + 1 + p.3);
        }
    }
    let mut query = vec![vec![]; 2];
    for (i, &(a, b, c, d)) in ask.iter().enumerate() {
        if a <= c {
            query[0].push((a, b, c, d, i));
        } else {
            query[1].push((n - 1 - a, b, n - 1 - c, d, i));
        }
    }
    let mut a = a;
    for query in query {
        {
            // 
            let mut ask = vec![vec![]; n];
            for &(l, x, r, y, k) in query.iter() {
                ask[r].push((l, x, y, k));
            }
            let mut stack: Vec<(i32, usize)> = vec![];
            let mut plus = segment_tree::PURQ::new(n, inf, |a, b| std::cmp::min(*a, *b));
            let mut minus = segment_tree::PURQ::new(n, inf, |a, b| std::cmp::min(*a, *b));
            for (i, &a) in a.iter().enumerate() {
                while stack.last().map_or(false, |p| p.0 >= a) {
                    let k = stack.pop().unwrap().1;
                    plus.update(k, inf);
                    minus.update(k, inf);
                }
                stack.push((a, i));
                plus.update(i, a - 2 * i as i32);
                minus.update(i, -a - 2 * i as i32);
                for &(l, x, y, k) in ask[i].iter() {
                    if x == y {
                        continue;
                    }
                    let m = stack.binary_search_by_key(&(l, 0), |p| (p.1, 1)).unwrap_err();
                    let (up, mid) = stack.split_at(m);
                    // 
                    if x < y {
                        let z = mid.binary_search_by_key(&(y, 0), |p| (p.0, 1)).unwrap_err();
                        mid.get(z).map(|p| ans[k].chmin(p.0 - y + (i - l) as i32 + 1));
                        mid.get(z - 1).map(|p| ans[k].chmin(y - p.0 + (i - l) as i32 + 1));
                    }
                    if up.is_empty() {
                        continue;
                    }
                    // 
                    if x < y {
                        let m = up.binary_search_by_key(&(y, 0), |p| (p.0, 1)).unwrap_err();
                        if let Some(p) = up.get(m) {
                            ans[k].chmin(plus.find(p.1, l) - y + (l + i) as i32 + 1);
                        }
                        if let Some(p) = up.get(m - 1) {
                            ans[k].chmin(minus.find(0, p.1 + 1) + y + (l + i) as i32 + 1);
                        }
                    } else {
                        let a = up.binary_search_by_key(&(x, 0), |p| (p.0, 1)).unwrap_err();
                        if a == 0 {
                            continue;
                        }
                        let b = up.binary_search_by_key(&(y, 0), |p| (p.0, 1)).unwrap_err();
                        if let Some(p) = up.get(b) {
                            ans[k].chmin(plus.find(p.1, up[a - 1].1 + 1) - y + (l + i) as i32);
                        }
                        if let Some(p) = up.get(b - 1) {
                            ans[k].chmin(minus.find(0, p.1 + 1) + y + (l + i) as i32);
                        }
                    }
                }
            }
        }
        {
            // 
            let mut ask = vec![vec![]; n];
            for &(l, x, r, y, k) in query.iter() {
                ask[r].push((x, y, (r - l) as i32, k));
            }
            let mut stack: Vec<(i32, usize)> = vec![];
            let mut plus = segment_tree::PURQ::new(n, inf, |a, b| std::cmp::min(*a, *b));
            let mut minus = segment_tree::PURQ::new(n, inf, |a, b| std::cmp::min(*a, *b));
            for (i, &a) in a.iter().enumerate().rev() {
                while stack.last().map_or(false, |p| p.0 >= a) {
                    let k = stack.pop().unwrap().1;
                    plus.update(k, inf);
                    minus.update(k, inf);
                }
                stack.push((a, i));
                plus.update(i, a + 2 * i as i32);
                minus.update(i, -a + 2 * i as i32);
                for &(x, y, geta, k) in ask[i].iter() {
                    if x == y {
                        continue;
                    }
                    if x < y {
                        let m = stack.binary_search_by_key(&(y, 0), |p| (p.0, 1)).unwrap_err();
                        stack.get(m).map(|p| ans[k].chmin(plus.find(0, p.1 + 1) - y - 2 * i as i32 + geta + 1));
                        stack.get(m - 1).map(|p| ans[k].chmin(minus.find(p.1, n) + y - 2 * i as i32 + geta + 1));
                    } else {
                        let m = stack.binary_search_by_key(&(y, 0), |p| (p.0, 1)).unwrap_err();
                        stack.get(m).map(|p| ans[k].chmin(plus.find(0, p.1 + 1) - y - 2 * i as i32 + geta));
                        stack.get(m - 1).map(|p| ans[k].chmin(minus.find(p.1, n) + y - 2 * i as i32 + geta));
                    }
                }
            }
        }
        a.reverse();
    }
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}