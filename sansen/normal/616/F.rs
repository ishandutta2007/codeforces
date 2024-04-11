// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
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
// ---------- begin Suffix Array ----------
fn suffix_array<T: Ord>(s: &[T]) -> Vec<usize> {
    let n = s.len();
    let mut z = s.iter().collect::<Vec<_>>();
    z.sort();
    z.dedup();
    let mut ord = Vec::with_capacity(n);
    for s in s.iter() {
        ord.push(z.binary_search(&s).unwrap() as u32 + 1);
    }
    let mut z = (0..n).map(|p| ((ord[p], 0), p)).collect::<Vec<_>>();
    z.sort_by_key(|p| p.0);
    let mut len = 1;
    while len < n {
        for z in z.iter_mut() {
            z.0 = (ord[z.1], ord.get(z.1 + len).map_or(0, |p| *p));
        }
        z.sort_by_key(|p| p.0);
        let mut id = 1;
        let mut prev = z[0].0;
        for z in z.iter_mut() {
            if z.0 != prev {
                id += 1;
                prev = z.0;
            }
            ord[z.1] = id;
        }
        len <<= 1;
    }
    z.into_iter().map(|p| p.1).collect()
}
// ---------- end Suffix Array ----------
// ---------- begin lcp array ----------
fn lcp_array<T: Ord>(s: &[T], sa: &[usize]) -> Vec<usize> {
    let mut isa = vec![0; s.len()];
    for (i, sa) in sa.iter().enumerate() {
        isa[*sa] = i;
    }
    let mut lcp = vec![0; s.len()];
    let mut h = 0;
    for i in 0..sa.len() {
        if isa[i] + 1 < sa.len() {
            let j = sa[isa[i] + 1];
            while i.max(j) + h < sa.len() && s[i + h] == s[j + h] {
                h += 1;
            }
            lcp[isa[i] + 1] = h;
            if h > 0 {
                h -= 1;
            }
        }
    }
    lcp
}
// ---------- end lcp array ----------
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
        t: [bytes; n],
        c: [i64; n],
    }
    let mut sp = 26;
    let mut s = vec![];
    let mut cost = vec![];
    let mut len = vec![];
    for (c, t) in c.iter().zip(t) {
        for (i, a) in t.iter().enumerate() {
            cost.push(*c);
            len.push(t.len() - i);
            s.push((*a - b'a') as u32);
        }
        cost.push(0);
        len.push(0);
        s.push(sp);
        sp += 1;
    }
    let sa = suffix_array(&s);
    let lcp = lcp_array(&s, &sa);
    let mut ans = 0;
    // height, sum c
    let mut stack = vec![(0i64, 0i64)];
    for (i, &sa) in sa.iter().enumerate() {
        let mut w = 0;
        let h = lcp[i] as i64;
        while stack.last().map_or(false, |p| p.0 > h) {
            let (a, b) = stack.pop().unwrap();
            w += b;
            ans.chmax(w * a);
        }
        if stack.last().unwrap().0 == h {
            stack.last_mut().unwrap().1 += w;
        } else {
            stack.push((h, w));
        }
        let len = len[sa] as i64;
        if stack.last().unwrap().0 == len {
            stack.last_mut().unwrap().1 += cost[sa];
        } else {
            stack.push((len, cost[sa]));
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}