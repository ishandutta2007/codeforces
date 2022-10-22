// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: u64, b: u64) -> u64 {
    if a == 0 || b == 0 {
        return a + b;
    }
    let x = a.trailing_zeros();
    let y = b.trailing_zeros();
    let mut a = a >> x;
    let mut b = b >> y;
    while a != b {
        let x = (a ^ b).trailing_zeros();
        if a < b {
            std::mem::swap(&mut a, &mut b);
        }
        a = (a - b) >> x;
    }
    a << x.min(y)
}
// ---------- end binary_gcd ----------
// (-inf, x] * (-inf, y] 
// 
// ---------- begin rectangle sum ----------
pub struct RectangleSum<Index, Weight> {
    point: Vec<(Index, Index)>,
    row: Vec<Index>,
    col: Vec<Vec<Index>>,
    bit: Vec<Vec<Weight>>,
    zero: Weight,
}

impl<Index, Weight> RectangleSum<Index, Weight>
where
    Index: Ord + Copy,
    Weight: std::ops::Add<Output = Weight> + Copy,
{
    pub fn new(zero: Weight) -> Self {
        RectangleSum {
            point: vec![],
            row: vec![],
            col: vec![],
            bit: vec![],
            zero: zero,
        }
    }
    pub fn add_point(&mut self, x: Index, y: Index) {
        self.point.push((x, y));
    }
    pub fn build(&mut self) {
        let mut row: Vec<_> = self.point.iter().map(|p| p.0).collect();
        row.sort();
        row.dedup();
        let mut col = vec![vec![]; row.len() + 1];
        for &(x, y) in self.point.iter() {
            let mut k = row.binary_search(&x).unwrap() + 1;
            while let Some(a) = col.get_mut(k) {
                a.push(y);
                k += k & (!k + 1);
            }
        }
        let mut bit = vec![vec![]; row.len() + 1];
        for (bit, col) in bit.iter_mut().zip(col.iter_mut()).skip(1) {
            col.sort();
            col.dedup();
            bit.resize(col.len() + 1, self.zero);
        }
        self.row = row;
        self.col = col;
        self.bit = bit;
    }
    pub fn add(&mut self, x: Index, y: Index, w: Weight) {
        let mut x = self.row.binary_search(&x).unwrap() + 1;
        while let Some(bit) = self.bit.get_mut(x) {
            let mut y = self.col[x].binary_search(&y).unwrap() + 1;
            while let Some(v) = bit.get_mut(y) {
                *v = *v + w;
                y += y & (!y + 1);
            }
            x += x & (!x + 1);
        }
    }
    // (-inf, x] * (-inf * y] 
    pub fn find(&self, x: Index, y: Index) -> Weight {
        let upper_bound = |x: &[Index], v: &Index| -> usize {
            use std::cmp::Ordering::Less;
            x.binary_search_by(|p| p.cmp(v).then(Less)).unwrap_err()
        };
        let mut x = upper_bound(&self.row, &x);
        let mut ans = self.zero;
        while x > 0 {
            let mut y = upper_bound(&self.col[x], &y);
            let bit = &self.bit[x];
            while y > 0 {
                ans = ans + bit[y];
                y -= y & (!y + 1);
            }
            x -= x & (!x + 1);
        }
        ans
    }
}
// ---------- end rectangle sum ----------
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

type Map<K, V> = std::collections::BTreeMap<K, V>;

fn run() {
    input! {
        n: usize,
        w: i64,
        point: [(i64, i64); n],
    }
    let mut time = vec![];
    let mut a = vec![];
    let mut b = vec![];
    let mut z = vec![];
    for (i, &(x, v)) in point.iter().enumerate() {
        if x > 0 {
            a.push(i);
        } else {
            b.push(i);
        }
        let x = x.abs();
        let v = v.abs();
        let a = binary_gcd(x as u64, (v - w) as u64) as i64;
        let a = (x / a, (v - w) / a);
        let b = binary_gcd(x as u64, (v + w) as u64) as i64;
        let b = (x / b, (v + w) / b);
        time.push((b, a));
        z.push(a);
        z.push(b);
    }
    let cmp = |a: &(i64, i64), b: &(i64, i64)| -> std::cmp::Ordering {
        (a.0 * b.1).cmp(&(a.1 * b.0))
    };
    z.sort_by(cmp);
    z.dedup_by(|a, b| cmp(a, b) == std::cmp::Ordering::Equal);
    let mut ans = 0;
    for p in [&a, &b].iter() {
        let mut map = Map::new();
        let mut rect = RectangleSum::new(0u64);
        for &k in p.iter() {
            let (l, r) = time[k];
            let x = z.binary_search_by(|p| cmp(p, &l)).unwrap() as i32;
            let y = z.binary_search_by(|p| cmp(p, &r)).unwrap() as i32;
            map.entry(point[k].0.abs()).or_insert(vec![]).push((x, y));
            rect.add_point(x, y);
        }
        rect.build();
        for (_, v) in map {
            for &(a, b) in v.iter() {
                ans += rect.find(z.len() as i32, b) + rect.find(a, z.len() as i32) - rect.find(a, b) - rect.find(a - 1, b - 1);
            }
            for &(a, b) in v.iter() {
                rect.add(a, b, 1);
            }
        }
    }
    let mut rect = RectangleSum::new(0u64);
    for &(l, r) in time.iter() {
        let x = z.binary_search_by(|p| cmp(p, &l)).unwrap() as i32;
        let y = z.binary_search_by(|p| cmp(p, &r)).unwrap() as i32;
        rect.add_point(x, y);
        rect.add_point(y, x);
    }
    rect.build();
    for b in b.iter() {
        let (l, r) = time[*b];
        let x = z.binary_search_by(|p| cmp(p, &l)).unwrap() as i32;
        let y = z.binary_search_by(|p| cmp(p, &r)).unwrap() as i32;
        rect.add(y, x, 1);
    }
    for a in a.iter() {
        let (l, r) = time[*a];
        let a = z.binary_search_by(|p| cmp(p, &l)).unwrap() as i32;
        let b = z.binary_search_by(|p| cmp(p, &r)).unwrap() as i32;
        ans += rect.find(z.len() as i32, b) - rect.find(a - 1, b);
    }
    println!("{}", ans);
}

fn main() {
    run();
}