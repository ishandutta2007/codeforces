use crate::lib::fxhash::FxHashMap;
use crate::lib::math::gcd::ext::*;
use crate::lib::slice::*;
use crate::lib::stdio::*;

fn main() {
    scan!(mut n: usize, mut m: usize, mut k: u64, mut a: [usize1; n], mut b: [usize1; m]);
    if n < m {
        std::mem::swap(&mut n, &mut m);
        std::mem::swap(&mut a, &mut b);
    }
    let (g, inv_m1) = extgcd(m as u64, n as u64);
    let (g, inv_m1) = (g as usize, inv_m1 as usize);
    let n1 = n / g;
    let mut t = 0;
    let mut occur = vec![FxHashMap::default(); g];
    for (i, &a) in a.iter().enumerate() {
        occur[i % g].entry(a).or_insert(Vec::new()).push((i, 0));
    }

    let km = {
        let mut km = n as u64 / g as u64 * m as u64;
        for (i, &b) in b.iter().enumerate() {
            km -= occur[i % g].get(&b).unwrap_or(&Vec::new()).len() as u64;
        }
        km
    };
    t += (k / km as u64) * (n as u64 / g as u64 * m as u64);
    k %= km;
    if k == 0 {
        k = km;
        t -= n as u64 / g as u64 * m as u64;
    }

    for occ in &mut occur {
        for (_, (_, oc)) in occ.into_iter().enumerate() {
            if oc.is_empty() {
                continue;
            }
            for (i, p) in oc.iter_mut() {
                *p = (((*i / g) as u64 * inv_m1 as u64) % n1 as u64) as usize;
            }
            oc.sort_unstable_by_key(|&(_i, p)| p);
            let len = oc.len();
            oc.reserve_exact(len * 2);
            for i in 0..len * 2 {
                let (i, p) = oc[i];
                oc.push((i, p + n1));
            }
        }
    }
    let (mut lb, mut ub) = (0, n / g + 2);
    while lb + 1 != ub {
        let c = (lb + ub) / 2;
        let mut count = 0;
        for (i, &b) in b.iter().enumerate() {
            if let Some(slice) = occur[i % g].get(&b) {
                let pl = (((i / g) as u64 * inv_m1 as u64) % n1 as u64) as usize;
                let lo = partition_point(slice, |&(_, p)| p < pl);
                let hi = partition_point(slice, |&(_, p)| p < pl + c);
                count += (hi - lo) as u64;
            }
        }
        let x = m as u64 * c as u64 - count;
        if x < k {
            lb = c;
        } else {
            ub = c;
        }
    }
    let c = lb;
    t += m as u64 * c as u64;
    k -= {
        let mut count = 0;
        for (i, &b) in b.iter().enumerate() {
            if let Some(slice) = occur[i % g].get(&b) {
                let pl = (((i / g) as u64 * inv_m1 as u64) % n1 as u64) as usize;
                let lo = partition_point(slice, |&(_, p)| p < pl);
                let hi = partition_point(slice, |&(_, p)| p < pl + c);
                count += (hi - lo) as u64;
            }
        }
        m as u64 * c as u64 - count
    };
    assert_ne!(k, 0);
    let mut ai = (m as u64 * c as u64 % n as u64) as usize;
    let mut bi = 0;
    while k != 0 {
        if a[ai] != b[bi] {
            k -= 1;
        }
        t += 1;
        ai += 1;
        if ai == n {
            ai = 0;
        }
        bi += 1;
        if bi == m {
            bi = 0;
        }
    }
    println!("{}", t);
}



