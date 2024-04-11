// ---------- begin recurse ----------
// reference
// https://twitter.com/noshi91/status/1393952665566994434
// https://twitter.com/shino16_cp/status/1393933468082397190
pub fn recurse<A, R, F>(f: F) -> impl Fn(A) -> R
where
    F: Fn(&dyn Fn(A) -> R, A) -> R,
{
    fn call<A, R, F>(f: &F, a: A) -> R
    where
        F: Fn(&dyn Fn(A) -> R, A) -> R,
    {
        f(&|a| call(f, a), a)
    }
    move |a| call(&f, a)
}
// ---------- end recurse ----------
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

use std::cell::*;

// 
// palindrome
// 
// 
// 
// 
//
// 
// good
// 11*9*7*5*3*1 * 6! 

pub struct BitOne(usize);

use std::iter::*;

impl Iterator for BitOne {
    type Item = usize;
    fn next(&mut self) -> Option<Self::Item> {
        if self.0 == 0 {
            None
        } else {
            let y = self.0.trailing_zeros() as usize;
            self.0 ^= 1 << y;
            Some(y)
        }
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        e: [(usize1, usize1); m],
    }
    let mut g = vec![0; n];
    for (a, b) in e {
        g[a] |= 1 << b;
        g[b] |= 1 << a;
    }
    let edge = |a: usize, b: usize| -> bool { g[a] >> b & 1 == 1 };
    let m = n / 2;
    let map = RefCell::new(vec![]);
    recurse(|f, (x, p): (usize, Vec<usize>)| {
        if x == p.len() {
            map.borrow_mut().push(p);
            return;
        }
        let v = *p[..=x].iter().max().unwrap() + 1;
        for i in 1..=v {
            let mut p = p.clone();
            p[x] = i;
            f((x + 1, p));
        }
    })((0, vec![0; m]));
    let cond = RefCell::new(vec![vec![]; m + 1]);
    recurse(|f, p: Vec<usize>| {
        if let Some(x) = p.iter().position(|p| *p == 0) {
            let v = *p.iter().max().unwrap() + 1;
            for i in (x + 1)..n {
                if p[i] == 0 {
                    let mut p = p.clone();
                    p[x] = v;
                    p[i] = v;
                    f(p);
                }
            }
            return;
        }
        let mut pair = vec![(n, n); m];
        for (i, p) in p.iter().enumerate() {
            let po = &mut pair[*p - 1];
            if po.0 == n {
                po.0 = i;
            } else {
                po.1 = i;
            }
        }
        let mut g = vec![0; m];
        for (i, a) in pair.iter().enumerate() {
            for (j, b) in pair[..i].iter().enumerate() {
                let mut ok = false;
                ok |= edge(a.0, b.0) && edge(a.1, b.1);
                ok |= edge(a.0, b.1) && edge(a.1, b.0);
                if ok {
                    g[i] |= 1 << j;
                    g[j] |= 1 << i;
                }
            }
        }
        let mut dp = vec![vec![false; 1 << m]; m];
        for (i, a) in pair.iter().enumerate() {
            if edge(a.0, a.1) {
                dp[i][((1 << m) - 1) ^ (1 << i)] = true;
            }
        }
        for bit in (1..(1 << m)).rev() {
            for s in 0..m {
                if dp[s][bit] {
                    for t in BitOne(g[s] & bit) {
                        dp[t][bit ^ 1 << t] |= true;
                    }
                }
            }
        }
        if dp.iter().any(|dp| dp[0]) {
            for a in map.borrow().iter() {
                let c = *a.iter().max().unwrap();
                let mut x = 0u64;
                for p in p.iter() {
                    x = 7 * x + a[*p - 1] as u64;
                }
                cond.borrow_mut()[c].push(x);
            }
        }
    })(vec![0; n]);
    let mut fact = vec![1; k + 1];
    for i in 2..=k {
        fact[i] = i as u64 * fact[i - 1];
    }
    let mut ans = 0u64;
    for (i, a) in cond.borrow_mut().iter_mut().enumerate().take(k + 1) {
        a.sort();
        a.dedup();
        ans += a.len() as u64 * fact[k] / fact[k - i];
    }
    println!("{}", ans);
}

fn main() {
    run();
}