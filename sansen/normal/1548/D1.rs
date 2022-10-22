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

fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn run() {
    input! {
        n: usize,
        p: [(i64, i64); n],
    }
    /*
    let p = (0..n).map(|_| ((rand() % 5000000) as i64 * 2, (rand() % 5000000) as i64 * 2)).collect::<Vec<_>>();
    let mut ans = 0;
    for i in 0..n {
        for j in 0..i {
            for k in 0..j {
                let a = p[i].0 - p[j].0;
                let b = p[i].1 - p[j].1;
                let c = p[i].0 - p[k].0;
                let d = p[i].1 - p[k].1;
                let s = (a * d - b * c).abs() / 2;
                let x = gcd(a.abs(), b.abs());
                let y = gcd(c.abs(), d.abs());
                let z = gcd((a - c).abs(), (b - d).abs());
                let l = x + y + z;
                assert!(l % 2 == 0);
                if (s - l / 2 + 1) % 2 == 1 {
                    ans += 1;
                }
            }
        }
    }
    println!("{}", ans);
    */
    let mut ans = 0u64;
    for i in 2..n {
        let g = p[i];
        let p = &p[..i];
        let mut cnt = [[0; 2]; 2];
        for (_j, a) in p.iter().enumerate() {
            let x = ((a.0 - g.0).abs() / 2 % 2) as usize;
            let y = ((a.1 - g.1).abs() / 2 % 2) as usize;
            for (a, cnt) in cnt.iter().enumerate() {
                for (b, &cnt) in cnt.iter().enumerate() {
                    let mut even = 0;
                    if (x, y) == (0, 0) {
                        even += 1;
                    }
                    if (a, b) == (0, 0) {
                        even += 1;
                    }
                    if (x, y) == (a, b) {
                        even += 1;
                    }
                    if (3 - even) % 2 == 0 {
                        ans += cnt;
                    }
                }
            }
            cnt[x][y] += 1;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}