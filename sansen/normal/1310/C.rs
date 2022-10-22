// ---------- begin Suffix Array ----------
//  https://ei1333.github.io/luzhiled/snippets/string/suffix-array.html
// 
fn suffix_array<T: Ord + Copy>(s: &[T]) -> Vec<usize> {
    let n = s.len();
    let mut z = Vec::with_capacity(n);
    z.extend_from_slice(s);
    z.sort();
    z.dedup();
    let mut sa: Vec<usize> = (0..n).collect();
    sa.sort_by(|&a, &b| s[a].cmp(&s[b]).then(b.cmp(&a)));
    let mut c = Vec::with_capacity(n);
    for s in s.iter() {
        c.push(z.binary_search(s).unwrap());
    }
    let mut classes = vec![0; n];
    let mut cnt = vec![0; n];
    let mut len = 1;
    let mut id = 0;
    while id < n && len < n {
        id = 1;
        let mut prev = sa[0];
        classes[prev] = id - 1;
        cnt[0] = 0;
        for (i, &sa) in sa.iter().enumerate().skip(1) {
            if c[sa] == c[prev] && prev < n - len && c[prev + len / 2] == c[sa + len / 2] {
                classes[sa] = classes[prev];
            } else {
                id += 1;
                classes[sa] = id - 1;
                cnt[id - 1] = i;
            }
            prev = sa;
        }
        c.clone_from(&sa);
        for c in c.iter() {
            if *c >= len {
                let k = *c - len;
                sa[cnt[classes[k]]] = k;
                cnt[classes[k]] += 1;
            }
        }
        std::mem::swap(&mut classes, &mut c);
        len <<= 1;
    }
    sa
}
// ---------- end Suffix Array ----------
// ---------- begin z-algorithm ----------
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
// ---------- end z-algorithm ----------
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

use std::cmp::*;

fn run() {
    input! {
        n: usize,
        m: usize,
        k: u64,
        s: chars,
    }
    let sa = suffix_array(&s);
    let mut a = vec![];
    for i in (sa[0] + 1)..=n {
        a.push(&s[sa[0]..i]);
    }
    for i in 1..n {
        let mut lcp = 0;
        for (a, b) in s[sa[i - 1]..].iter().zip(s[sa[i]..].iter()) {
            if *a != *b {
                break;
            }
            lcp += 1;
        }
        for j in (sa[i] + lcp + 1)..=n {
            a.push(&s[sa[i]..j]);
        }
    }
    let mut ok = 0;
    let mut ng = a.len();
    while ng - ok > 1 {
        let mid = (ok + ng) / 2;
        let val = a[mid];
        let mut z = vec![];
        z.extend_from_slice(val);
        z.push('$');
        z.extend_from_slice(&s);
        let x = z_algorithm(&z);
        let x = &x[(val.len() + 1)..];
        let mut dp = vec![0u64; n + 1];
        dp[0] = 1;
        for _ in 0..m {
            let mut imos = vec![0; n + 1];
            for i in 0..n {
                if x[i] >= val.len() {
                    imos[i + val.len()] = min(k, imos[i + val.len()] + dp[i]);
                } else if i + x[i] < n && s[i + x[i]] > val[x[i]] {
                    imos[i + x[i] + 1] = min(k, imos[i + x[i] + 1] + dp[i]);
                }
            }
            for i in 1..=n {
                imos[i] = min(k, imos[i] + imos[i - 1]);
            }
            dp = imos;
        }
        if dp[n] >= k {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    let ans: String = a[ok].iter().cloned().collect();
    println!("{}", ans);
}

fn main() {
    run();
}