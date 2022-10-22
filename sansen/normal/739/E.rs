// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        if *self > x {
            *self = x;
            true
        } else {
            false
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        if *self < x {
            *self = x;
            true
        } else {
            false
        }
    }
}
// ---------- end chmin, chmax ----------
// ---------- begin rand ----------
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
// ---------- end rand ----------
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

//

// https://qiita.com/QCFium/items/be94ff286891291584eb
// 
//
// hack
//
// 

fn test() {
    use std::env;
    let args = std::env::args().collect::<Vec<String>>();
    let n = args[1].parse::<usize>().unwrap();
    let a = args[2].parse::<usize>().unwrap();
    let b = args[3].parse::<usize>().unwrap();
    let c = args[4].parse::<usize>().unwrap();
    assert!(a <= n && b <= n && std::cmp::min(a, b) >= c && a + b - c <= n);
    let mut p = vec![];
    while p.len() < c {
        p.push((1, 1));
    }
    while p.len() < a {
        p.push((1, 0));
    }
    while p.len() < a + b - c {
        p.push((0, 1));
    }
    while p.len() < n {
        p.push((0, 0));
    }
    let w = 50;
    let it = 100000;
    let mut fail = 0;
    for _ in 0..it {
        for i in 1..n {
            let x = rand() % (i + 1);
            p.swap(i, x);
        }
        let mut now = (0, 0);
        for (i, p) in p.iter().enumerate() {
            now.0 += p.0;
            now.1 += p.1;
            let mut upa = i + 1;
            upa.chmin(a);
            upa.chmin(a * (i + 1) / n + w);
            let mut upb = i + 1;
            upb.chmin(b);
            upb.chmin(b * (i + 1) / n + w);
            let lowa = if upa >= 2 * w { upa - 2 * w } else { 0 };
            let lowb = if upb >= 2 * w { upb - 2 * w } else { 0 };
            if !(lowa <= now.0 && now.0 <= upa && lowb <= now.1 && now.1 <= upb) {
                fail += 1;
                break;
            }
        }
    }
    println!(
        "success rate: {}",
        (it - fail) as f64 / it as f64,
    );
}

fn run() {
    input! {
        n: usize,
        a: usize,
        b: usize,
        p: [f64; n],
        u: [f64; n],
    }
    let mut p = p.into_iter().zip(u.into_iter()).collect::<Vec<_>>();
    for i in 1..n {
        let x = rand() % (i + 1);
        p.swap(i, x);
    }
    let mut dp = vec![vec![0f64; b + 1]; a + 1];
    for (i, &(p, u)) in p.iter().enumerate() {
        let w = 80;
        let mut upa = i + 1;
        upa.chmin(a);
        upa.chmin(a * (i + 1) / n + w);
        let mut upb = i + 1;
        upb.chmin(b);
        upb.chmin(b * (i + 1) / n + w);
        let lowa = if upa >= 2 * w { upa - 2 * w } else { 0 };
        let lowb = if upb >= 2 * w { upb - 2 * w } else { 0 };
        for i in (lowa..=upa).rev() {
            for j in (lowb..=upb).rev() {
                let mut val = dp[i][j];
                for &(x, y, c) in
                    [(i - 1, j, p), (i, j - 1, u), (i - 1, j - 1, p + u - p * u)].iter()
                {
                    if x <= a && y <= b {
                        val.chmax(dp[x][y] + c);
                    }
                }
                dp[i][j] = val;
            }
        }
    }
    let mut ans = 0f64;
    for v in dp.into_iter().flatten() {
        ans.chmax(v);
    }
    println!("{:.5}", ans);
}

fn main() {
//    test();
    run();
}