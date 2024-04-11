fn run() {
    input! {
        n: usize,
        k: usize,
        a: [[usize1; n]; n],
    }
    let mut cnt = vec![0; n * n];
    for a in a.iter().flatten() {
        cnt[*a] += 1;
    }
    let all = cnt.iter().filter(|e| **e > 0).count();
    if all <= k {
        println!("{}", k - all);
        return;
    }
    let mut ans = 2;
    let mut a = a;
    for _ in 0..2 {
        for s in 0..n {
            let mut cnt = cnt.clone();
            let mut c = 0;
            let mut l = 0;
            for i in 0..(n - s) {
                for j in l..i {
                    for &(x, y) in [(i, s + j), (j, s + i)].iter() {
                        let a = a[x][y];
                        cnt[a] -= 1;
                        if cnt[a] == 0 {
                            c += 1;
                        }
                    }
                }
                cnt[a[i][s + i]] -= 1;
                if cnt[a[i][s + i]] == 0 {
                    c += 1;
                }
                if all - c == k || all - c + 1 == k {
                    ans = 1;
                }
                while all - c + 1 < k {
                    if cnt[a[l][s + l]] == 0 {
                        c -= 1;
                    }
                    cnt[a[l][s + l]] += 1;
                    for j in (l + 1)..=i {
                        for &(x, y) in [(l, s + j), (j, s + l)].iter() {
                            let a = a[x][y];
                            if cnt[a] == 0 {
                                c -= 1;
                            }
                            cnt[a] += 1;
                        }
                    }
                    l += 1;
                }
                if all - c == k || all - c + 1 == k {
                    ans = 1;
                }
            }
        }
        a = transpose(a);
    }
    println!("{}", ans);
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
// ---------- begin transpose ----------
pub fn transpose<T>(a: Vec<Vec<T>>) -> Vec<Vec<T>> {
    if a.is_empty() {
        return a;
    }
    let h = a.len();
    let w = a[0].len();
    assert!(a.iter().all(|a| a.len() == w));
    let mut ta: Vec<_> = (0..w).map(|_| Vec::with_capacity(h)).collect();
    for a in a {
        for (ta, a) in ta.iter_mut().zip(a) {
            ta.push(a);
        }
    }
    ta
}
// ---------- end transpose ----------