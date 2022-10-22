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

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// 
// 6100
// 2swap3
fn test() {
    let mut a = [1i32, 2, 3, 4];
    let mut set = Set::new();
    set.insert(a);
    let mut map = Map::new();
    let mut q = Deque::new();
    q.push_back((a, 0));
    while let Some((src, d)) = q.pop_front() {
        if d == 3 {
            break;
        }
        let d = d + 1;
        for i in 0..=a.len() {
            let mut a = src;
            a.rotate_right(i);
            a[..i].reverse();
            a[..i].iter_mut().for_each(|a| *a *= -1);
            for a in a.iter_mut() {
                if a.abs() == 3 {
                    *a = 3;
                }
            }
            if set.insert(a) {
                println!("{:?} {}", a, d);
                map.insert(a, src);
                q.push_back((a, d));
            }
        }
    }
    let mut b = [3, 1, 2, -4];
    while let Some(a) = map.get(&b) {
        println!("{:?}", b);
        b = *a;
    }
    println!("{:?}", b);
    /*
    println!("{}", set.len());
    for a in set {
        println!("{:?}", a);
    }
    */
}

fn run() {
    input! {
        n: usize,
        s: bytes,
        t: bytes,
    }
    let mut x = s.clone();
    let mut y = t.clone();
    x.sort();
    y.sort();
    if x != y {
        println!("-1");
        return;
    }
    let mut x = s;
    let mut ans = vec![];
    {
        let mut op = |k: usize, x: &mut [u8]| {
            assert!(k <= n);
            ans.push(k);
            x.rotate_right(k);
            x[..k].reverse();
        };
        for i in (0..n).rev() {
            let p = x.iter().rposition(|x| *x == t[i]).unwrap();
            op(n, &mut x);
            op(p, &mut x);
            op(1, &mut x);
        }
    }
    println!("{}", ans.len());
    println!("{}", ans.iter().map(|s| s.to_string()).collect::<Vec<_>>().join(" "));
}

fn main() {
    run();
}