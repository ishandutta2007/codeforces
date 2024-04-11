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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

fn z_algorithm<T: Eq>(s: &[T]) -> Vec<usize> {
    let len = s.len();
    let mut a = vec![0; len];
    a[0] = len;
    let mut i = 1;
    let mut j = 0;
    while i < len {
        while i + j < len && s[j] == s[i + j] {
            j += 1;
        }
        a[i] = j;
        if j == 0 {
            i += 1;
            continue;
        }
        let mut k = 1;
        while i + k < len && k + a[k] < j {
            a[i + k] = a[k];
            k += 1;
        }
        i += k;
        j -= k;
    }
    a
}

// Tyes, ok
//
// 
// A B
// z_algorithm
// 
// 
// prefix, suffix 

fn calc(s: &[char], t: &[char], k: usize) -> Vec<Option<usize>> {
    let mut a = vec![];
    a.extend_from_slice(t);
    a.push('$');
    a.extend_from_slice(s);
    let a = &z_algorithm(&a)[(t.len() + 1)..];
    let mut set = std::collections::BTreeSet::new();
    for i in 1..=t.len() {
        set.insert(i);
    }
    let mut left = vec![None; t.len() + 1];
    for (i, &a) in a.iter().enumerate() {
        let mut save = vec![];
        use std::ops::Bound::*;
        for &x in set.range((Included(&0), Included(&std::cmp::min(a, k)))).rev() {
            if i + x < k {
                break;
            }
            left[x] = Some(i + x - k);
            save.push(x);
        }
        for x in save {
            set.remove(&x);
        }
    }
    left
}

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        s: chars,
        t: chars,
    }
    assert!(t.len() == m);
    if t.len() <= 2 * k {
        let mut a = t.clone();
        a.push('$');
        a.extend_from_slice(&s);
        let a = &z_algorithm(&a)[(t.len() + 1)..];
        if let Some(x) = a.iter().position(|a| *a >= t.len()) {
            let (l, r) = if x + 2 * k <= n {
                (x + 1, x + k + 1)
            } else {
                (n - 2 * k + 1, n - k + 1)
            };
            println!("Yes\n{} {}", l, r);
            return;
        }
    }
    let fl = calc(&s, &t, k);
    let mut s = s;
    s.reverse();
    let mut t = t;
    t.reverse();
    let bl = calc(&s, &t, k);
    for i in 1..m {
        match (fl[i], bl[m - i]) {
            (Some(x), Some(y)) => {
                if x + k <= n - y - k {
                    println!("Yes\n{} {}", x + 1, n - y - k + 1);
                    return;
                }
            },
            _ => (),
        };
    }
    println!("No");
}

fn main() {
    run();
}