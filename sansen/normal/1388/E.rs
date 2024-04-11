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

// N^2
// validN
// O(N^3)
//
// 2 rad <= l, r <= rad 
// 
// 
//
// 
//  
//

fn run() {
    input! {
        n: usize,
        a: [(i64, i64, i64); n],
    }
    let mut event = vec![];
    for (i, &p) in a.iter().enumerate() {
        for &q in a.iter().take(i) {
            if p.2 == q.2 {
                continue;
            }
            let mut p = p;
            let mut q = q;
            if p.2 < q.2 {
                std::mem::swap(&mut p, &mut q);
            }
            event.push((q.0 - p.1, q.2 - p.2, 1));
            event.push((q.1 - p.0, q.2 - p.2, -1));
        }
    }
    if event.is_empty() {
        let mut l = std::i64::MAX;
        let mut r = std::i64::MIN;
        for &(a, b, _) in a.iter() {
            l.chmin(a);
            r.chmax(b);
        }
        println!("{}", r - l);
        return;
    }
    event.sort_by(|a, b| (-(a.0 * b.1 - a.1 * b.0)).cmp(&0).then(a.2.cmp(&b.2)));
    let event = event;
    let mut map = std::collections::BTreeMap::new();
    for &(l, r, y) in a.iter() {
        let po = map.entry(y).or_insert((l, r));
        po.0.chmin(l);
        po.1.chmax(r);
    }
    let mut left: Vec<(i64, i64)> = vec![];
    for (&y, &(l, _)) in map.iter().rev() {
        while left.len() > 1 {
            let len = left.len();
            let (a, b) = left[len - 1];
            let (c, d) = left[len - 2];
            let (a, b) = (a - l, b - y);
            let (c, d) = (c - l, d - y);
            if a * d - b * c >= 0 {
                left.pop();
            } else {
                break;
            }
        }
        left.push((l, y));
    }
    let left = left;
    let mut right: Vec<(i64, i64)> = vec![];
    for (&y, &(_, r)) in map.iter() {
        while right.len() > 1 {
            let len = right.len();
            let (a, b) = right[len - 1];
            let (c, d) = right[len - 2];
            let (a, b) = (a - r, b - y);
            let (c, d) = (c - r, d - y);
            if a * d - b * c >= 0 {
                right.pop();
            } else {
                break;
            }
        }
        right.push((r, y));
    }
    let right = right;
    let mut ans = std::f64::MAX;
    let mut l = 0;
    let mut r = 0;
    let mut sum = 0;
    for &(x, y, s) in event.iter() {
        while l + 1 < left.len() {
            let (a, b) = left[l];
            let (c, d) = left[l + 1];
            let (p, q) = (c - a, d - b);
            if x * q - y * p > 0 {
                break;
            } else {
                l += 1;
            }
        }
        while r + 1 < right.len() {
            let (a, b) = right[r];
            let (c, d) = right[r + 1];
            let (p, q) = (c - a, d - b);
            if x * q - y * p < 0 {
                break;
            } else {
                r += 1;
            }
        }
//        println!("{} {}: {:?}, {:?}", x, y, left[l], right[r]);
        if sum == 0 {
            let (a, b) = left[l];
            let (c, d) = right[r];
            let p = -b as f64 / y as f64;
            let q = -d as f64 / y as f64;
            ans.chmin((c as f64 + x as f64 * q) - (a as f64 + x as f64 * p));
        }
        sum += s;
        if sum == 0 {
            let (a, b) = left[l];
            let (c, d) = right[r];
            let p = -b as f64 / y as f64;
            let q = -d as f64 / y as f64;
            ans.chmin((c as f64 + x as f64 * q) - (a as f64 + x as f64 * p));
        }
    }
    println!("{:.7}", ans);
}

fn main() {
    run();
}