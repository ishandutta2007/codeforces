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

fn read() -> (usize, usize, Vec<Vec<u32>>) {
    let mut s = String::new();
    use std::io::Read;
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace().flat_map(|s| s.parse::<u64>());
    let mut next = || it.next().unwrap();
    let h = next() as usize;
    let w = next() as usize;
    let a = next() as usize;
    let b = next() as usize;
    let mut g = next();
    let x = next();
    let y = next();
    let z = next();
    let mut s = vec![vec![0u32; w]; h];
    for s in s.iter_mut().flatten() {
        *s = g as u32;
        g = (g * x + y) % z;
    }
    (a, b, s)
}

fn run() {
    let (a, b, mut s) = read();
    for &len in [b, a].iter() {
        let mut deq = SimpleDeque::<(u32, usize)>::new(s[0].len());
        for s in s.iter_mut() {
            deq.clear();
            let mut res = vec![0; s.len() - len + 1];
            for (i, &s) in s.iter().enumerate() {
                while deq.back().map_or(false, |p| p.0 >= s) {
                    deq.pop_back();
                }
                deq.push_back((s, i));
                if i >= len - 1 {
                    if deq.front().unwrap().1 + len <= i {
                        deq.pop_front();
                    }
                    res[i - len + 1] = deq.front().unwrap().0;
                }
            }
            *s = res;
        }
        s = transpose(s);
    }
    let ans = s.into_iter().flatten().fold(0, |s, a| s + a as u64);
    println!("{}", ans);
}

fn main() {
    run();
}