fn rand_memory() -> u64 {
    Box::into_raw(Box::new("I hope this is a random number")) as u64
}

fn rand() -> u64 {
    static mut X: u64 = 0;
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
        a: [usize1; n],
    }
    let mut hash = vec![0; n];
    for h in hash.iter_mut() {
        *h = rand();
    }
    let mut sum = hash.clone();
    for i in 1..n {
        sum[i] ^= sum[i - 1];
    }
    let mut elem = vec![false; n];
    let mut set = std::collections::HashSet::new();
    let mut calc = |l: &[usize], r: &[usize]| -> u64 {
        let mut v = 0;
        for r in r.iter() {
            if elem[*r] {
                break;
            }
            elem[*r] = true;
            v ^= hash[*r];
            set.insert(v);
        }
        for r in r.iter() {
            elem[*r] = false;
        }
        let mut v = 0;
        let mut max = 0;
        let mut ans = 0;
        for l in l.iter() {
            if elem[*l] {
                break;
            }
            elem[*l] = true;
            v ^= hash[*l];
            max = max.max(*l);
            if set.contains(&(sum[max] ^ v)) {
                ans += 1;
            }
        }
        for l in l.iter() {
            elem[*l] = false;
        }
        let mut v = 0;
        for r in r.iter() {
            v ^= hash[*r];
            set.remove(&v);
        }
        ans
    };
    let mut ans = 0u64;
    let mut a = a;
    let mut dfs = vec![a.as_mut_slice()];
    while let Some(a) = dfs.pop() {
        if a.len() == 1 {
            if a[0] == 0 {
                ans += 1;
            }
            continue;
        }
        let (l, r) = a.split_at_mut(a.len() / 2);
        l.reverse();
        ans += calc(l, r) + calc(r, l);
        dfs.push(l);
        dfs.push(r);
    }
    println!("{}", ans);
}

fn main() {
    run();
}