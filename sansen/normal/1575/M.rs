// ---------- begin simple deque ----------
// vecdeque 
// size 
// front = back = 0
// push_front 
//
pub struct SimpleDeque<T> {
    data: Vec<T>,
    front: usize,
    back: usize,
}

impl<T> SimpleDeque<T>
where
    T: Copy + Default,
{
    pub fn new(size: usize) -> Self {
        Self {
            data: vec![T::default(); size],
            front: 0,
            back: 0,
        }
    }
    pub fn push_back(&mut self, v: T) {
        self.data[self.back] = v;
        self.back += 1;
    }
    pub fn pop_back(&mut self) -> Option<T> {
        if self.is_empty() {
            return None;
        }
        self.back -= 1;
        Some(self.data[self.back])
    }
    pub fn pop_front(&mut self) -> Option<T> {
        if self.is_empty() {
            return None;
        }
        self.front += 1;
        Some(self.data[self.front - 1])
    }
}

impl<T> SimpleDeque<T> {
    pub fn clear(&mut self) {
        self.front = 0;
        self.back = 0;
    }
    pub fn front(&self) -> Option<&T> {
        if self.is_empty() {
            return None;
        }
        Some(&self.data[self.front])
    }
    pub fn back(&self) -> Option<&T> {
        if self.is_empty() {
            return None;
        }
        Some(&self.data[self.back - 1])
    }
    pub fn get(&self, x: usize) -> Option<&T> {
        if x >= self.len() {
            return None;
        }
        Some(&self.data[self.front + x])
    }
    pub fn len(&self) -> usize {
        self.back - self.front
    }
    pub fn is_empty(&self) -> bool {
        self.front == self.back
    }
}

impl<T> std::ops::Index<usize> for SimpleDeque<T> {
    type Output = T;
    fn index(&self, pos: usize) -> &Self::Output {
        self.get(pos).expect("out of bounds access")
    }
}
// ---------- end simple deque ----------
// ---------- begin transpose ----------
fn transpose<T>(a: Vec<Vec<T>>) -> Vec<Vec<T>> {
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

fn run() {
    input! {
        h: usize,
        w: usize,
        s: [bytes; h + 1],
    }
    let inf = 2000i64.pow(2) * 2 + 1;
    let mut dp = vec![vec![inf; w + 1]; h + 1];
    for (dp, s) in dp.iter_mut().zip(&s) {
        for (dp, s) in dp.iter_mut().zip(s) {
            if *s == b'1' {
                *dp = 0;
            }
        }
    }
    for _ in 0..2 {
        let mut deq = SimpleDeque::new(dp[0].len());
        for dp in dp.iter_mut() {
            deq.clear();
            for (i, dp) in dp.iter().enumerate() {
                let i = i as i64;
                let (a, b) = (-2 * i, i * i + *dp);
                while deq.len() > 1 {
                    let len = deq.len();
                    let (c, d) = deq[len - 1];
                    let (e, f) = deq[len - 2];
                    if (b - d) * (e - a) <= (b - f) * (c - a) {
                        deq.pop_back();
                    } else {
                        break;
                    }
                }
                deq.push_back((a, b));
            }
            for (i, dp) in dp.iter_mut().enumerate() {
                let i = i as i64;
                while deq.len() > 1 {
                    let (a, b) = deq[0];
                    let (c, d) = deq[1];
                    if a * i + b >= c * i + d {
                        deq.pop_front();
                    } else {
                        break;
                    }
                }
                *dp = deq
                    .front()
                    .map(|p| p.0 * i + p.1 + i * i)
                    .unwrap();
            }
        }
        dp = transpose(dp);
    }
    let ans = dp.into_iter().flatten().sum::<i64>();
    println!("{}", ans);
}

fn main() {
    run();
}