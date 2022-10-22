// ---------- begin fenwick tree ----------
#[allow(dead_code)]
mod fenwick {
    type T = i32;
    const ZERO: T = 0;
    pub struct Tree {
        a: Vec<T>,
    }
    impl Tree {
        pub fn new(n: usize) -> Tree {
            Tree {
                a: vec![ZERO; n + 1],
            }
        }
        pub fn add(&mut self, mut x: usize, v: T) {
            while x < self.a.len() {
                self.a[x] += v;
                x += x & (!x + 1);
            }
        }
        pub fn sum(&self, mut x: usize) -> T {
            debug_assert!(x < self.a.len());
            let mut res = ZERO;
            while x > 0 {
                res += self.a[x];
                x -= x & (!x + 1);
            }
            res
        }
        pub fn search(&self, s: T) -> usize {
            debug_assert!(self.sum(self.a.len() - 1) >= s);
            let mut k = 1;
            while 2 * k < self.a.len() {
                k *= 2;
            }
            let mut x = 0;
            let mut w = ZERO;
            while k > 0 {
                if k + x < self.a.len() && w + self.a[x + k] < s {
                    w += self.a[x + k];
                    x += k;
                }
                k >>= 1;
            }
            x + 1
        }
    }
}
// ---------- end fenwick tree ----------
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

//

fn run() {
    input! {
        n: usize,
        m: usize,
        p: [i32; n],
        s: [i32; n],
        b: [i32; n],
        inc: [i32; m],
        pref: [i32; m],
    }
    let mut z = vec![std::i32::MIN];
    let mut event = vec![];
    for (i, (p, (s, b))) in p.iter().zip(s.iter().zip(b.iter())).enumerate() {
        z.push(*p - *b);
        z.push(*p + *b);
        event.push((*p, 0, i));
        event.push((*s, 2, i));
    }
    for (i, (inc, pref)) in inc.iter().zip(pref.iter()).enumerate() {
        z.push(*inc + *pref);
        z.push(*inc - *pref);
        event.push((*inc, 1, i));
    }
    z.sort();
    z.dedup();
    event.sort();
    let mut ans = vec![0; m];
    let mut add = fenwick::Tree::new(z.len() - 1);
    let mut sub = fenwick::Tree::new(z.len() - 1);
    for (_, op, k) in event {
        if op == 1 {
            let cnt = add.sum(z.len() - 1);
            ans[k] = cnt;
            let x = z.binary_search(&(inc[k] + pref[k])).unwrap();
            ans[k] -= cnt - add.sum(x);
            let x = z.binary_search(&(inc[k] - pref[k])).unwrap();
            ans[k] -= cnt - sub.sum(x);
        } else {
            let v = 1 - op;
            let x = z.binary_search(&(p[k] + b[k])).unwrap();
            add.add(x, v);
            let x = z.binary_search(&(p[k] - b[k])).unwrap();
            sub.add(x, v);
        }
    }
    let mut out = String::new();
    for a in ans {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}