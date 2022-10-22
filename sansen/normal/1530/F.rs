// ---------- begin bitwise transform ----------
fn bitwise_transform<T, F>(a: &mut [T], mut f: F)
where
    F: FnMut(&mut T, &mut T)
{
    let n = a.len().trailing_zeros() as usize;
    assert!(a.len() == 1 << n);
    for i in 0..n {
        for a in a.chunks_exact_mut(2 << i) {
            let (x, y) = a.split_at_mut(1 << i);
            for (x, y) in x.iter_mut().zip(y) {
                f(x, y);
            }
        }
    }
}
// ---------- end bitwise transform ----------

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
        a: [[u16; n]; n],
    }
    const MOD: u16 = 31607;
    let mul = |a: u16, b: u16| -> u16 {
        (a as u32 * b as u32 % MOD as u32) as u16
    };
    let add = |a: u16, b: u16| -> u16 {
        let mut d = a + b;
        if d >= MOD {
            d -= MOD;
        }
        d
    };
    let sub = |a: u16, b: u16| -> u16 {
        let mut d = a - b;
        if d >= MOD {
            d += MOD;
        }
        d
    };
    /*
    let mut p = vec![vec![0u16; n]; n];
    for p in p.iter_mut().flatten() {
        *p = mul((rand() % 9999 + 1) as u16, 3973);
    }
    */
    let mut p = vec![vec![0; n]; n];
    for (p, a) in p.iter_mut().zip(a) {
        for (p, a) in p.iter_mut().zip(a) {
            *p = mul(a, 3973);
        }
    }
    let table = |a: &[u16]| -> Vec<u16> {
        let mut p = vec![1u16];
        for &a in a.iter() {
            for i in 0..p.len() {
                let v = p[i];
                p.push(mul(v, a));
                p[i] = mul(v, MOD + 1 - a);
            }
        }
        p
    };
    let mut ans = 0;
    let mut prod = 1;
    let mut dp = vec![1; 1 << (n + 2)];
    for (i, p) in p.iter().enumerate() {
        let mut table = table(p);
        ans = add(ans, mul(prod, table[(1 << n) - 1]));
        prod = mul(prod, 1 + MOD - table[(1 << n) - 1]);
        table[(1 << n) - 1] = 0;
        let mut c = vec![0; 1 << (n + 2)];
        for (j, table) in table.into_iter().enumerate() {
            let mut j = j;
            if j >> i & 1 == 1 {
                j |= 1 << n;
            }
            if j >> (n - 1 - i) & 1 == 1 {
                j |= 1 << (n + 1);
            }
            c[j] = table;
        }
        bitwise_transform(&mut c, |a, b| *a = add(*a, *b));
        for (dp, c) in dp.iter_mut().zip(c) {
            *dp = mul(*dp, c);
        }
    }
    bitwise_transform(&mut dp, |a, b| *a = sub(*a, *b));
    let ans = dp[1..].iter().fold(ans, |s, a| add(s, *a));
    println!("{}", ans);
}

fn main() {
    run();
}