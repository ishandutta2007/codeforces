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

fn diff(a: usize, b: usize) -> usize {
    a.max(b) - a.min(b)
}

fn run() {
    input! {
        n: usize,
        p: usize1,
        s: bytes,
    }
    let mut cost = 0;
    let mut deq = std::collections::VecDeque::new();
    for i in 0..n {
        if i >= n - 1 - i {
            break;
        }
        let a = s[i];
        let b = s[n - 1 - i];
        if a != b {
            deq.push_back(i + 2 * n);
        }
        let (a, b) = (a.max(b), a.min(b));
        cost += (a - b).min(b + 26 - a) as usize;
    }
    let cost = cost;
    if deq.is_empty() {
        println!("{}", cost);
        return;
    }
    let p = p + n;
    let mut ans = cost + *deq.back().unwrap() - p;
    let mut next = std::collections::VecDeque::new();
    while deq.len() > 0 {
        let x = deq.pop_back().unwrap();
        next.push_back(n + n - 1 - x % n);
        let f = *next.front().unwrap();
        let d = deq.back().map_or(*next.back().unwrap(), |p| *p);
        ans = (cost + diff(f, d) + diff(f, p)).min(ans);
        ans = (cost + diff(f, d) + diff(d, p)).min(ans);
    }
    deq = next;
    let mut next = std::collections::VecDeque::new();
    while deq.len() > 0 {
        let x = deq.pop_back().unwrap();
        next.push_back(n + n - 1 - x % n);
        let f = *next.front().unwrap();
        let d = deq.back().map_or(*next.back().unwrap(), |p| *p);
        ans = (cost + diff(f, d) + diff(f, p)).min(ans);
        ans = (cost + diff(f, d) + diff(d, p)).min(ans);
    }
    deq = next;
    let mut next = std::collections::VecDeque::new();
    while deq.len() > 0 {
        let x = deq.pop_back().unwrap();
        next.push_back(n - 1 - x % n);
        let f = *next.front().unwrap();
        let d = deq.back().map_or(*next.back().unwrap(), |p| *p);
        ans = (cost + diff(f, d) + diff(f, p)).min(ans);
        ans = (cost + diff(f, d) + diff(d, p)).min(ans);
    }
    println!("{}", ans);
}

fn main() {
    run();
}