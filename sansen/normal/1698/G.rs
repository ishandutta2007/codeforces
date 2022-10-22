// 10^100 T0
// S 
// S  T xor
// 1T
//
// |S| <= 35
//
// 4
//
// 
// 0
// 
// 
// 1, 2
// 
// 
// 1
// 
// xor
// xor
//
// S 0
//  (0, 0, ..., 1) 
// 
// 
// S 11s, e_i 
// k = |S| - 1 
//
// s * mat [s, e_1, .., e_{k - 1}] ^n = e_k
//
// n 
// 
// 
// 2^18 
//  BS-GS 
//  A 
//
// s A^n = e_k
// s A^(qx + r) = e_k
// s A^(qx) = e_k A^(-r)
// 
//
// 
// 

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run(mut s: Vec<u8>) -> Option<(usize, usize)> {
    s.iter_mut().for_each(|s| *s -= b'0');
    let c = s.iter().filter(|s| **s == 1).count();
    if c == 0 {
        return None;
    }
    let f = s.iter().position(|s| *s == 1).unwrap();
    if c == 1 {
        return Some((f, f + 1));
    }
    let mut s = s;
    s.drain(..=f);
    while s.last().map_or(false, |c| *c == 0) {
        s.pop();
    }
    let s = s;
    let k = s.len();
    let mut a = vec![vec![0u8; k]; k];
    for (i, s) in s.iter().enumerate() {
        a[0][i] = *s;
    }
    for i in 1..k {
        a[i][i - 1] = 1;
    }
    let inv_a = inverse_matrix(a.clone()).unwrap();
    let mut right = vec![0; k];
    right[k - 1] = 1u8;
    let sq = 1 << (k / 2 + 1);
    let mut map = Map::new();
    for i in 0..=sq {
        map.entry(right.clone()).or_insert(i);
        let mut next = vec![0; k];
        for (right, inv_a) in right.iter().zip(inv_a.iter()) {
            for (next, inv_a) in next.iter_mut().zip(inv_a.iter()) {
                *next ^= *right & *inv_a;
            }
        }
        right = next;
    }
    let mul = |a: &[Vec<u8>], b: &[Vec<u8>]| -> Vec<Vec<u8>> {
        let mut c = vec![vec![0; k]; k];
        for (c, a) in c.iter_mut().zip(a.iter()) {
            for (a, b) in a.iter().zip(b.iter()) {
                for (c, b) in c.iter_mut().zip(b.iter()) {
                    *c ^= *a & *b;
                }
            }
        }
        c
    };
    let mut mat = vec![vec![0; k]; k];
    for i in 0..k {
        mat[i][i] = 1;
    }
    for i in (0..20).rev() {
        mat = mul(&mat, &mat);
        if sq >> i & 1 == 1 {
            mat = mul(&mat, &a);
        }
    }
    let rad = mat;
    let mut mat = vec![vec![0; k]; k];
    for i in 0..k {
        mat[i][i] = 1;
    }
    for i in 0..=sq {
        let mut b = vec![0; k];
        for (s, mat) in s.iter().zip(mat.iter()) {
            for (b, mat) in b.iter_mut().zip(mat.iter()) {
                *b ^= *s & *mat;
            }
        }
        if let Some(v) = map.get(&b) {
            return Some((f, sq * i + v + f + k));
        }
        mat = mul(&mat, &rad);
    }
    None
}

fn inverse_matrix(mut mat: Vec<Vec<u8>>) -> Option<Vec<Vec<u8>>> {
    let n = mat.len();
    assert!(mat.iter().all(|mat| mat.len() == n));
    for (i, mat) in mat.iter_mut().enumerate() {
        mat.resize(2 * n, 0);
        mat[n + i] = 1;
    }
    for i in 0..n {
        let x = (i..n).find(|x| mat[*x][i] != 0)?;
        mat.swap(i, x);
        let a = std::mem::take(&mut mat[i]);
        for mat in mat.iter_mut().filter(|mat| !mat.is_empty()) {
            let mul = mat[i];
            for (mat, a) in mat[i..].iter_mut().zip(a[i..].iter()) {
                *mat ^= mul & *a;
            }
        }
        mat[i] = a;
    }
    Some(mat.iter().map(|a| Vec::from(&a[n..])).collect())
}

fn main() {
    input! {
        s: bytes,
    }
    if let Some((a, b)) = run(s) {
        println!("{} {}", a + 1, b + 1);
    } else {
        println!("-1");
    }
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