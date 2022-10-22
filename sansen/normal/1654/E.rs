// ---------- begin Run Length Encoding ----------
fn run_length_encoding<T: Eq>(a: Vec<T>) -> Vec<(T, usize)> {
    let mut a = a.into_iter().map(|a| (a, 1)).collect::<Vec<_>>();
    a.dedup_by(|a, b| {
        a.0 == b.0 && {
            b.1 += a.1;
            true
        }
    });
    a
}
// ---------- end Run Length Encoding ----------

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
        a: [i64; n],
    }
    let small = 300;
    let len = 100000 / small + 1;
    let mut ans = 1;
    for i in 0..n {
        let mut map = std::collections::BTreeMap::new();
        for j in (i + 1)..n.min(i + len) {
            let d = (j - i) as i64;
            let v = a[j] - a[i];
            if v % d == 0 {
                *map.entry(v / d).or_insert(0) += 1;
            }
        }
        ans = ans.max(map.values().max().map_or(1, |p| *p + 1));
    }
    for d in (-(small as i64))..=(small as i64) {
        let geta = d.abs() * (n - 1) as i64;
        let mut b = vec![];
        let mut max = 0;
        for (i, a) in a.iter().enumerate() {
            let v = (geta + *a - i as i64 * d) as usize;
            max = max.max(v);
            b.push(v);
        }
        let k = ((max + 1).next_power_of_two().trailing_zeros() + 1) / 2;
        for i in 0..2 {
            let mut cnt = vec![0; 1 << k];
            for b in b.iter() {
                cnt[(*b >> (i * k)) & ((1 << k) - 1)] += 1;
            }
            for i in 1..cnt.len() {
                cnt[i] += cnt[i - 1];
            }
            let mut next = vec![0; n];
            for b in b.iter().rev() {
                let x = (*b >> (i * k)) & ((1 << k) - 1);
                cnt[x] -= 1;
                next[cnt[x]] = *b;
            }
            b = next;
        }
        let b = run_length_encoding(b);
        ans = ans.max(b.iter().map(|p| p.1).max().unwrap());
    }
    println!("{}", n - ans);
}

fn main() {
    run();
}