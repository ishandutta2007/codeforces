// ---------- begin BitSet ----------
#[derive(Clone)]
struct BitSet {
    size: usize,
    a: Vec<usize>,
}

fn bit_size() -> usize {
    8 * std::mem::size_of::<usize>()
}

fn quot_rem(n: usize) -> (usize, usize) {
    let w = bit_size();
    (n / w, n % w)
}

#[allow(dead_code)]
impl BitSet {
    fn new(size: usize) -> Self {
        let w = bit_size();
        BitSet {
            size: size,
            a: vec![0; (size + w - 1) / w],
        }
    }
    fn set_at(&mut self, x: usize) {
        assert!(x < self.size);
        let (q, r) = quot_rem(x);
        self.a[q] |= 1 << r;
    }
    fn clear_at(&mut self, x: usize) {
        assert!(x < self.size);
        let (q, r) = quot_rem(x);
        self.a[q] &= !(1 << r);
    }
    fn get_at(&self, x: usize) -> bool {
        if x >= self.size {
            return false;
        }
        let (q, r) = quot_rem(x);
        (self.a[q] >> r) & 1 == 1
    }
    fn any(&self) -> bool {
        self.a.iter().any(|a| *a != 0)
    }
    fn fix(&mut self) {
        let (q, r) = quot_rem(self.size);
        if r != 0 {
            self.a[q] &= (1 << r) - 1;
        }
    }
    fn clear(&mut self) {
        let len = self.a.len();
        self.a.clear();
        self.a.resize(len, 0);
    }
    fn truncate(&mut self, len: usize) {
        if len >= self.size {
            return;
        }
        let w = bit_size();
        self.a.truncate((len + w - 1) / w);
        self.size = len;
        self.fix();
    }
    fn popcnt(&self) -> usize {
        self.a.iter().fold(0, |s, a| s + a.count_ones() as usize)
    }
    fn shift_left(&self, rhs: usize) -> Self {
        let (q, r) = quot_rem(rhs);
        let mut ans = BitSet::new(self.size + rhs);
        if r == 0 {
            for (x, y) in ans.a[q..].iter_mut().zip(self.a.iter()) {
                *x = *y;
            }
        } else {
            let w = bit_size();
            let mut prev = 0;
            for (x, y) in ans.a[q..].iter_mut().zip(self.a.iter()) {
                *x = (*y << r) | (prev >> (w - r));
                prev = *y;
            }
            *ans.a.last_mut().unwrap() |= prev >> (w - r);
        }
        ans.fix();
        ans
    }
    fn shift_right(&self, rhs: usize) -> Self {
        if rhs >= self.size {
            return BitSet::new(1);
        }
        let (q, r) = quot_rem(rhs);
        let mut ans = BitSet::new(self.size - rhs);
        if r == 0 {
            for (x, y) in ans.a.iter_mut().zip(self.a[q..].iter()) {
                *x = *y;
            }
        } else {
            let w = bit_size();
            let mut prev = 0;
            for (x, y) in ans.a.iter_mut().zip(self.a[q..].iter()).rev() {
                *x |= (*y >> r) | (prev << (w - r));
                prev = *y;
            }
        }
        ans.fix();
        ans
    }
    fn bitwise_or(&self, rhs: &Self) -> Self {
        let (x, y) = if self.size >= rhs.size {
            (self, rhs)
        } else {
            (rhs, self)
        };
        let mut a = x.a.clone();
        for (a, y) in a.iter_mut().zip(y.a.iter()) {
            *a |= *y;
        }
        BitSet { size: x.size, a: a }
    }
    fn bitwise_and(&self, rhs: &Self) -> Self {
        let (x, y) = if self.size <= rhs.size {
            (self, rhs)
        } else {
            (rhs, self)
        };
        let mut a = x.a.clone();
        for (a, y) in a.iter_mut().zip(y.a.iter()) {
            *a &= *y;
        }
        BitSet { size: x.size, a: a }
    }
    fn bitwise_xor(&self, rhs: &Self) -> Self {
        let (x, y) = if self.size >= rhs.size {
            (self, rhs)
        } else {
            (rhs, self)
        };
        let mut a = x.a.clone();
        for (a, y) in a.iter_mut().zip(y.a.iter()) {
            *a ^= *y;
        }
        BitSet { size: x.size, a: a }
    }
    fn bitwise_or_assign(&mut self, rhs: &Self) {
        if self.size < rhs.size {
            self.size = rhs.size;
            self.a.resize(rhs.a.len(), 0);
        }
        for (a, b) in self.a.iter_mut().zip(rhs.a.iter()) {
            *a |= *b;
        }
    }
    fn bitwise_and_assign(&mut self, rhs: &Self) {
        if self.size > rhs.size {
            self.size = rhs.size;
            self.a.resize(rhs.a.len(), 0);
        }
        for (a, b) in self.a.iter_mut().zip(rhs.a.iter()) {
            *a &= *b;
        }
    }
    fn bitwise_xor_assign(&mut self, rhs: &Self) {
        if self.size < rhs.size {
            self.size = rhs.size;
            self.a.resize(rhs.a.len(), 0);
        }
        for (a, b) in self.a.iter_mut().zip(rhs.a.iter()) {
            *a ^= *b;
        }
    }
}
// ---------- end BitSet ----------
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
// 
// 
// 
//
// 
// a k 
// a(k - i) * a 
// bitset?

fn calc(a: &[(usize, usize)], dp: &[BitSet]) -> usize {
    let n = a.len();
    if n == 1 {
        let (a, c) = a[0];
        let mut ans = 1;
        for k in 2..=c {
            let mut ok = true;
            for j in 0..k {
                ok &= !dp[k - j].get_at(a * (k - j));
            }
            if ok {
                ans = k;
            }
        }
        return ans;
    }
    let (l, r) = a.split_at(n / 2);
    let mut p = vec![];
    p.extend_from_slice(dp);
    for &(a, c) in l.iter() {
        for _ in 0..c {
            for i in (1..dp.len()).rev() {
                let mut set = p[i].bitwise_or(&p[i - 1].shift_left(a));
                set.truncate(dp[0].size);
                p[i] = set;
            }
        }
    }
    let a = calc(r, &p);
    let mut p = vec![];
    p.extend_from_slice(dp);
    for &(a, c) in r.iter() {
        for _ in 0..c {
            for i in (1..dp.len()).rev() {
                let mut set = p[i].bitwise_or(&p[i - 1].shift_left(a));
                set.truncate(dp[0].size);
                p[i] = set;
            }
        }
    }
    std::cmp::max(a, calc(l, &p))
}

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let mut a = a.into_iter().map(|a| (a, 1)).collect::<Vec<_>>();
    a.sort();
    a.dedup_by(|a, b| {
        a.0 == b.0 && {
            b.1 += a.1;
            true
        }
    });
    if a.len() <= 2 {
        println!("{}", n);
        return;
    }
    let w = n * 100;
    let mut dp = vec![BitSet::new(w + 1); n + 1];
    dp[0].set_at(0);
    let ans = calc(&a, &dp);
    println!("{}", ans);
}

fn main() {
    run();
}