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

fn calc(a: &[i64], a_max: i64) -> (i64, i64) {
    let mut ans = (std::i64::MAX, 0);
    for a in a.iter() {
        if *a == a_max {
            ans.1 += 1;
        }
        ans.0.chmin(*a);
    }
    ans
}

fn run() {
    input! {
        n: usize,
        a_max: i64,
        cf: i64,
        cm: i64,
        m: i64,
        a: [i64; n],
    }
    let save = a.clone();
    let mut a = a;
    let mut b = vec![];
    for (i, a) in a.iter().enumerate() {
        b.push((*a, i));
    }
    b.sort();
    if a.iter().fold(0, |s, a| s + a_max - a) <= m {
        let score = a_max * cm + n as i64 * cf;
        let mut s = String::new();
        s.push_str(&format!("{}\n", score));
        let a = vec![a_max; n];
        for a in a.iter() {
            s.push_str(&format!("{} ", *a));
        }
        s.pop();
        println!("{}", s);
        return;
    }
    let mut sum = 0;
    let mut pos = 0;
    while pos < n && pos as i64 * b[pos].0 - sum <= m {
        sum += b[pos].0;
        pos += 1;
    }
    let (_, y) = calc(&a, a_max);
    let mut ans = ((m + sum) / (pos as i64) * cm + y * cf, n);
    let mut need = 0;
    for i in (0..n).rev() {
        need += a_max - b[i].0;
        if need > m {
            break;
        }
        while pos > i {
            pos -= 1;
            sum -= b[pos].0;
        }
        while pos > 0 && need + (pos as i64 * b[pos - 1].0 - sum) > m {
            pos -= 1;
            sum -= b[pos].0;
        }
        let mut score = (n - i) as i64 * cf;
        let v = (m - need + sum) / (pos as i64);
        score += v * cm;
    //    println!("{}: {} {} {} {}", i, pos, score, need, v);
        ans.chmax((score, i));
    }
    let mut m = m;
    for i in ans.1..n {
        a[b[i].1] = a_max;
        m -= a_max - b[i].0;
    }
    if cm > 0 {
        let q = (ans.0 - (n - ans.1) as i64 * cf) / cm;
        let mut i = 0;
        while i < n && a[b[i].1] < q && m >= q - b[i].0 {
            m -= q - b[i].0;
            a[b[i].1] = q;
            i += 1;
        }
    }
    let (x, y) = calc(&a, a_max);
    assert!(x * cm + y * cf == ans.0);
    let mut s = String::new();
    s.push_str(&format!("{}\n", ans.0));
    for a in a.iter() {
        s.push_str(&format!("{} ", *a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}