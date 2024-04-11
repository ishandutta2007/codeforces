// ---------- begin multiset ----------
#[derive(Clone)]
struct MultiSet<T> {
    size: usize,
    map: std::collections::BTreeMap<T, u32>,
}

#[allow(dead_code)]
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

// Adanger 
// sum[i] >= A[i + 1] i
// ...
// 1, 2, 6, 18, 54, ...
// 
// 
// [2^k, 2^(k + 1)) 

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        q: usize,
        ask: [(bytes, u64); q],
    }
    let ask = ask.into_iter().map(|(s, x)| (s[0], x)).collect::<Vec<_>>();
    let w = 32;
    let mut sum = vec![0; w];
    let mut set = vec![MultiSet::new(); w];
    for (op, x) in ask {
        let y = (x + 1).next_power_of_two().trailing_zeros() as usize;
        if op == b'+' {
            sum[y] += x;
            set[y].insert(x);
        } else {
            sum[y] -= x;
            set[y].remove(&x);
        }
        let mut ans = 0;
        let mut pre = 0;
        for i in 0..w {
            if set[i].len() == 0 {
                continue;
            }
            ans += set[i].size - 1;
            if 2 * pre >= *set[i].map.iter().next().unwrap().0 {
                ans += 1;
            }
            pre += sum[i];
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}