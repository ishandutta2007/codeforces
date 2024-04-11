use std::collections::*;

type Map<K, V> = HashMap<K, V>;

fn run() {
    input! {
        n: usize,
        k: usize,
        b: [usize; n],
    }
    let mut fact = vec![0; n + 1000];
    for i in 1..fact.len() {
        let mut s = fact[i - 1];
        let mut v = i;
        while v % 2 == 0 {
            v /= 2;
            s += 1;
        }
        fact[i] = s;
    }
    let binom = |n: usize, k: usize| -> usize {
        let c = fact[n] - fact[k] - fact[n - k];
        if c == 0 {
            1
        } else {
            0
        }
    };
    let mut memo = Map::new();
    let mut calc = |n: usize, k: usize| -> usize {
        if let Some(&c) = memo.get(&(n, k)) {
            return c;
        }
        let v = (k..=n).fold(0, |s, a| s ^ binom(n, a));
        memo.insert((n, k), v);
        v
    };
    let len = 1 << 20;
    let mut ans = vec![0; len];
    for s in 0..n {
        let mut x = b[s];
        for t in (s + 1)..=n {
            if x == len {
                break;
            }
            let mut need = 0;
            if s > 0 {
                need += 1;
            }
            if t < n {
                need += 1;
            }
            let l = s.saturating_sub(1);
            let r = (n - t).saturating_sub(1);
            if calc(l + r, k.saturating_sub(need)) == 1 {
                ans[x] ^= 1;
            }
            if t < n {
                x = len.min(x << b[t].min(20));
            }
        }
    }
    while ans.last().map_or(false, |p| *p == 0) {
        ans.pop();
    }
    if ans.is_empty() {
        ans.push(0);
    }
    ans.reverse();
    use util::*;
    println!("{}", ans.iter().join(""));
}

fn main() {
    run();
}

mod util {
    pub trait Join {
        fn join(self, sep: &str) -> String;
    }

    impl<T, I> Join for I
    where
        I: Iterator<Item = T>,
        T: std::fmt::Display,
    {
        fn join(self, sep: &str) -> String {
            let mut s = String::new();
            use std::fmt::*;
            for (i, v) in self.enumerate() {
                if i > 0 {
                    write!(&mut s, "{}", sep).ok();
                }
                write!(&mut s, "{}", v).ok();
            }
            s
        }
    }
}
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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