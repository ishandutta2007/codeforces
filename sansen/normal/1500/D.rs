// 
// 
// new(size, zero): zerosize
// init(&mut self): 
// index(mut) 
// 
//
// 
// 1. deref  data
//    derefmut 
// 2. 
//    , trait
// ---------- begin init array ----------
pub struct InitArray<T> {
    data: Vec<T>,
    used: Vec<bool>,
    list: Vec<usize>,
    zero: T,
}

impl<T: Copy> InitArray<T> {
    pub fn new(size: usize, zero: T) -> Self {
        InitArray {
            data: vec![zero; size],
            used: vec![false; size],
            list: vec![],
            zero: zero,
        }
    }
    pub fn init(&mut self) {
        for x in self.list.drain(..) {
            self.used[x] = false;
            self.data[x] = self.zero;
        }
    }
}

impl<T> std::ops::Index<usize> for InitArray<T> {
    type Output = T;
    fn index(&self, pos: usize) -> &Self::Output {
        &self.data[pos]
    }
}

impl<T> std::ops::IndexMut<usize> for InitArray<T> {
    fn index_mut(&mut self, pos: usize) -> &mut Self::Output {
        if !self.used[pos] {
            self.used[pos] = true;
            self.list.push(pos);
        }
        &mut self.data[pos]
    }
}
// ---------- end init array ----------
// ---------- begin Foldable Qeque ----------
pub struct FoldableQueue<T, F> {
    front: Vec<(T, T)>,
    back: Vec<(T, T)>,
    op: F,
}

impl<T, F> FoldableQueue<T, F>
where
    T: Clone,
    F: Fn(&T, &T) -> T,
{
    pub fn new(op: F) -> Self {
        FoldableQueue {
            front: Vec::new(),
            back: Vec::new(),
            op: op,
        }
    }
    pub fn find(&self) -> Option<T> {
        match (self.front.last(), self.back.last()) {
            (Some(a), Some(b)) => Some((self.op)(&a.1, &b.1)),
            (x, y) => x.or(y).map(|p| p.1.clone()),
        }
    }
    pub fn clear(&mut self) {
        self.front.clear();
        self.back.clear();
    }
    pub fn len(&self) -> usize {
        self.front.len() + self.back.len()
    }
    pub fn push_back(&mut self, val: T) {
        let sum = self
            .back
            .last()
            .map_or_else(|| val.clone(), |p| (self.op)(&p.1, &val));
        self.back.push((val, sum));
    }
    pub fn pop_front(&mut self) -> Option<T> {
        if self.front.is_empty() {
            let mut back = std::mem::take(&mut self.back);
            for (v, _) in back.drain(..).rev() {
                let sum = self
                    .front
                    .last()
                    .map_or_else(|| v.clone(), |p| (self.op)(&v, &p.1));
                self.front.push((v, sum));
            }
            self.back = back;
        }
        self.front.pop().map(|p| p.0)
    }
}
// ---------- end Foldable Qeque ----------



fn read() -> (usize, Vec<Vec<usize>>) {
    let mut s = String::new();
    use std::io::Read;
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace().flat_map(|s| s.parse::<usize>());
    let mut next = || it.next().unwrap();
    let n = next();
    let q = next();
    let mut a = vec![vec![0; n]; n];
    for a in a.iter_mut().flatten() {
        *a = next() - 1;
    }
    (q, a)
}

fn run() {
    let (q, a) = read();
    let n = a.len();
    const SIZE: usize = 11;
    let elem = std::cell::RefCell::new(InitArray::new(n * n + SIZE, false));
    type Value = [(usize, usize); SIZE];
    let merge = |a: &Value, b: &Value| -> Value {
        let mut elem = elem.borrow_mut();
        elem.init();
        let mut i = 0;
        let mut j = 0;
        let mut res = [(0, 0); SIZE];
        let mut k = 0;
        while i < SIZE && j < SIZE && k < SIZE {
            if a[i] < b[j] {
                if !elem[a[i].1] {
                    elem[a[i].1] = true;
                    res[k] = a[i];
                    k += 1;
                }
                i += 1;
            } else {
                if !elem[b[j].1] {
                    elem[b[j].1] = true;
                    res[k] = b[j];
                    k += 1;
                }
                j += 1;
            }
        }
        while k < SIZE {
            if i < SIZE {
                if !elem[a[i].1] {
                    elem[a[i].1] = true;
                    res[k] = a[i];
                    k += 1;
                }
                i += 1;
            } else {
                if !elem[b[j].1] {
                    elem[b[j].1] = true;
                    res[k] = b[j];
                    k += 1;
                }
                j += 1;
            }
        }
        res
    };
    let mut dp = vec![[(0, 0); SIZE]; n];
    for dp in dp.iter_mut() {
        for (i, dp) in dp.iter_mut().enumerate() {
            *dp = (n, n * n + i);
        }
    }
    let mut ans = vec![0; n + 1];
    let mut deq = FoldableQueue::new(merge);
    for (i, a) in a.iter().enumerate().rev() {
        deq.clear();
        for (dp, &a) in dp.iter_mut().zip(a) {
            if let Some(x) = dp.iter().position(|p| p.1 == a) {
                dp[..=x].rotate_right(1);
            } else {
                dp.rotate_right(1);
            }
            dp[0] = (i, a);
            deq.push_back(*dp);
            while deq.find().unwrap()[q].0 < i + deq.len() {
                deq.pop_front();
            }
            ans[deq.len()] += 1;
        }
    }
    for i in (1..n).rev() {
        ans[i] += ans[i + 1];
    }
    for a in ans[1..].iter() {
        println!("{}", *a);
    }
}

fn main() {
    run();
}