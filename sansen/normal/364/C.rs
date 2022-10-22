fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> usize {
    static mut X: usize = 0;
    unsafe {
        if X == 0 {
            X = rand_memory();
        }
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}

fn shuffle<T>(a: &mut [T]) {
    for i in 1..a.len() {
        let p = rand() % (i + 1);
        a.swap(i, p);
    }
}

// ---------- begin enumerate prime ----------
fn enumerate_prime<F>(n: usize, mut f: F)
where
    F: FnMut(usize),
{
    assert!(1 <= n && n <= 5 * 10usize.pow(8));
    let batch = (n as f64).sqrt().ceil() as usize;
    let mut is_prime = vec![true; batch + 1];
    for i in (2..).take_while(|p| p * p <= batch) {
        if is_prime[i] {
            let mut j = i * i;
            while let Some(p) = is_prime.get_mut(j) {
                *p = false;
                j += i;
            }
        }
    }
    let mut prime = vec![];
    for (i, p) in is_prime.iter().enumerate().skip(2) {
        if *p && i <= n {
            f(i);
            prime.push(i);
        }
    }
    let mut l = batch + 1;
    while l <= n {
        let r = std::cmp::min(l + batch, n + 1);
        is_prime.clear();
        is_prime.resize(r - l, true);
        for &p in prime.iter() {
            let mut j = (l + p - 1) / p * p - l;
            while let Some(is_prime) = is_prime.get_mut(j) {
                *is_prime = false;
                j += p;
            }
        }
        for (i, _) in is_prime.iter().enumerate().filter(|p| *p.1) {
            f(i + l);
        }
        l += batch;
    }
}
// ---------- end enumerate prime ----------
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

fn run() {
    input! {
        k: usize,
    }
    for m in 2..=5 {
        let mut p = vec![];
        enumerate_prime(100, |a| {
            if p.len() < m {
                p.push(a);
            }
        });
        let mut a = vec![];
        let mut dfs = vec![(1, 0, 0usize)];
        while let Some((v, s, bit)) = dfs.pop() {
            if v > 2 * k * k {
                continue;
            }
            if v != 1 {
                a.push((bit, v));
            }
            for j in s..m {
                dfs.push((v * p[j], j, bit | (1 << j)));
            }
        }
        a.sort_by_key(|p| p.0.count_ones());
        let mut cnt = vec![0; m];
        let mut ans = vec![];
        let mut stack = vec![];
        for &(bit, val) in a.iter().rev() {
            let mut ok = false;
            for j in 0..m {
                if bit >> j & 1 == 1 && cnt[j] * 2 < k {
                    ok = true;
                }
            }
            if ok {
                ans.push(val);
                for j in 0..m {
                    cnt[j] += bit >> j & 1;
                }
            } else {
                stack.push(val);
            }
            if ans.len() == k {
                break;
            }
        }
        if cnt.iter().all(|c| *c * 2 >= k) && ans.len() + stack.len() >= k {
            while ans.len() < k {
                ans.push(stack.pop().unwrap());
            }
            ans.sort();
            let mut s = String::new();
            for a in ans {
                s.push_str(&format!("{} ", a));
            }
            s.pop();
            println!("{}", s);
            return;
        }
    }
}

fn main() {
    run();
}