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

mod internal_math {
// remove this after dependencies has been added

#![allow(dead_code)]
use std::mem::swap;

/// # Arguments
/// * `m` `1 <= m`
///
/// # Returns
/// x mod m
/* const */
pub(crate) fn safe_mod(mut x: i64, m: i64) -> i64 {
    x %= m;
    if x < 0 {
        x += m;
    }
    x
}

/// Fast modular by barrett reduction
/// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
/// NOTE: reconsider after Ice Lake
pub(crate) struct Barrett {
    pub(crate) _m: u32,
    pub(crate) im: u64,
}

impl Barrett {
    /// # Arguments
    /// * `m` `1 <= m`
    /// (Note: `m <= 2^31` should also hold, which is undocumented in the original library.
    /// See the [pull reqeust commment](https://github.com/rust-lang-ja/ac-library-rs/pull/3#discussion_r484661007)
    /// for more details.)
    pub(crate) fn new(m: u32) -> Barrett {
        Barrett {
            _m: m,
            im: (-1i64 as u64 / m as u64).wrapping_add(1),
        }
    }

    /// # Returns
    /// `m`
    pub(crate) fn umod(&self) -> u32 {
        self._m
    }

    /// # Parameters
    /// * `a` `0 <= a < m`
    /// * `b` `0 <= b < m`
    ///
    /// # Returns
    /// a * b % m
    #[allow(clippy::many_single_char_names)]
    pub(crate) fn mul(&self, a: u32, b: u32) -> u32 {
        mul_mod(a, b, self._m, self.im)
    }
}

/// Calculates `a * b % m`.
///
/// * `a` `0 <= a < m`
/// * `b` `0 <= b < m`
/// * `m` `1 <= m <= 2^31`
/// * `im` = ceil(2^64 / `m`)
#[allow(clippy::many_single_char_names)]
pub(crate) fn mul_mod(a: u32, b: u32, m: u32, im: u64) -> u32 {
    // [1] m = 1
    // a = b = im = 0, so okay

    // [2] m >= 2
    // im = ceil(2^64 / m)
    // -> im * m = 2^64 + r (0 <= r < m)
    // let z = a*b = c*m + d (0 <= c, d < m)
    // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im
    // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2
    // ((ab * im) >> 64) == c or c + 1
    let mut z = a as u64;
    z *= b as u64;
    let x = (((z as u128) * (im as u128)) >> 64) as u64;
    let mut v = z.wrapping_sub(x.wrapping_mul(m as u64)) as u32;
    if m <= v {
        v = v.wrapping_add(m);
    }
    v
}

/// # Parameters
/// * `n` `0 <= n`
/// * `m` `1 <= m`
///
/// # Returns
/// `(x ** n) % m`
/* const */
#[allow(clippy::many_single_char_names)]
pub(crate) fn pow_mod(x: i64, mut n: i64, m: i32) -> i64 {
    if m == 1 {
        return 0;
    }
    let _m = m as u32;
    let mut r: u64 = 1;
    let mut y: u64 = safe_mod(x, m as i64) as u64;
    while n != 0 {
        if (n & 1) > 0 {
            r = (r * y) % (_m as u64);
        }
        y = (y * y) % (_m as u64);
        n >>= 1;
    }
    r as i64
}

/// Reference:
/// M. Forisek and J. Jancina,
/// Fast Primality Testing for Integers That Fit into a Machine Word
///
/// # Parameters
/// * `n` `0 <= n`
/* const */
pub(crate) fn is_prime(n: i32) -> bool {
    let n = n as i64;
    match n {
        _ if n <= 1 => return false,
        2 | 7 | 61 => return true,
        _ if n % 2 == 0 => return false,
        _ => {}
    }
    let mut d = n - 1;
    while d % 2 == 0 {
        d /= 2;
    }
    for &a in &[2, 7, 61] {
        let mut t = d;
        let mut y = pow_mod(a, t, n as i32);
        while t != n - 1 && y != 1 && y != n - 1 {
            y = y * y % n;
            t <<= 1;
        }
        if y != n - 1 && t % 2 == 0 {
            return false;
        }
    }
    true
}

// omitted
// template <int n> constexpr bool is_prime = is_prime_constexpr(n);

/// # Parameters
/// * `b` `1 <= b`
///
/// # Returns
/// (g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
/* const */
#[allow(clippy::many_single_char_names)]
pub(crate) fn inv_gcd(a: i64, b: i64) -> (i64, i64) {
    let a = safe_mod(a, b);
    if a == 0 {
        return (b, 0);
    }

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    let mut s = b;
    let mut t = a;
    let mut m0 = 0;
    let mut m1 = 1;

    while t != 0 {
        let u = s / t;
        s -= t * u;
        m0 -= m1 * u; // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        swap(&mut s, &mut t);
        swap(&mut m0, &mut m1);
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if m0 < 0 {
        m0 += b / s;
    }
    (s, m0)
}

/// Compile time (currently not) primitive root
/// @param m must be prime
/// @return primitive root (and minimum in now)
/* const */
pub(crate) fn primitive_root(m: i32) -> i32 {
    match m {
        2 => return 1,
        167_772_161 => return 3,
        469_762_049 => return 3,
        754_974_721 => return 11,
        998_244_353 => return 3,
        _ => {}
    }

    let mut divs = [0; 20];
    divs[0] = 2;
    let mut cnt = 1;
    let mut x = (m - 1) / 2;
    while x % 2 == 0 {
        x /= 2;
    }
    for i in (3..std::i32::MAX).step_by(2) {
        if i as i64 * i as i64 > x as i64 {
            break;
        }
        if x % i == 0 {
            divs[cnt] = i;
            cnt += 1;
            while x % i == 0 {
                x /= i;
            }
        }
    }
    if x > 1 {
        divs[cnt] = x;
        cnt += 1;
    }
    let mut g = 2;
    loop {
        if (0..cnt).all(|i| pow_mod(g, ((m - 1) / divs[i]) as i64, m) != 1) {
            break g as i32;
        }
        g += 1;
    }
}
// omitted
// template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

#[cfg(test)]
mod tests {
    #![allow(clippy::unreadable_literal)]
    #![allow(clippy::cognitive_complexity)]
    use crate::internal_math::{inv_gcd, is_prime, pow_mod, primitive_root, safe_mod, Barrett};
    use std::collections::HashSet;

    #[test]
    fn test_safe_mod() {
        assert_eq!(safe_mod(0, 3), 0);
        assert_eq!(safe_mod(1, 3), 1);
        assert_eq!(safe_mod(2, 3), 2);
        assert_eq!(safe_mod(3, 3), 0);
        assert_eq!(safe_mod(4, 3), 1);
        assert_eq!(safe_mod(5, 3), 2);
        assert_eq!(safe_mod(73, 11), 7);
        assert_eq!(safe_mod(2306249155046129918, 6620319213327), 1374210749525);

        assert_eq!(safe_mod(-1, 3), 2);
        assert_eq!(safe_mod(-2, 3), 1);
        assert_eq!(safe_mod(-3, 3), 0);
        assert_eq!(safe_mod(-4, 3), 2);
        assert_eq!(safe_mod(-5, 3), 1);
        assert_eq!(safe_mod(-7170500492396019511, 777567337), 333221848);
    }

    #[test]
    fn test_barrett() {
        let b = Barrett::new(7);
        assert_eq!(b.umod(), 7);
        assert_eq!(b.mul(2, 3), 6);
        assert_eq!(b.mul(4, 6), 3);
        assert_eq!(b.mul(5, 0), 0);

        let b = Barrett::new(998244353);
        assert_eq!(b.umod(), 998244353);
        assert_eq!(b.mul(2, 3), 6);
        assert_eq!(b.mul(3141592, 653589), 919583920);
        assert_eq!(b.mul(323846264, 338327950), 568012980);

        // make `z - x * self._m as u64` overflow.
        // Thanks @koba-e964 (at https://github.com/rust-lang-ja/ac-library-rs/pull/3#discussion_r484932161)
        let b = Barrett::new(2147483647);
        assert_eq!(b.umod(), 2147483647);
        assert_eq!(b.mul(1073741824, 2147483645), 2147483646);
    }

    #[test]
    fn test_pow_mod() {
        assert_eq!(pow_mod(0, 0, 1), 0);
        assert_eq!(pow_mod(0, 0, 3), 1);
        assert_eq!(pow_mod(0, 0, 723), 1);
        assert_eq!(pow_mod(0, 0, 998244353), 1);
        assert_eq!(pow_mod(0, 0, i32::max_value()), 1);

        assert_eq!(pow_mod(0, 1, 1), 0);
        assert_eq!(pow_mod(0, 1, 3), 0);
        assert_eq!(pow_mod(0, 1, 723), 0);
        assert_eq!(pow_mod(0, 1, 998244353), 0);
        assert_eq!(pow_mod(0, 1, i32::max_value()), 0);

        assert_eq!(pow_mod(0, i64::max_value(), 1), 0);
        assert_eq!(pow_mod(0, i64::max_value(), 3), 0);
        assert_eq!(pow_mod(0, i64::max_value(), 723), 0);
        assert_eq!(pow_mod(0, i64::max_value(), 998244353), 0);
        assert_eq!(pow_mod(0, i64::max_value(), i32::max_value()), 0);

        assert_eq!(pow_mod(1, 0, 1), 0);
        assert_eq!(pow_mod(1, 0, 3), 1);
        assert_eq!(pow_mod(1, 0, 723), 1);
        assert_eq!(pow_mod(1, 0, 998244353), 1);
        assert_eq!(pow_mod(1, 0, i32::max_value()), 1);

        assert_eq!(pow_mod(1, 1, 1), 0);
        assert_eq!(pow_mod(1, 1, 3), 1);
        assert_eq!(pow_mod(1, 1, 723), 1);
        assert_eq!(pow_mod(1, 1, 998244353), 1);
        assert_eq!(pow_mod(1, 1, i32::max_value()), 1);

        assert_eq!(pow_mod(1, i64::max_value(), 1), 0);
        assert_eq!(pow_mod(1, i64::max_value(), 3), 1);
        assert_eq!(pow_mod(1, i64::max_value(), 723), 1);
        assert_eq!(pow_mod(1, i64::max_value(), 998244353), 1);
        assert_eq!(pow_mod(1, i64::max_value(), i32::max_value()), 1);

        assert_eq!(pow_mod(i64::max_value(), 0, 1), 0);
        assert_eq!(pow_mod(i64::max_value(), 0, 3), 1);
        assert_eq!(pow_mod(i64::max_value(), 0, 723), 1);
        assert_eq!(pow_mod(i64::max_value(), 0, 998244353), 1);
        assert_eq!(pow_mod(i64::max_value(), 0, i32::max_value()), 1);

        assert_eq!(pow_mod(i64::max_value(), i64::max_value(), 1), 0);
        assert_eq!(pow_mod(i64::max_value(), i64::max_value(), 3), 1);
        assert_eq!(pow_mod(i64::max_value(), i64::max_value(), 723), 640);
        assert_eq!(
            pow_mod(i64::max_value(), i64::max_value(), 998244353),
            683296792
        );
        assert_eq!(
            pow_mod(i64::max_value(), i64::max_value(), i32::max_value()),
            1
        );

        assert_eq!(pow_mod(2, 3, 1_000_000_007), 8);
        assert_eq!(pow_mod(5, 7, 1_000_000_007), 78125);
        assert_eq!(pow_mod(123, 456, 1_000_000_007), 565291922);
    }

    #[test]
    fn test_is_prime() {
        assert!(!is_prime(0));
        assert!(!is_prime(1));
        assert!(is_prime(2));
        assert!(is_prime(3));
        assert!(!is_prime(4));
        assert!(is_prime(5));
        assert!(!is_prime(6));
        assert!(is_prime(7));
        assert!(!is_prime(8));
        assert!(!is_prime(9));

        // assert!(is_prime(57));
        assert!(!is_prime(57));
        assert!(!is_prime(58));
        assert!(is_prime(59));
        assert!(!is_prime(60));
        assert!(is_prime(61));
        assert!(!is_prime(62));

        assert!(!is_prime(701928443));
        assert!(is_prime(998244353));
        assert!(!is_prime(1_000_000_000));
        assert!(is_prime(1_000_000_007));

        assert!(is_prime(i32::max_value()));
    }

    #[test]
    fn test_is_prime_sieve() {
        let n = 1_000_000;
        let mut prime = vec![true; n];
        prime[0] = false;
        prime[1] = false;
        for i in 0..n {
            assert_eq!(prime[i], is_prime(i as i32));
            if prime[i] {
                for j in (2 * i..n).step_by(i) {
                    prime[j] = false;
                }
            }
        }
    }

    #[test]
    fn test_inv_gcd() {
        for &(a, b, g) in &[
            (0, 1, 1),
            (0, 4, 4),
            (0, 7, 7),
            (2, 3, 1),
            (-2, 3, 1),
            (4, 6, 2),
            (-4, 6, 2),
            (13, 23, 1),
            (57, 81, 3),
            (12345, 67890, 15),
            (-3141592 * 6535, 3141592 * 8979, 3141592),
            (i64::max_value(), i64::max_value(), i64::max_value()),
            (i64::min_value(), i64::max_value(), 1),
        ] {
            let (g_, x) = inv_gcd(a, b);
            assert_eq!(g, g_);
            let b_ = b as i128;
            assert_eq!(((x as i128 * a as i128) % b_ + b_) % b_, g as i128 % b_);
        }
    }

    #[test]
    fn test_primitive_root() {
        for &p in &[
            2,
            3,
            5,
            7,
            233,
            200003,
            998244353,
            1_000_000_007,
            i32::max_value(),
        ] {
            assert!(is_prime(p));
            let g = primitive_root(p);
            if p != 2 {
                assert_ne!(g, 1);
            }

            let q = p - 1;
            for i in (2..i32::max_value()).take_while(|i| i * i <= q) {
                if q % i != 0 {
                    break;
                }
                for &r in &[i, q / i] {
                    assert_ne!(pow_mod(g as i64, r as i64, p), 1);
                }
            }
            assert_eq!(pow_mod(g as i64, q as i64, p), 1);

            if p < 1_000_000 {
                assert_eq!(
                    (0..p - 1)
                        .scan(1, |i, _| {
                            *i = *i * g % p;
                            Some(*i)
                        })
                        .collect::<HashSet<_>>()
                        .len() as i32,
                    p - 1
                );
            }
        }
    }
}
}

use internal_math::*;

use std::mem::swap;

/// Returns $x^n \bmod m$.
///
/// # Constraints
///
/// - $0 \leq n$
/// - $1 \leq m$
///
/// # Panics
///
/// Panics if the above constraints are not satisfied.
///
/// # Complexity
///
/// - $O(\log n)$
///
/// # Example
///
/// ```
/// use ac_library_rs::math;
///
/// assert_eq!(math::pow_mod(2, 10000, 7), 2);
/// ```
#[allow(clippy::many_single_char_names)]
pub fn pow_mod(x: i64, mut n: i64, m: u32) -> u32 {
    assert!(0 <= n && 1 <= m && m <= 2u32.pow(31));
    if m == 1 {
        return 0;
    }
    let bt = internal_math::Barrett::new(m);
    let mut r = 1;
    let mut y = internal_math::safe_mod(x, m as i64) as u32;
    while n != 0 {
        if n & 1 != 0 {
            r = bt.mul(r, y);
        }
        y = bt.mul(y, y);
        n >>= 1;
    }
    r
}

/// Returns an integer $y \in [0, m)$ such that $xy \equiv 1 \pmod m$.
///
/// # Constraints
///
/// - $\gcd(x, m) = 1$
/// - $1 \leq m$
///
/// # Panics
///
/// Panics if the above constraints are not satisfied.
///
/// # Complexity
///
/// - $O(\log m)$
///
/// # Example
///
/// ```
/// use ac_library_rs::math;
///
/// assert_eq!(math::inv_mod(3, 7), 5);
/// ```
pub fn inv_mod(x: i64, m: i64) -> i64 {
    assert!(1 <= m);
    let z = internal_math::inv_gcd(x, m);
    assert!(z.0 == 1);
    z.1
}

/// Performs CRT (Chinese Remainder Theorem).
///
/// Given two sequences $r, m$ of length $n$, this function solves the modular equation system
///
/// \\[
///   x \equiv r_i \pmod{m_i}, \forall i \in \\{0, 1, \cdots, n - 1\\}
/// \\]
///
/// If there is no solution, it returns $(0, 0)$.
///
/// Otherwise, all of the solutions can be written as the form $x \equiv y \pmod z$, using integer $y, z\\ (0 \leq y < z = \text{lcm}(m))$.
/// It returns this $(y, z)$.
///
/// If $n = 0$, it returns $(0, 1)$.
///
/// # Constraints
///
/// - $|r| = |m|$
/// - $1 \leq m_{\forall i}$
/// - $\text{lcm}(m)$ is in `i64`
///
/// # Panics
///
/// Panics if the above constraints are not satisfied.
///
/// # Complexity
///
/// - $O(n \log \text{lcm}(m))$
///
/// # Example
///
/// ```
/// use ac_library_rs::math;
///
/// let r = [2, 3, 2];
/// let m = [3, 5, 7];
/// assert_eq!(math::crt(&r, &m), (23, 105));
/// ```
pub fn crt(r: &[i64], m: &[i64]) -> (i64, i64) {
    assert_eq!(r.len(), m.len());
    // Contracts: 0 <= r0 < m0
    let (mut r0, mut m0) = (0, 1);
    for (&(mut ri), &(mut mi)) in r.iter().zip(m.iter()) {
        assert!(1 <= mi);
        ri = internal_math::safe_mod(ri, mi);
        if m0 < mi {
            swap(&mut r0, &mut ri);
            swap(&mut m0, &mut mi);
        }
        if m0 % mi == 0 {
            if r0 % mi != ri {
                return (0, 0);
            }
            continue;
        }
        // assume: m0 > mi, lcm(m0, mi) >= 2 * max(m0, mi)

        // (r0, m0), (ri, mi) -> (r2, m2 = lcm(m0, m1));
        // r2 % m0 = r0
        // r2 % mi = ri
        // -> (r0 + x*m0) % mi = ri
        // -> x*u0*g % (u1*g) = (ri - r0) (u0*g = m0, u1*g = mi)
        // -> x = (ri - r0) / g * inv(u0) (mod u1)

        // im = inv(u0) (mod u1) (0 <= im < u1)
        let (g, im) = internal_math::inv_gcd(m0, mi);
        let u1 = mi / g;
        // |ri - r0| < (m0 + mi) <= lcm(m0, mi)
        if (ri - r0) % g != 0 {
            return (0, 0);
        }
        // u1 * u1 <= mi * mi / g / g <= m0 * mi / g = lcm(m0, mi)
        let x = (ri - r0) / g % u1 * im % u1;

        // |r0| + |m0 * x|
        // < m0 + m0 * (u1 - 1)
        // = m0 + m0 * mi / g - m0
        // = lcm(m0, mi)
        r0 += x * m0;
        m0 *= u1; // -> lcm(m0, mi)
        if r0 < 0 {
            r0 += m0
        };
    }

    (r0, m0)
}

/// Returns $\sum_{i = 0}^{n - 1} \lfloor \frac{a \times i + b}{m} \rfloor$.
///
/// # Constraints
///
/// - $0 \leq n \leq 10^9$
/// - $1 \leq m \leq 10^9$
/// - $0 \leq a, b \leq m$
///
/// # Panics
///
/// Panics if the above constraints are not satisfied and overflow or division by zero occurred.
///
/// # Complexity
///
/// - $O(\log(n + m + a + b))$
///
/// # Example
///
/// ```
/// use ac_library_rs::math;
///
/// assert_eq!(math::floor_sum(6, 5, 4, 3), 13);
/// ```
pub fn floor_sum(n: i64, m: i64, mut a: i64, mut b: i64) -> i64 {
    let mut ans = 0;
    if a >= m {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if b >= m {
        ans += n * (b / m);
        b %= m;
    }

    let y_max = (a * n + b) / m;
    let x_max = y_max * m - b;
    if y_max == 0 {
        return ans;
    }
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    ans
}

#[cfg(test)]
mod tests {
    #![allow(clippy::unreadable_literal)]
    #![allow(clippy::cognitive_complexity)]
    use super::*;
    #[test]
    fn test_pow_mod() {
        assert_eq!(pow_mod(0, 0, 1), 0);
        assert_eq!(pow_mod(0, 0, 3), 1);
        assert_eq!(pow_mod(0, 0, 723), 1);
        assert_eq!(pow_mod(0, 0, 998244353), 1);
        assert_eq!(pow_mod(0, 0, 2u32.pow(31)), 1);

        assert_eq!(pow_mod(0, 1, 1), 0);
        assert_eq!(pow_mod(0, 1, 3), 0);
        assert_eq!(pow_mod(0, 1, 723), 0);
        assert_eq!(pow_mod(0, 1, 998244353), 0);
        assert_eq!(pow_mod(0, 1, 2u32.pow(31)), 0);

        assert_eq!(pow_mod(0, i64::max_value(), 1), 0);
        assert_eq!(pow_mod(0, i64::max_value(), 3), 0);
        assert_eq!(pow_mod(0, i64::max_value(), 723), 0);
        assert_eq!(pow_mod(0, i64::max_value(), 998244353), 0);
        assert_eq!(pow_mod(0, i64::max_value(), 2u32.pow(31)), 0);

        assert_eq!(pow_mod(1, 0, 1), 0);
        assert_eq!(pow_mod(1, 0, 3), 1);
        assert_eq!(pow_mod(1, 0, 723), 1);
        assert_eq!(pow_mod(1, 0, 998244353), 1);
        assert_eq!(pow_mod(1, 0, 2u32.pow(31)), 1);

        assert_eq!(pow_mod(1, 1, 1), 0);
        assert_eq!(pow_mod(1, 1, 3), 1);
        assert_eq!(pow_mod(1, 1, 723), 1);
        assert_eq!(pow_mod(1, 1, 998244353), 1);
        assert_eq!(pow_mod(1, 1, 2u32.pow(31)), 1);

        assert_eq!(pow_mod(1, i64::max_value(), 1), 0);
        assert_eq!(pow_mod(1, i64::max_value(), 3), 1);
        assert_eq!(pow_mod(1, i64::max_value(), 723), 1);
        assert_eq!(pow_mod(1, i64::max_value(), 998244353), 1);
        assert_eq!(pow_mod(1, i64::max_value(), 2u32.pow(31)), 1);

        assert_eq!(pow_mod(i64::max_value(), 0, 1), 0);
        assert_eq!(pow_mod(i64::max_value(), 0, 3), 1);
        assert_eq!(pow_mod(i64::max_value(), 0, 723), 1);
        assert_eq!(pow_mod(i64::max_value(), 0, 998244353), 1);
        assert_eq!(pow_mod(i64::max_value(), 0, 2u32.pow(31)), 1);

        assert_eq!(pow_mod(i64::max_value(), i64::max_value(), 1), 0);
        assert_eq!(pow_mod(i64::max_value(), i64::max_value(), 3), 1);
        assert_eq!(pow_mod(i64::max_value(), i64::max_value(), 723), 640);
        assert_eq!(
            pow_mod(i64::max_value(), i64::max_value(), 998244353),
            683296792
        );
        assert_eq!(
            pow_mod(i64::max_value(), i64::max_value(), 2u32.pow(31)),
            2147483647
        );

        assert_eq!(pow_mod(2, 3, 1_000_000_007), 8);
        assert_eq!(pow_mod(5, 7, 1_000_000_007), 78125);
        assert_eq!(pow_mod(123, 456, 1_000_000_007), 565291922);
    }

    #[test]
    #[should_panic]
    fn test_inv_mod_1() {
        inv_mod(271828, 0);
    }

    #[test]
    #[should_panic]
    fn test_inv_mod_2() {
        inv_mod(3141592, 1000000008);
    }

    #[test]
    fn test_crt() {
        let a = [44, 23, 13];
        let b = [13, 50, 22];
        assert_eq!(crt(&a, &b), (1773, 7150));
        let a = [12345, 67890, 99999];
        let b = [13, 444321, 95318];
        assert_eq!(crt(&a, &b), (103333581255, 550573258014));
        let a = [0, 3, 4];
        let b = [1, 9, 5];
        assert_eq!(crt(&a, &b), (39, 45));
    }

    #[test]
    fn test_floor_sum() {
        assert_eq!(floor_sum(0, 1, 0, 0), 0);
        assert_eq!(floor_sum(1_000_000_000, 1, 1, 1), 500_000_000_500_000_000);
        assert_eq!(
            floor_sum(1_000_000_000, 1_000_000_000, 999_999_999, 999_999_999),
            499_999_999_500_000_000
        );
        assert_eq!(floor_sum(332955, 5590132, 2231, 999423), 22014575);
    }
}

fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        k: i64,
        a: [usize; n],
        b: [usize; m],
    }
    let w = 2 * n.max(m) + 1;
    let mut ia = vec![w; w];
    for (i, a) in a.iter().enumerate() {
        ia[*a] = i;
    }
    let mut ib = vec![w; w];
    for (i, b) in b.iter().enumerate() {
        ib[*b] = i;
    }
    let g = gcd(n as i64, m as i64);
    let lcm = n as i64 * m as i64 / g;
    let mut x = vec![];
    for (&a, &b) in ia.iter().zip(ib.iter()) {
        if a == w || b == w {
            continue;
        }
        let (p, q) = crt(&[a as i64, b as i64], &[n as i64, m as i64]);
        if (p, q) == (0, 0) {
            continue;
        }
        assert!(p % n as i64 == a as i64 && p % m as i64 == b as i64 && p < lcm);
        x.push((p, a, b));
    }
    let mut ok = 0;
    let mut ng = 10i64.pow(18);
    while ng - ok > 1 {
        let mid = (ok + ng) / 2;
        let mut diff = mid;
        for &(p, a, b) in x.iter() {
            if mid > p {
                diff -= (mid - p - 1) / lcm + 1;
            }
        }
        if diff < k {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    println!("{}", ng);
}

fn main() {
    run();
}