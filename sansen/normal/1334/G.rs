// ---------- begin fast fourier transform ----------
#[allow(dead_code)]
mod fft {
    use std::marker::Copy;
    use std::ops::{Add, Mul, Sub};
    pub fn fft<T>(a: &mut [T], zeta: T, one: T)
    where
        T: Add<Output = T> + Mul<Output = T> + Sub<Output = T> + Copy,
    {
        let size = a.len();
        assert!(size.is_power_of_two());
        let w = size.trailing_zeros() as usize;
        for i in 0..size {
            let mut j = i;
            let mut k = 0;
            for _ in 0..w {
                k = (k << 1) | (j & 1);
                j >>= 1;
            }
            if i < k {
                a.swap(i, k);
            }
        }
        for k in 1..(w + 1) {
            let len = 1 << k;
            let mut z = one;
            for _ in 0..(1 << (w - k)) {
                z = z * zeta;
            }
            let zeta = z;
            for a in a.chunks_mut(len) {
                let (f, t) = a.split_at_mut(len / 2);
                let mut q = one;
                for (f, t) in f.iter_mut().zip(t.iter_mut()) {
                    let x = *f;
                    let y = q * *t;
                    *f = x + y;
                    *t = x - y;
                    q = q * zeta;
                }
            }
        }
    }
}
// ---------- end fast fourier transform ----------

#[allow(dead_code)]
mod complex {
    use std::ops::{Add, Mul, Sub};
    #[derive(Clone, Copy)]
    pub struct Complex {
        pub re: f64,
        pub im: f64,
    }
    impl Complex {
        pub fn new(re: f64, im: f64) -> Self {
            Complex { re: re, im: im }
        }
        pub fn zero() -> Self {
            Complex::new(0.0, 0.0)
        }
        pub fn one() -> Self {
            Complex::new(1.0, 0.0)
        }
        pub fn zeta(n: usize) -> Self {
            assert!(n > 0);
            let rad = 2.0 * std::f64::consts::PI / n as f64;
            Complex::new(rad.cos(), rad.sin())
        }
    }
    impl Add for Complex {
        type Output = Self;
        fn add(self, rhs: Self) -> Self::Output {
            Complex::new(self.re + rhs.re, self.im + rhs.im)
        }
    }
    impl Sub for Complex {
        type Output = Self;
        fn sub(self, rhs: Self) -> Self::Output {
            Complex::new(self.re - rhs.re, self.im - rhs.im)
        }
    }
    impl Mul for Complex {
        type Output = Self;
        fn mul(self, rhs: Self) -> Self::Output {
            Complex::new(
                self.re * rhs.re - self.im * rhs.im,
                self.re * rhs.im + self.im * rhs.re,
            )
        }
    }
}

#[allow(dead_code)]
mod array_operation {
    use std::ops::*;
    use std::marker::Copy;
    pub fn add<T: Add<Output = T> + Copy>(a: &[T], b: &[T]) -> Vec<T> {
        let mut c = Vec::with_capacity(std::cmp::max(a.len(), b.len()));
        if a.len() >= b.len() {
            c.extend_from_slice(a);
            add_assign(&mut c, b);
        } else {
            c.extend_from_slice(b);
            add_assign(&mut c, a);
        }
        c
    }
    pub fn sub<T: Sub<Output = T> + Neg<Output = T> + Copy>(a: &[T], b: &[T]) -> Vec<T> {
        let mut c = Vec::with_capacity(std::cmp::max(a.len(), b.len()));
        if a.len() >= b.len() {
            c.extend_from_slice(a);
            sub_assign(&mut c, b);
        } else {
            let (x, y) = b.split_at(a.len());
            for (a, b) in a.iter().zip(x.iter()) {
                c.push(*a - *b);
            }
            for y in y.iter() {
                c.push(-*y);
            }
        }
        c
    }
    pub fn mul<T: Mul<Output = T> + Copy>(a: &[T], b: &[T]) -> Vec<T> {
        let mut c = Vec::with_capacity(std::cmp::min(a.len(), b.len()));
        for (a, b) in a.iter().zip(b.iter()) {
            c.push(*a * *b);
        }
        c
    }
    pub fn add_assign<T: Add<Output = T> + Copy>(a: &mut [T], b: &[T]) {
        assert!(a.len() >= b.len());
        for (a, b) in a.iter_mut().zip(b.iter()) {
            *a = *a + *b;
        }
    }
    pub fn sub_assign<T: Sub<Output = T> + Copy>(a: &mut [T], b: &[T]) {
        assert!(a.len() >= b.len());
        for (a, b) in a.iter_mut().zip(b.iter()) {
            *a = *a - *b;
        }
    }
    pub fn scalar<T: Mul<Output = T> + Copy>(a: &[T], b: T) -> Vec<T> {
        a.iter().map(|a| *a * b).collect()
    }
}

