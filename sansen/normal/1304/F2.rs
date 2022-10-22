// ---------- begin Foldable Deque ----------
struct FoldableDeque<T, F> {
    front: Vec<(T, T)>,
    back: Vec<(T, T)>,
    op: F,
}

#[allow(dead_code)]
impl<T, F> FoldableDeque<T, F>
where T: Clone,
      F: Fn(&T, &T) -> T,
{
    fn new(op: F) -> Self {
        FoldableDeque {
            front: Vec::new(),
            back: Vec::new(),
            op: op,
        }
    }
    fn find(&self) -> Option<T> {
        match (self.front.last(), self.back.last()) {
            (Some(a), Some(b)) => Some((self.op)(&a.1, &b.1)),
            (Some(a), None) => Some(a.1.clone()),
            (None, Some(b)) => Some(b.1.clone()),
            (None, None) => None,
        }
    }
    fn clear(&mut self) {
        self.front.clear();
        self.back.clear();
    }
    fn len(&self) -> usize {
        self.front.len() + self.back.len()
    }
    fn push_back(&mut self, val: T) {
        let sum = if let Some(p) = self.back.last() {
            (self.op)(&p.1, &val)
        } else {
            val.clone()
        };
        self.back.push((val, sum));
    }
    fn push_front(&mut self, val: T) {
        let sum = if let Some(p) = self.front.last() {
            (self.op)(&val, &p.1)
        } else {
            val.clone()
        };
        self.front.push((val, sum));
    }
    fn pop_front(&mut self) -> Option<T> {
        if let Some(v) = self.front.pop() {
            Some(v.0)
        } else if !self.back.is_empty() {
            let a = self.back.clone();
            let m = (self.back.len() + 1) / 2;
            self.back.clear();
            let (f, b) = a.split_at(m);
            for v in f.iter().rev() {
                self.push_front(v.0.clone());
            }
            for v in b.iter() {
                self.push_back(v.0.clone());
            }
            Some(self.front.pop().unwrap().0)
        } else {
            None
        }
    }
    fn pop_back(&mut self) -> Option<T> {
        if let Some(v) = self.back.pop() {
            Some(v.0)
        } else if !self.front.is_empty() {
            let a = self.front.clone();
            let m = self.front.len() / 2;
            self.front.clear();
            let (f, b) = a.split_at(m);
            for v in f.iter().rev() {
                self.push_front(v.0.clone());
            }
            for v in b.iter() {
                self.push_back(v.0.clone());
            }
            Some(self.back.pop().unwrap().0)
        } else {
            None
        }
    }
}
// ---------- end Foldable Deque ----------
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

use std::cmp::*;

fn run() {
    input! {
        h: usize,
        w: usize,
        l: usize,
        a: [[i32; w]; h],
    }
    let mut sum = a.clone();
    for s in sum.iter_mut() {
        let mut prev = 0;
        for s in s.iter_mut().rev() {
            *s += prev;
            prev = *s;
        }
        s.push(0);
    }
    sum.push(vec![0; w + 1]);
    let mut dp = vec![0; w - l + 1];
    let mut que = FoldableDeque::new(|a: &i32, b: &i32| max(*a, *b));
    for i in (0..h).rev() {
        let mut next = vec![std::i32::MIN; w - l + 1];
        que.clear();
        for j in (0..(w - l + 1)).rev() {
            let val = dp[j] - sum[i + 1][j];
            que.push_back(val);
            if que.len() > l {
                que.pop_front();
            }
            let v = sum[i + 1][j + l] + que.find().unwrap();
            next[j] = max(next[j], v);
        }
        que.clear();
        for j in 0..(w - l + 1) {
            let val = dp[j] + sum[i + 1][j + l];
            que.push_back(val);
            if que.len() > l {
                que.pop_front();
            }
            let v = -sum[i + 1][j] + que.find().unwrap();
            next[j] = max(next[j], v);
        }
        let mut local = 0;
        for j in l..(w - l + 1) {
            local = max(local, dp[j - l]);
            next[j] = max(next[j], local);
        }
        let mut local = 0;
        for j in (l..(w - l + 1)).rev() {
            local = max(local, dp[j]);
            next[j - l] = max(next[j - l], local);
        }
        for j in 0..(w - l + 1) {
            next[j] += sum[i][j] - sum[i][j + l] + sum[i + 1][j] - sum[i + 1][j + l];
        }
        dp = next;
    }
    let ans = dp.into_iter().max().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}