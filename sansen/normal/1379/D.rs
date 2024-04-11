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

fn run() {
    input! {
        n: usize,
        _h: i64,
        m: i64,
        k: i64,
        p: [(i64, i64); n],
    }
    let half = m / 2;
    let mut a = vec![];
    for (i, &(_, x)) in p.iter().enumerate() {
        a.push((x % half, i));
    }
    a.sort();
    let b = a.clone();
    for b in b {
        a.push((b.0 + half, b.1));
    }
    let mut ans = (std::usize::MAX, 0, 0);// cancel, t, index
    let mut r = 0;
    for l in 0..n {
        let t = a[l].0;
        while r < a.len() && a[r].0 <= t + half - k {
            r += 1;
        }
        ans.chmin((n - (r - l), t, l));
    }
    println!("{} {}", ans.0, ans.1);
    let mut s = String::new();
    let mut x = vec![];
    for i in 0..n {
        if i + ans.2 >= ans.2 + n - ans.0 {
            x.push(a[i + ans.2].1 + 1);
        }
    }
    x.sort();
    for x in x {
        s.push_str(&format!("{} ", x));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}