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

// 
// +-1 
// p
// 
// p
// +-1p
// 
// 3
//

fn run() {
    input! {
        n: usize,
        x: i64,
        y: i64,
        a: [u32; n],
    }
    let mut p = vec![];
    for &a in [a[0], a[n - 1]].iter() {
        for x in [a - 1, a, a + 1].iter() {
            let mut x = *x;
            for k in 2.. {
                if k * k > x {
                    break;
                }
                if x % k == 0 {
                    p.push(k);
                    while x % k == 0 {
                        x /= k;
                    }
                }
            }
            if x > 1 {
                p.push(x);
            }
        }
    }
    p.sort();
    p.dedup();
    let calc = |p: u32| -> i64 {
        let mut deq = std::collections::VecDeque::new();
        let mut fix = false;
        for (i, a) in a.iter().enumerate() {
            if *a % p == 0 {
                continue;
            }
            let b = (*a + p - 1) % p == 0 || (*a + 1) % p == 0;
            fix |= !b;
            deq.push_back((i as i64, b));
        }
        let mut res = std::i64::MAX;
        if deq.is_empty() {
            res.chmin(0);
        } else {
            let len = deq.len();
            let l = deq.get(0).unwrap().0;
            let r = deq.get(len - 1).unwrap().0;
            res.chmin((r - l + 1) * x);
            if fix {
                let mut sum = 0;
                let mut b = vec![];
                while deq.back().unwrap().1 {
                    b.push(deq.pop_back().unwrap().0);
                }
                if b.len() > 0 {
                    let r = deq.back().unwrap().0;
                    let mut val = b.len() as i64 * y;
                    for (i, p) in b.into_iter().enumerate() {
                        val.chmin(i as i64 * y + (p - r) as i64 * x);
                    }
                    sum += val;
                }
                let mut b = vec![];
                while deq.front().map_or(false, |p| p.1) {
                    b.push(deq.pop_front().unwrap().0);
                }
                if b.len() > 0 {
                    let l = deq.front().unwrap().0;
                    let mut val = b.len() as i64 * y;
                    for (i, p) in b.into_iter().enumerate() {
                        val.chmin(i as i64 * y + (l - p) as i64 * x);
                    }
                    sum += val;
                }
                sum += x * (deq.back().unwrap().0 - deq.front().unwrap().0 + 1) as i64;
                res.chmin(sum);
            } else {
                res.chmin(deq.len() as i64 * y);
                let len = deq.len();
                let mut l = -deq.get(0).unwrap().0 * x;
                for (i, (r, _)) in deq.into_iter().enumerate() {
                    res.chmin(r * x + l + (len - i - 1) as i64 * y + x);
                    l.chmin(-r * x + i as i64 * y);
                }
            }
        }
        res
    };
    let mut ans = std::i64::MAX;
    for p in p {
        ans.chmin(calc(p));
    }
    println!("{}", ans);
}

fn main() {
    run();
}