pub mod lib {

pub mod fxhash {

// original: https://github.com/cbreeden/fxhash

// Copyright 2015 The Rust Project Developers. See the COPYRIGHT
// file at the top-level directory of this distribution and at
// http://rust-lang.org/COPYRIGHT.
//
// Licensed under the Apache License, Version 2.0 <LICENSE-APACHE or
// http://www.apache.org/licenses/LICENSE-2.0> or the MIT license
// <LICENSE-MIT or http://opensource.org/licenses/MIT>, at your
// option. This file may not be copied, modified, or distributed
// except according to those terms.

use crate::lib::rand::seed;
use std::collections::{HashMap, HashSet};
use std::hash::{BuildHasherDefault, Hash, Hasher};
use std::ops::BitXor;

pub type FxBuildHasher = BuildHasherDefault<FxHasher>;

pub type FxHashMap<K, V> = HashMap<K, V, FxBuildHasher>;

pub type FxHashSet<V> = HashSet<V, FxBuildHasher>;

const ROTATE: u32 = 5;
static mut SEED64: u64 = 0;
static mut SEED32: u32 = 0;
static mut SEED: usize = 0;

#[used]
#[cfg_attr(target_os = "linux", link_section = ".init_array")]
#[cfg_attr(target_os = "windows", link_section = ".CRT$XCU")]
static INIT: unsafe extern "C" fn() = {
    #[cfg_attr(target_os = "linux", link_section = ".text.startup")]
    unsafe extern "C" fn init() {
        let seed = seed::seed();
        SEED64 = seed[0] | 1;
        SEED32 = seed[1] as u32 | 1;
        SEED = SEED64 as usize;
    }
    init
};

trait HashWord {
    fn hash_word(&mut self, word: Self);
}

macro_rules! impl_hash_word {
    ($($ty:ty = $key:ident),* $(,)*) => { $(
        impl HashWord for $ty {
            fn hash_word(&mut self, word: Self) {
                *self = self.rotate_left(ROTATE).bitxor(word).wrapping_mul(unsafe { $key });
            }
        }
    )* }
}

impl_hash_word!(usize = SEED, u32 = SEED32, u64 = SEED64);

fn read_u32(bytes: &[u8]) -> u32 {
    let mut data = 0;
    unsafe {
        std::ptr::copy_nonoverlapping(bytes.as_ptr(), &mut data as *mut _ as *mut u8, 4);
    }
    data
}

fn read_u64(bytes: &[u8]) -> u64 {
    let mut data = 0;
    unsafe {
        std::ptr::copy_nonoverlapping(bytes.as_ptr(), &mut data as *mut _ as *mut u8, 8);
    }
    data
}

#[allow(dead_code)]
fn write32(mut hash: u32, mut bytes: &[u8]) -> u32 {
    while bytes.len() >= 4 {
        let n = read_u32(bytes);
        hash.hash_word(n);
        bytes = bytes.split_at(4).1;
    }
    for byte in bytes {
        hash.hash_word(*byte as u32);
    }
    hash
}

#[allow(dead_code)]
fn write64(mut hash: u64, mut bytes: &[u8]) -> u64 {
    while bytes.len() >= 8 {
        let n = read_u64(bytes);
        hash.hash_word(n);
        bytes = bytes.split_at(8).1;
    }
    if bytes.len() >= 4 {
        let n = read_u32(bytes);
        hash.hash_word(n as u64);
        bytes = bytes.split_at(4).1;
    }
    for byte in bytes {
        hash.hash_word(*byte as u64);
    }
    hash
}

#[cfg(target_pointer_width = "32")]
fn write(hash: usize, bytes: &[u8]) -> usize { write32(hash as u32, bytes) as usize }

#[cfg(target_pointer_width = "64")]
fn write(hash: usize, bytes: &[u8]) -> usize { write64(hash as u64, bytes) as usize }

#[derive(Debug, Clone)]
pub struct FxHasher {
    hash: usize,
}

impl Default for FxHasher {
    fn default() -> FxHasher { FxHasher { hash: 0 } }
}

impl Hasher for FxHasher {
    fn write(&mut self, bytes: &[u8]) { self.hash = write(self.hash, bytes); }
    fn write_u8(&mut self, i: u8) { self.hash.hash_word(i as usize); }
    fn write_u16(&mut self, i: u16) { self.hash.hash_word(i as usize); }
    fn write_u32(&mut self, i: u32) { self.hash.hash_word(i as usize); }
    #[cfg(target_pointer_width = "32")]
    fn write_u64(&mut self, i: u64) {
        self.hash.hash_word(i as usize);
        self.hash.hash_word((i >> 32) as usize);
    }
    #[cfg(target_pointer_width = "64")]
    fn write_u64(&mut self, i: u64) { self.hash.hash_word(i as usize); }
    fn write_usize(&mut self, i: usize) { self.hash.hash_word(i); }
    fn finish(&self) -> u64 { self.hash as u64 }
}

pub fn hash<T: Hash + ?Sized>(v: &T) -> usize {
    let mut state = FxHasher::default();
    v.hash(&mut state);
    state.finish() as usize
}

}  // mod fxhash

pub mod math {

pub mod gcd {

pub mod ext {

type Int = u64;
type IInt = i64;

/// (g, x) where g = gcd(a, b), ax = g (mod b), 0 <= x < b/g
pub fn extgcd(a: Int, b: Int) -> (Int, Int) {
    let (mut a, mut b) = (a as IInt, b as IInt);
    let b0 = b;
    // A = [a, x, y; b, u, v], k = [-1; a; b], Ak = 0
    let (mut x, mut u) = (1, 0);
    while b != 0 {
        let t = a / b;
        a -= t * b;
        x -= t * u;
        std::mem::swap(&mut a, &mut b);
        std::mem::swap(&mut x, &mut u);
    }
    if x < 0 {
        x += b0 / a;
    }
    (a as Int, x as Int)
}

}  // mod ext

}  // mod gcd

}  // mod math

pub mod rand {

pub mod seed {

// Codeforces
#[cfg(windows)]
mod detail {
    extern "system" {
        #[link_name = "SystemFunction036"]
        fn RtlGenRandom(buf: *mut u8, len: u32) -> u8;
    }
    fn getrand(buf: *mut u8, len: usize) {
        let ret = unsafe { RtlGenRandom(buf, len as u32) };
        assert_ne!(ret, 0);
    }
    macro_rules! def_seed {
        ($(pub fn $name:ident() -> $ret:ty;)*) => { $(
            pub fn $name() -> $ret {
                let mut v = std::mem::MaybeUninit::uninit();
                getrand(v.as_mut_ptr() as *mut u8, std::mem::size_of_val(&v));
                unsafe { v.assume_init() }
            }
        )* };
    }
    def_seed! {
        pub fn seed() -> [u64; 4];
        pub fn seed64() -> u64;
    }
}

#[cfg(not(windows))]
mod detail {
    pub fn seed() -> [u64; 4] {
        [
            0x35fee63b_fd9f69cf,
            0x9fd0680a_f9e37356,
            0x7454d5e3_d982527e,
            0x35d1849a_77925163,
        ]
    }
    pub fn seed64() -> u64 { 0x17adfb20_0995921c }
}

pub use self::detail::*;

pub fn from_time() -> [u64; 4] {
    use std::time::SystemTime;
    let t = SystemTime::now().duration_since(SystemTime::UNIX_EPOCH).unwrap().as_nanos();
    unsafe {
        std::mem::transmute([t, t.wrapping_mul(0xaa3c057f_bed7578e_6b62420c_f79932a5)])
    }
}

}  // mod seed

}  // mod rand

pub mod slice {

pub fn partition_point<T, F: FnMut(&T) -> bool>(slice: &[T], mut pred: F) -> usize {
    let (mut l, mut r) = (0, slice.len()); // pred(slice[r]) == false
    while l != r {
        let mid = (l + r) / 2;
        let val = unsafe { slice.get_unchecked(mid) };
        if pred(val) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    r
}

pub fn lower_bound<T: Ord>(slice: &[T], v: &T) -> usize {
    partition_point(slice, |x| x < v)
}

pub fn upper_bound<T: Ord>(slice: &[T], v: &T) -> usize {
    partition_point(slice, |x| x <= v)
}

}  // mod slice

pub mod stdio {

pub use crate::prtln;
pub use crate::scan;
use std::io::{stdout, BufWriter, StdoutLock};

pub fn stdout_buf() -> BufWriter<StdoutLock<'static>> {
    let out = Box::leak(Box::new(stdout()));
    BufWriter::with_capacity(1 << 25, out.lock())
}

#[macro_export]
macro_rules! prtln {
    (@ $dst:expr, iter=$expr:expr) => { $crate::prtln!(@ $dst, iter=$expr, sep=" "); };
    (@ $dst:expr, iter=$expr:expr, sep=$sep:expr) => { {
        let mut iter = $expr.into_iter();
        if let Some(expr) = iter.next() {
            std::write!($dst, "{}", expr).unwrap();
            for expr in iter { std::write!($dst, "{}{}", $sep, expr).unwrap(); }
        }
        $crate::prtln!(@ $dst, "");
    } };
    (@ $dst:expr, $expr:expr) => { std::writeln!($dst, "{}", $expr).unwrap(); };
    (@ $dst:expr, $expr:expr, $($exprs:expr),*) => { {
        std::write!($dst, "{} ", $expr).unwrap();
        $crate::prtln!(@ $dst, $($exprs),*);
    } };
    (new $var:ident) => { let mut $var = stdout_buf(); };
    (new $var:ident, $($t:tt)*) => { {
        $crate::prtln!(new $var);
        $crate::prtln!(to $var, $($t)*);
    } };
    (to $var:ident, $($t:tt)*) => { {
        use std::io::Write;
        $crate::prtln!(@ $var, $($t)*);
    } };
    ($($t:tt)*) => { $crate::prtln!(new __prtln, $($t)*); };
}

#[macro_export]
macro_rules! scan {
    (@ $iter:expr $(,)?) => {};
    (@ $iter:expr, mut $var:ident : $t:tt $($r:tt)*) => {
        let mut $var = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $pat:pat in $t:tt $($r:tt)*) => {
        let $pat = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (from $s:expr, $($r:tt)*) => { $crate::scan!(@ $s, $($r)*); };
    (new $var:ident, $($r:tt)*) => {
        let mut __input = String::new();
        std::io::Read::read_to_string(&mut std::io::stdin(), &mut __input).unwrap();
        let $var = &mut __input.split_ascii_whitespace();
        $crate::scan!(@ $var, $($r)*);
    };
    ($($r:tt)*) => { $crate::scan!(new __scan, $($r)*); };
}

#[macro_export]
macro_rules! scan_value {
    ($iter:expr, ( $($t:tt),* )) => { ( $($crate::scan_value!($iter, $t)),* ) };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| $crate::scan_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, [u8]) => { $iter.next().unwrap().as_bytes() };
    ($iter:expr, usize1) => { $crate::scan_value!($iter, usize) - 1 };
    ($iter:expr, $t:ty) => { $iter.next().unwrap().parse::<$t>().unwrap() };
}

}  // mod stdio

}  // mod lib