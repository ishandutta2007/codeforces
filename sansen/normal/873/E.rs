// ---------- begin sparse table ----------
pub struct SparseTable<T, F> {
    table: Vec<Vec<T>>,
    size: usize,
    op: F,
}

impl<T, F> SparseTable<T, F>
where
    F: Fn(&T, &T) -> T
{
    pub fn new(mut a: Vec<T>, op: F) -> Self {
        assert!(a.len() > 0);
        let size = a.len();
        let mut table = vec![];
        let mut w = 1;
        while w + 1 <= a.len() {
            let next = a.windows(w + 1).map(|a| op(&a[0], &a[w])).collect::<Vec<_>>();
            table.push(a);
            a = next;
            w <<= 1;
        }
        table.push(a);
        SparseTable {
            table: table,
            size: size,
            op: op,
        }
    }
    pub fn find(&self, l: usize, r: usize) -> T {
        assert!(l < r && r <= self.size);
        let k = (r - l + 1).next_power_of_two().trailing_zeros() as usize - 1;
        let table = &self.table[k];
        (self.op)(&table[l], &table[r - (1 << k)])
    }
}
// ---------- end sparse table ----------
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
        a: [i32; n],
    }
    let mut a = a.into_iter().enumerate().map(|p| (p.1, p.0)).collect::<Vec<_>>();
    a.push((0, n));
    a.sort();
    a.reverse();
    let b = a.windows(2).enumerate().map(|(k, a)| (a[0].0 - a[1].0, k)).collect::<Vec<_>>();
    let rmq = SparseTable::new(b.clone(), |a, b| std::cmp::max(*a, *b));
    let mut ans = (0, 0, 0, 0, 0, 0);
    for x in 0..n {
        let (d1, c1) = (b[x].0, x + 1);
        for y in (x + 1)..n {
            let (d2, c2) = (b[y].0, y - x);
            if c1 * 2 < c2 || c2 * 2 < c1 {
                continue;
            }
            let p = std::cmp::max((c1 + 1) / 2, (c2 + 1) / 2);
            let q = std::cmp::min(2 * c1, 2 * c2);
            if y + p < n {
                let v = rmq.find(y + p, n.min(y + q + 1));
                let (d3, c3) = (v.0, v.1 - y);
                let key = (d1, d2, d3, c1, c2, c3);
                if key > ans {
                    ans = key;
                }
            }
        }
    }
    let (_, _, _, x, y, z) = ans;
    let mut b = vec![];
    b.extend((0..x).map(|_| 1));
    b.extend((0..y).map(|_| 2));
    b.extend((0..z).map(|_| 3));
    let mut ans = vec![-1; n];
    for (a, b) in a.iter().zip(b) {
        ans[a.1] = b;
    }
    let s = ans.iter().map(|a| a.to_string()).collect::<Vec<_>>().join(" ");
    println!("{}", s);
}

fn main() {
    run();
}