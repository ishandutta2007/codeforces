fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> u64 {
    static mut X: u64 = 0;
    unsafe {
        if X == 0 {
            X = rand_memory() as u64;
        }
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
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

type Map<K, V> = std::collections::BTreeMap<K, V>;

fn run() {
    input! {
        n: usize,
        m: usize,
        p: usize,
        a: [u32; n],
        b: [u32; m],
    }
    let mut cnt = Map::new();
    let mut hash = Map::new();
    for a in a.iter().chain(&b) {
        let c = cnt.entry(*a).or_insert(0);
        hash.entry((*a, *c)).or_insert(rand());
        *c += 1;
    }
    let mut cnt = Map::new();
    let mut val = 0;
    for b in b {
        let c = cnt.entry(b).or_insert(0);
        val ^= *hash.get(&(b, *c)).unwrap();
        *c += 1;
    }
    let hash_b = val;
    let mut ans = vec![];
    for i in 0..p.min(n) {
        let mut y = vec![];
        let mut x = i;
        while x < n {
            y.push(a[x]);
            x += p;
        }
        if y.len() < m {
            continue;
        }
        let mut cnt = Map::new();
        let mut val = 0;
        for i in 0..(m - 1) {
            let b = y[i];
            let c = cnt.entry(b).or_insert(0);
            val ^= *hash.get(&(b, *c)).unwrap();
            *c += 1;
        }
        for j in (m - 1)..y.len() {
            let b = y[j];
            let c = cnt.entry(b).or_insert(0);
            val ^= *hash.get(&(b, *c)).unwrap();
            *c += 1;
            if val == hash_b {
                ans.push(i + (j - m + 1) * p);
            }
            let b = y[j - m + 1];
            let c = cnt.entry(b).or_insert(0);
            *c -= 1;
            val ^= *hash.get(&(b, *c)).unwrap();
        }
    }
    ans.sort();
    println!("{}", ans.len());
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a + 1));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}