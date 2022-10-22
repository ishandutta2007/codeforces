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
        assert!(x < self.size);
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
    fn bitwise_or(&self, rhs: &Self) -> Self {
        let (x, y) = if self.size >= rhs.size {(self, rhs)} else {(rhs, self)};
        let mut a = x.a.clone();
        for (a, y) in a.iter_mut().zip(y.a.iter()) {
            *a |= *y;
        }
        BitSet {
            size: x.size,
            a: a,
        }
    }
    fn bitwise_and(&self, rhs: &Self) -> Self {
        let (x, y) = if self.size <= rhs.size {(self, rhs)} else {(rhs, self)};
        let mut a = x.a.clone();
        for (a, y) in a.iter_mut().zip(y.a.iter()) {
            *a &= *y;
        }
        BitSet {
            size: x.size,
            a: a,
        }
    }
    fn bitwise_xor(&self, rhs: &Self) -> Self {
        let (x, y) = if self.size >= rhs.size {(self, rhs)} else {(rhs, self)};
        let mut a = x.a.clone();
        for (a, y) in a.iter_mut().zip(y.a.iter()) {
            *a ^= *y;
        }
        BitSet {
            size: x.size,
            a: a,
        }
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

use std::io::Read;
use std::io::Write;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let q: usize = it.next().unwrap().parse().unwrap();
    let len = 7000;
    let mut ini = vec![BitSet::new(len + 1); len + 1];
    for i in 1..=len {
        for j in (i..=len).step_by(i) {
            ini[j].set_at(i);
        }
    }
    let mut s = vec![];
    for i in 1..=len {
        let mut free = true;
        let mut j = 2;
        while j * j <= i {
            if i % (j * j) == 0 {
                free = false;
            }
            j += 1;
        }
        if free {
            s.push(i);
        }
    }
    let mut fold = vec![BitSet::new(len + 1); len + 1];
    for i in 1..=len {
        for &s in s.iter() {
            if s * i > len {
                break;
            }
            fold[i].set_at(s * i);
        }
    }
    let mut dp = vec![BitSet::new(len + 1); n + 1];
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for _ in 0..q {
        let op: u8 = it.next().unwrap().parse().unwrap();
        match op {
            1 => {
                let x: usize = it.next().unwrap().parse().unwrap();
                let v: usize = it.next().unwrap().parse().unwrap();
                dp[x] = ini[v].clone();
            },
            2 => {
                let x: usize = it.next().unwrap().parse().unwrap();
                let y: usize = it.next().unwrap().parse().unwrap();
                let z: usize = it.next().unwrap().parse().unwrap();
                dp[x] = dp[y].bitwise_xor(&dp[z]);
            },
            3 => {
                let x: usize = it.next().unwrap().parse().unwrap();
                let y: usize = it.next().unwrap().parse().unwrap();
                let z: usize = it.next().unwrap().parse().unwrap();
                dp[x] = dp[y].bitwise_and(&dp[z]);
            },
            4 => {
                let x: usize = it.next().unwrap().parse().unwrap();
                let v: usize = it.next().unwrap().parse().unwrap();
                let ans = dp[x].bitwise_and(&fold[v]).popcnt() & 1;
                write!(out, "{}", ans).ok();
            },
            _ => unreachable!(),
        }
    }
    writeln!(out, "").ok();
}

fn main() {
    run();
}