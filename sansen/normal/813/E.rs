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

use std::io::Write;

fn run() {
    input! {
        n: usize,
        k: usize,
        a: [usize1; n],
        q: usize,
        ask: [(usize, usize); q],
    }
    let mut x = vec![vec![]; *a.iter().max().unwrap() + 1];
    for (i, a) in a.iter().enumerate() {
        x[*a].push(i);
    }
    let mut rect = RectangleSum::new(0);
    for x in x.iter() {
        for x in x.windows(k + 1) {
            let l = x[0];
            let r = x[k];
            rect.add_point(n - l, r);
        }
    }
    rect.build();
    for x in x {
        for x in x.windows(k + 1) {
            let l = x[0];
            let r = x[k];
            rect.add(n - l, r, 1);
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut last = 0;
    for (x, y) in ask {
        let mut l = (x + last) % n + 1;
        let mut r = (y + last) % n + 1;
        if l > r {
            std::mem::swap(&mut l, &mut r);
        }
        l -= 1;
        r -= 1;
        let ans = r - l + 1 - rect.find(n - l, r);
        writeln!(out, "{}", ans).ok();
        last = ans;
    }
}

fn main() {
    run();
}