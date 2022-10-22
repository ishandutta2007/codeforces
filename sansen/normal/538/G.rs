// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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

// 
// parity -
// 0 <= a < b <= l 
// (a, x, y) -> (b, z, w)
// (L or R)abs(x - z), (U or D) abs(y - w)
// UD, LR hoge
//
// 
// dx, dy 
// t % l dx, dy O(N) 
// 
// 2, dx, dy 
// (s, x, y), (t, z, w)
// diff >= (x - dx * s - (z - dx * t)).abs() + (z - dy * s - (w - dy * t)).abs()
// = (x - z - dx * (s - t)).abs() + (z - w - dy * (s - t)).abs()
// = (A - dx * q).abs() + (B - dy * q).abs()
// dx + dy, dx - dy 
// OK?
// 
// (n, 0, dx, dy) 
// (a, b, c, d) 
// l - a >= (c - b * dx - dx).abs() + (d - b * dy - dy).abs()
// (l, -1, 0, 0) ok
//
//

fn require(b: bool) {
    if !b {
        println!("NO");
        std::process::exit(0);
    }
}

fn run() {
    input! {
        n: usize,
        l: i64,
        p: [(i64, i64, i64); n],
    }
    let mut a = vec![(0, 0, 0, 0)];
    for (t, x, y) in p {
        require(x.abs() + y.abs() <= t && (x.abs() + y.abs()) % 2 == t % 2);
        let q = t / l;
        let r = t % l;
        a.push((r, q, x, y));
    }
    a.sort();
    a.push((l, -1, 0, 0));
    let mut range_add = (-l, l); // dx + dy
    let mut range_sub = (-l, l); // dx - dy
    for p in a.windows(2) {
        let (a, b, c, d) = p[0];
        let (p, q, r, s) = p[1];
        let diff = p - a;
        let mut q = q - b;
        let mut c = c - r;
        let mut d = d - s;
        if q < 0 {
            c *= -1;
            d *= -1;
            q *= -1;
        }
        let (q, c, d) = (q, c, d);
        if q == 0 {
            require(diff >= c.abs() + d.abs());
        } else {
            range_add.1.chmin((diff - c - d).div_euclid(q));
            range_add.0.chmax((-diff - c - d + q - 1).div_euclid(q));
            range_sub.1.chmin((diff - c + d).div_euclid(q));
            range_sub.0.chmax((-diff - c + d + q - 1).div_euclid(q));
        }
    }
    require(range_add.0 <= range_add.1);
    require(range_sub.0 <= range_sub.1);
    for add in (range_add.0..=range_add.1).take(4) {
        for sub in (range_sub.0..=range_sub.1).take(4) {
            if add.abs() % 2 != sub.abs() % 2 {
                continue;
            }
            let dx = (add + sub) / 2;
            let dy = (add - sub) / 2;
            if dx.abs() + dy.abs() <= l && (l - dx.abs() - dy.abs()) % 2 == 0 {
                let mut ans = String::new();
                let mut pos = (0, 0);
                let mut ok = true;
                for p in a.windows(2) {
                    let (p, q, r, s) = p[1];
                    let next = (r - q * dx, s - q * dy);
                    ans.push_str(&"R".repeat(0i64.max(next.0 - pos.0) as usize));
                    ans.push_str(&"L".repeat(0i64.max(pos.0 - next.0) as usize));
                    ans.push_str(&"U".repeat(0i64.max(next.1 - pos.1) as usize));
                    ans.push_str(&"D".repeat(0i64.max(pos.1 - next.1) as usize));
                    while (ans.len() as i64) < p {
                        ans.push_str("LR");
                    }
                    pos = next;
                    if ans.len() as i64 > p {
                        ok = false;
                        break;
                    }
                    require(ans.len() as i64 == p);
                }
                if !ok {
                    break;
                }
                println!("{}", ans);
                return;
            }
        }
    }
    require(false);
}

fn main() {
    run();
}