fn convolution(a: &[f64], b: &[f64]) -> Vec<f64> {
    if a.is_empty() || b.is_empty() {
        return vec![];
    }
    let x = a.len();
    let y = b.len();
    let size = (x + y - 1).next_power_of_two();
    type Complex = complex::Complex;
    let mut f = vec![Complex::zero(); size];
    for (f, a) in f.iter_mut().zip(a.iter()) {
        f.re = *a;
    }
    let zeta = Complex::zeta(size);
    fft::fft(&mut f, zeta, Complex::one());
    let mut g = vec![Complex::zero(); size];
    for (g, b) in g.iter_mut().zip(b.iter()) {
        g.re = *b;
    }
    fft::fft(&mut g, zeta, Complex::one());
    for (f, g) in f.iter_mut().zip(g.iter()) {
        *f = *f * *g;
    }
    let izeta = Complex::new(zeta.re, -zeta.im);
    fft::fft(&mut f, izeta, Complex::one());
    let mut ans = vec![0f64; x + y - 1];
    let inv = 1.0 / size as f64;
    for (ans, f) in ans.iter_mut().zip(f.iter()) {
        *ans = f.re * inv;
    }
    ans
}

use std::io::Read;

// https://twitter.com/noshi91/status/1250799228315504646
// 

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let p: Vec<_> = (0..26).map(|_| it.next().unwrap().parse::<usize>().unwrap() - 1).collect();
    let s: Vec<_> = it.next().unwrap().chars().map(|c| c.to_digit(36).unwrap() as usize - 10).collect();
    let t: Vec<_> = it.next().unwrap().chars().map(|c| c.to_digit(36).unwrap() as usize - 10).collect();
    // end input
    let p: Vec<_> = s.iter().map(|s| p[*s]).collect();
    let s: Vec<_> = s.into_iter().rev().map(|s| s as f64).collect();
    let p: Vec<_> = p.into_iter().rev().map(|ps| ps as f64).collect();
    let t: Vec<_> = t.into_iter().map(|t| t as f64).collect();
    use array_operation::*;
    let t2 = mul(&t, &t);
    let t3 = mul(&t2, &t);
    let t4 = mul(&t3, &t);
    let s_p = add(&s, &p);
    let sp = mul(&s, &p);
    let mut res = vec![0.0; t.len() + s.len()];
    add_assign(&mut res, &scalar(&convolution(&s_p, &t3), -2.0));
    add_assign(&mut res, &convolution(&add(&scalar(&sp, 2.0), &mul(&s_p, &s_p)), &t2));
    add_assign(&mut res, &scalar(&convolution(&mul(&s_p, &sp), &t), -2.0));
    let sspp = s.iter().zip(p.iter()).map(|(s, p)| s.powi(2) * p.powi(2)).fold(0.0, |s, a| s + a);
    let mut t4 = t4;
    t4.push(0.0);
    for i in (0..(t4.len() - 1)).rev() {
        assert!(t4[i] > -1e-9);
        t4[i] += t4[i + 1];
    }
    let mut ans = String::new();
    for (t4, res) in t4.windows(s.len() + 1).zip(res.iter().skip(s.len() - 1)) {
        let val = t4[0] - t4[s.len()] + *res + sspp;
        if val < 0.5 {
            ans.push('1');
        } else {
            ans.push('0');
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}