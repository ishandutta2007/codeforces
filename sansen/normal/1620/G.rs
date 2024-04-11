// ---------- begin bitwise transform ----------
#[target_feature(enable = "avx2")]
unsafe fn bitwise_transform<T, F>(a: &mut [T], mut f: F)
where
    F: FnMut(&mut T, &mut T)
{
    let n = a.len().trailing_zeros() as usize;
    assert!(a.len() == 1 << n);
    for i in 0..n {
        for a in a.chunks_exact_mut(2 << i) {
            let (x, y) = a.split_at_mut(1 << i);
            for (x, y) in x.iter_mut().zip(y) {
                f(x, y);
            }
        }
    }
}
// ---------- end bitwise transform ----------

const MOD: u32 = 998_244_353;

fn add(mut a: u32, b: u32) -> u32 {
    a += b;
    if a >= MOD {
        a -= MOD;
    }
    a
}

fn sub(a: u32, b: u32) -> u32 {
    let mut d = a - b;
    if a < b {
        d += MOD;
    }
    d
}

fn mul(a: u32, b: u32) -> u32 {
    (a as u64 * b as u64 % MOD as u64) as u32
}

fn read() -> Vec<Vec<u16>> {
    let mut s = String::new();
    use std::io::*;
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    it.next();
    let mut cnt = vec![vec![]; 26];
    for s in it {
        let mut s = s.bytes().map(|s| (s, 1u16)).collect::<Vec<_>>();
        s.extend((b'a'..=b'z').map(|c| (c, 1)));
        s.sort();
        s.dedup_by(|a, b| a.0 == b.0 && {
            b.1 += a.1;
            true
        });
        for (cnt, c) in cnt.iter_mut().zip(s) {
            cnt.push(c.1);
        }
    }
    cnt
}

#[target_feature(enable = "avx2")]
unsafe fn run() {
    let cnt = read();
    let n = cnt[0].len();
    let mut dp = vec![1; 1 << n];
    let mut min = vec![!0u16; 1 << n];
    for cnt in cnt {
        for (i, c) in cnt.iter().enumerate() {
            let (f, t) = min.split_at_mut(1 << i);
            for (t, f) in t.iter_mut().zip(f) {
                *t = std::cmp::min(*c, *f);
            }
        }
        for (dp, cnt) in dp.iter_mut().zip(&min) {
            *dp = mul(*dp, *cnt as u32);
        }
    }
    bitwise_transform(&mut dp, |a, b| *a = sub(*a, *b));
    dp[0] = 0;
    let all = dp.iter().fold(0, |s, a| add(s, *a));
    let mask = (1 << n) - 1;
    bitwise_transform(&mut dp, |a, b| *b = add(*a, *b));
    let mut ans = 0;
    for (i, dp) in dp.iter().enumerate() {
        let i = i ^ mask;
        let k = i.count_ones();
        let mut s = 0;
        for j in 0..n {
            s += (i >> j & 1) * (j + 1);
        }
        ans ^= k as u64 * s as u64 * sub(all, *dp) as u64;
    }
    println!("{}", ans);
}

fn main() {
    unsafe {
        run();
    }
}