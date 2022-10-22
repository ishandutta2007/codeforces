// ---------- begin super slice ----------
pub trait SuperSlice {
    type Item;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn lower_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn lower_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn upper_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn upper_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
}

impl<T> SuperSlice for [T] {
    type Item = T;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.lower_bound_by(|p| p.cmp(key))
    }
    fn lower_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Greater))
            .unwrap_err()
    }
    fn lower_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.lower_bound_by(|p| f(p).cmp(key))
    }
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.upper_bound_by(|p| p.cmp(key))
    }
    fn upper_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Less))
            .unwrap_err()
    }
    fn upper_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.upper_bound_by(|p| f(p).cmp(key))
    }
}
// ---------- end super slice ----------
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
        n: usize,
        a: [i64; n],
        b: [i64; n],
        q: usize,
        ask: [i64; q],
    }
    let mut a = a;
    a.insert(0, 0);
    let mut b = b;
    b.insert(0, 0);
    let mut cost = vec![(0, 0); n + 1];
    cost[1] = (-a[1], 1i64);
    let mut geta = 0;
    let mut plus = vec![];
    let mut minus = vec![];
    for i in 1..=n {
        let mut c = cost[i];
        if i > 1 {
            c.0 += b[i] - a[i];
        }
        assert!(c.1.abs() <= 1);
        if c.1 == 0 {
            geta += c.0.abs();
        } else if c.1 > 0 {
            plus.push(c.0);
        } else {
            minus.push(c.0);
        }
        for j in 2..=(n / i) {
            cost[j * i].0 -= c.0;
            cost[j * i].1 -= c.1;
        }
    }
    plus.sort();
    minus.sort();
    let mut a = vec![0; plus.len() + 1];
    for i in 0..plus.len() {
        a[i + 1] = a[i] + plus[i];
    }
    let mut b = vec![0; minus.len() + 1];
    for i in 0..minus.len() {
        b[i + 1] = b[i] + minus[i];
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for x in ask {
        let mut ans = geta;
        /*
        for p in plus.iter() {
            ans += (x + *p).abs();
        }
        for p in minus.iter() {
            ans += (-x + *p).abs();
        }
        */
        let p = plus.lower_bound(&-x);
        let q = p as i64;
        ans -= q * x + a[p];
        ans += (plus.len() - p) as i64 * x + a[plus.len()] - a[p];
        let p = minus.lower_bound(&x);
        let q = p as i64;
        ans -= q * -x + b[p];
        ans += (minus.len() - p) as i64 * -x + b[minus.len()] - b[p];
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}