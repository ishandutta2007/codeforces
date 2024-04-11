// ---------- begin multiset ----------
struct MultiSet<T> {
    size: usize,
    map: std::collections::BTreeMap<T, u32>,
}

impl<T> MultiSet<T> where T: Ord {
    fn new() -> Self {
        MultiSet {
            size: 0,
            map: std::collections::BTreeMap::new(),
        }
    }
    fn len(&self) -> usize {
        self.map.len()
    }
    fn insert(&mut self, val: T) {
        self.size += 1;
        *self.map.entry(val).or_insert(0) += 1;
    }
    fn remove(&mut self, val: &T) {
        assert!(self.map.contains_key(val));
        let cnt = self.map.get_mut(val).unwrap();
        *cnt -= 1;
        self.size -= 1;
        if *cnt == 0 {
            self.map.remove(val);
        }
    }
}
// ---------- end multiset ----------
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
        y: i64,
        x: i64,
        n: usize,
        ask: [(bytes, i64); n],
    }
    let mut h = std::collections::BTreeSet::new();
    let mut w = std::collections::BTreeSet::new();
    h.insert(0);
    h.insert(x);
    w.insert(0);
    w.insert(y);
    let mut a = MultiSet::new();
    let mut b = MultiSet::new();
    a.insert(x);
    b.insert(y);
    for (s, x) in ask {
        {
            let (set, ans) = if s[0] == b'H' {
                (&mut h, &mut a)
            } else {
                (&mut w, &mut b)
            };
            let l = *set.range(..x).rev().next().unwrap();
            let r = *set.range(x..).next().unwrap();
            ans.remove(&(r - l));
            ans.insert(r - x);
            ans.insert(x - l);
            set.insert(x);
        }
        let ans = a.map.iter().rev().next().unwrap().0 * b.map.iter().rev().next().unwrap().0;
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}