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

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

use std::cmp::*;

// 2^8 = 256
//
// 
// 
// 
// x, y, z 
// 
// 
// ...
// 

const MASK: usize = (1 << 8) - 1;

fn exp(s: &[u8], k: &mut usize) -> usize {
    let mut res = term(s, k);
    while *k < s.len() && s[*k] == b'|' {
        *k += 1;
        res |= term(s, k);
    }
    res
}

fn term(s: &[u8], k: &mut usize) -> usize {
    let mut res = factor(s, k);
    while *k < s.len() && s[*k] == b'&' {
        *k += 1;
        res &= factor(s, k);
    }
    res
}

fn factor(s: &[u8], k: &mut usize) -> usize {
    let c = s[*k];
    *k += 1;
    if c == b'!' {
        let x = factor(s, k);
        !x & MASK
    } else if c == b'(' {
        let x = exp(s, k);
        assert!(s[*k] == b')');
        *k += 1;
        x
    } else {
        assert!(b'x' <= c && c <= b'z');
        let p = 2 - (c - b'x') as usize;
        let mut res = 0;
        for i in 0..8 {
            res |= ((i >> p) & 1) << i;
        }
        res
    }
}

fn run() {
    /*
        let mut h = BinaryHeap::new();
        let mut ans = vec![(100000, vec![]); 1 << 8];
        for c in "xyz".bytes() {
            let s = vec![c];
            h.push(Reverse((s.len(), s)));
        }
        let part = [("", ""), ("(", ")"), ("!", ""), ("!(", ")")];
        while let Some(Reverse((len, s))) = h.pop() {
            let mut k = 0;
            let pos = exp(&s, &mut k);
            if k < s.len() || !ans[pos].chmin((len, s.clone())) {
                continue;
            }
            for p in part.iter() {
                let mut t = vec![];
                t.extend(p.0.bytes());
                t.extend(s.iter());
                t.extend(p.1.bytes());
                h.push(Reverse((t.len(), t)));
            }
            for &(_, ref a) in ans.iter() {
                if a.is_empty() {
                    continue;
                }
                for op in "&|".bytes() {
                    for (a, s) in [(a, &s), (&s, a)].iter() {
                        for p in part.iter() {
                            for q in part.iter() {
                                let mut t = vec![];
                                t.extend(p.0.bytes());
                                t.extend(a.iter());
                                t.extend(p.1.bytes());
                                t.push(op);
                                t.extend(q.0.bytes());
                                t.extend(s.iter());
                                t.extend(q.1.bytes());
                                h.push(Reverse((t.len(), t)));
                            }
                        }
                    }
                }
            }
        }
        for ans in ans.iter() {
            let ans = ans.1.iter().map(|s| *s as char).collect::<String>();
            println!("\"{}\",", ans);
    //        println!("{}", ans);
        }
        */
    let ans = vec![
        "!x&x",
        "!(x|y|z)",
        "!x&!y&z",
        "!x&!y",
        "!x&!z&y",
        "!x&!z",
        "!(!y&!z|x|y&z)",
        "!(x|y&z)",
        "!x&y&z",
        "!(!y&z|!z&y|x)",
        "!x&z",
        "!(!z&y|x)",
        "!x&y",
        "!(!y&z|x)",
        "!x&(y|z)",
        "!x",
        "!y&!z&x",
        "!y&!z",
        "!(!x&!z|x&z|y)",
        "!(x&z|y)",
        "!(!x&!y|x&y|z)",
        "!(x&y|z)",
        "!(!x&!y|x&y|z)|!x&!y&z",
        "!((x|y)&z|x&y)",
        "!x&y&z|!y&!z&x",
        "!x&y&z|!y&!z",
        "!x&z|!y&!z&x",
        "!x&z|!y&!z",
        "!x&y|!y&!z&x",
        "!x&y|!y&!z",
        "!x&(y|z)|!y&!z&x",
        "!x|!y&!z",
        "!y&x&z",
        "!(!x&z|!z&x|y)",
        "!y&z",
        "!(!z&x|y)",
        "!x&!z&y|!y&x&z",
        "!x&!z|!y&x&z",
        "!x&!z&y|!y&z",
        "!x&!z|!y&z",
        "!x&y&z|!y&x&z",
        "!(!x&z|!z&x|y)|!x&y&z",
        "!(x&y)&z",
        "!(!z&x|y)|!x&z",
        "!x&y|!y&x&z",
        "!(!y&z|x)|!y&x&z",
        "!x&y|!y&z",
        "!x|!y&z",
        "!y&x",
        "!(!x&z|y)",
        "!y&(x|z)",
        "!y",
        "!x&!z&y|!y&x",
        "!x&!z|!y&x",
        "!x&!z&y|!y&(x|z)",
        "!x&!z|!y",
        "!x&y&z|!y&x",
        "!(!x&z|y)|!x&y&z",
        "!x&z|!y&x",
        "!x&z|!y",
        "!x&y|!y&x",
        "!(!x&!y&z|x&y)",
        "!x&(y|z)|!y&x",
        "!x|!y",
        "!z&x&y",
        "!(!x&y|!y&x|z)",
        "!x&!y&z|!z&x&y",
        "!x&!y|!z&x&y",
        "!z&y",
        "!(!y&x|z)",
        "!x&!y&z|!z&y",
        "!x&!y|!z&y",
        "!x&y&z|!z&x&y",
        "!(!x&y|!y&x|z)|!x&y&z",
        "!x&z|!z&x&y",
        "!(!z&y|x)|!z&x&y",
        "!(x&z)&y",
        "!(!y&x|z)|!x&y",
        "!x&z|!z&y",
        "!x|!z&y",
        "!z&x",
        "!(!x&y|z)",
        "!x&!y&z|!z&x",
        "!x&!y|!z&x",
        "!z&(x|y)",
        "!z",
        "!x&!y&z|!z&(x|y)",
        "!x&!y|!z",
        "!x&y&z|!z&x",
        "!(!x&y|z)|!x&y&z",
        "!x&z|!z&x",
        "!(!x&!z&y|x&z)",
        "!x&y|!z&x",
        "!x&y|!z",
        "!x&(y|z)|!z&x",
        "!x|!z",
        "!y&x&z|!z&x&y",
        "!(!x&y|!y&x|z)|!y&x&z",
        "!y&z|!z&x&y",
        "!(!z&x|y)|!z&x&y",
        "!y&x&z|!z&y",
        "!(!y&x|z)|!y&x&z",
        "!y&z|!z&y",
        "!(!y&!z&x|y&z)",
        "!x&y&z|!y&x&z|!z&x&y",
        "!(!x&y|!y&x|z)|!x&y&z|!y&x&z",
        "!(x&y)&z|!z&x&y",
        "!(!z&x|y)|!x&z|!z&x&y",
        "!(x&z)&y|!y&x&z",
        "!(!y&x|z)|!x&y|!y&x&z",
        "!(x&y)&z|!z&y",
        "!x|!y&z|!z&y",
        "!(y&z)&x",
        "!(!x&y|z)|!y&x",
        "!y&z|!z&x",
        "!y|!z&x",
        "!y&x|!z&y",
        "!y&x|!z",
        "!y&(x|z)|!z&y",
        "!y|!z",
        "!(y&z)&x|!x&y&z",
        "!(!x&y|z)|!x&y&z|!y&x",
        "!(x&y)&z|!z&x",
        "!x&z|!y|!z&x",
        "!(x&z)&y|!y&x",
        "!x&y|!y&x|!z",
        "!x&y|!y&z|!z&x",
        "!(x&y&z)",
        "x&y&z",
        "!(x|y|z)|x&y&z",
        "!x&!y&z|x&y&z",
        "!x&!y|x&y&z",
        "!x&!z&y|x&y&z",
        "!x&!z|x&y&z",
        "!(!y&!z|x|y&z)|x&y&z",
        "!(x|y&z)|x&y&z",
        "y&z",
        "!(x|y|z)|y&z",
        "!x&z|y&z",
        "!x&!y|y&z",
        "!x&y|y&z",
        "!x&!z|y&z",
        "!x&(y|z)|y&z",
        "!x|y&z",
        "!y&!z&x|x&y&z",
        "!y&!z|x&y&z",
        "!(!x&!z|x&z|y)|x&y&z",
        "!(x&z|y)|x&y&z",
        "!(!x&!y|x&y|z)|x&y&z",
        "!(x&y|z)|x&y&z",
        "!(!x&!y|x&y|z)|!x&!y&z|x&y&z",
        "!((x|y)&z|x&y)|x&y&z",
        "!y&!z&x|y&z",
        "!y&!z|y&z",
        "!x&z|!y&!z&x|y&z",
        "!(x&z|y)|y&z",
        "!x&y|!y&!z&x|y&z",
        "!(x&y|z)|y&z",
        "!x&(y|z)|!y&!z&x|y&z",
        "!x|!y&!z|y&z",
        "x&z",
        "!(x|y|z)|x&z",
        "!y&z|x&z",
        "!x&!y|x&z",
        "!x&!z&y|x&z",
        "!x&!z|x&z",
        "!x&!z&y|!y&z|x&z",
        "!(x|y&z)|x&z",
        "(x|y)&z",
        "!(x|y|z)|(x|y)&z",
        "z",
        "!x&!y|z",
        "!x&y|x&z",
        "!(!y&z|x)|x&z",
        "!x&y|z",
        "!x|z",
        "!y&x|x&z",
        "!y&!z|x&z",
        "!y&(x|z)|x&z",
        "!y|x&z",
        "!x&!z&y|!y&x|x&z",
        "!(x&y|z)|x&z",
        "!x&!z&y|!y&(x|z)|x&z",
        "!x&!z|!y|x&z",
        "!y&x|y&z",
        "!(!x&z|y)|y&z",
        "!y&x|z",
        "!y|z",
        "!x&y|!y&x|x&z",
        "!x&!z|!y&x|y&z",
        "!x&y|!y&x|z",
        "!x|!y|z",
        "x&y",
        "!(x|y|z)|x&y",
        "!x&!y&z|x&y",
        "!x&!y|x&y",
        "!z&y|x&y",
        "!x&!z|x&y",
        "!x&!y&z|!z&y|x&y",
        "!(x|y&z)|x&y",
        "(x|z)&y",
        "!(x|y|z)|(x|z)&y",
        "!x&z|x&y",
        "!(!z&y|x)|x&y",
        "y",
        "!x&!z|y",
        "!x&z|y",
        "!x|y",
        "!z&x|x&y",
        "!y&!z|x&y",
        "!x&!y&z|!z&x|x&y",
        "!(x&z|y)|x&y",
        "!z&(x|y)|x&y",
        "!z|x&y",
        "!x&!y&z|!z&(x|y)|x&y",
        "!x&!y|!z|x&y",
        "!z&x|y&z",
        "!(!x&y|z)|y&z",
        "!x&z|!z&x|x&y",
        "!x&!y|!z&x|y&z",
        "!z&x|y",
        "!z|y",
        "!x&z|!z&x|y",
        "!x|!z|y",
        "(y|z)&x",
        "!(x|y|z)|(y|z)&x",
        "!y&z|x&y",
        "!(!z&x|y)|x&y",
        "!z&y|x&z",
        "!(!y&x|z)|x&z",
        "!y&z|!z&y|x&y",
        "!x&!y|!z&y|x&z",
        "(x|y)&z|x&y",
        "!(x|y|z)|(x|y)&z|x&y",
        "x&y|z",
        "!x&!y|x&y|z",
        "x&z|y",
        "!x&!z|x&z|y",
        "y|z",
        "!x|y|z",
        "x",
        "!y&!z|x",
        "!y&z|x",
        "!y|x",
        "!z&y|x",
        "!z|x",
        "!y&z|!z&y|x",
        "!y|!z|x",
        "x|y&z",
        "!y&!z|x|y&z",
        "x|z",
        "!y|x|z",
        "x|y",
        "!z|x|y",
        "x|y|z",
        "!x|x",
    ];
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        s: [String; n],
    }
    for s in s {
        let mut x = 0;
        for s in s.bytes().rev() {
            x = 2 * x + (s - b'0') as usize;
        }
        let ans = ans[x].bytes().map(|s| s as char).collect::<String>();
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}