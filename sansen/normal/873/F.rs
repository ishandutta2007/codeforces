// O(N (log N)^2)
// 
// O(N log N) log2
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
        s: bytes,
        t: bytes,
    }
    let mut s = s;
    let mut t = t;
    s.reverse();
    t.reverse();
    s.push(b'z' + 1);
    t.push(b'1');
    let sa = suffix_array(&s);
    let lcp = lcp_array(&s, &sa);
    let mut ans = 0u64;
    let mut stack = vec![(0u64, 0u64)];
    for (sa, lcp) in sa.iter().zip(&lcp) {
        let h = *lcp as u64;
        let mut w = 0;
        while stack.last().map_or(false, |p| p.0 > h) {
            let (a, b) = stack.pop().unwrap();
            w += b;
            ans = ans.max(a * w);
        }
        stack.push((h, w));
        if t[*sa] == b'0' {
            stack.push(((n - *sa) as u64, 1));
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}