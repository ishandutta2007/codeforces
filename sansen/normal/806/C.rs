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
// 22
// 2
// 
// No
// 
// 
// 
// 1O(N)
// 

fn valid(beki: &[u64], b: &mut [u64]) -> bool {
    b.sort();
    let mut p = 0;
    for pow in beki.iter().rev() {
        if p < b.len() && *pow * 2 >= b[p] {
            p += 1;
        }
    }
    p == b.len()
}

fn run() {
    input! {
        n: usize,
        a: [u64; n],
    }
    let mut beki = vec![];
    let mut k = 0;
    while k < n && a[k] == 1 {
        beki.push(1);
        k += 1;
    }
    if k == 0 {
        println!("-1");
        return;
    }
    let mut pos = 0;
    let mut b = vec![];
    for a in a[k..].iter() {
        if *a == beki[pos] * 2 {
            beki[pos] *= 2;
            pos = (pos + 1) % beki.len();
        } else {
            pos = 0;
            if *a == beki[pos] * 2 {
                beki[pos] *= 2;
                pos = (pos + 1) % beki.len();
            } else {
                b.push(*a);
            }
        }
    }
    let (beki, b) = (beki, b);
    if !valid(&beki, &mut b.clone()) {
        println!("-1");
        return;
    }
    let mut ok = beki.len();
    let mut ng = 0;
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        let mut b = b.clone();
        for p in beki[mid..].iter() {
            let mut k = 1;
            while k <= *p {
                b.push(k);
                k *= 2;
            }
        }
        if valid(&beki[..mid], &mut b) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    let mut s = String::new();
    for k in ok..=beki.len() {
        s.push_str(&format!("{} ", k));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}