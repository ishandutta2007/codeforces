fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> usize {
    static mut X: usize = 0;
    unsafe {
        if X == 0 {
            X = rand_memory();
        }
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}

pub trait MoOperator {
    type Value;
    type Query;
    type Answer;
    fn init(&mut self);
    fn insert(&mut self, v: &Self::Value);
    fn delete(&mut self, v: &Self::Value);
    fn answer(&mut self, q: Self::Query) -> Self::Answer;
    fn solve(
        &mut self,
        array: &[Self::Value],
        mut query: Vec<(usize, usize, Self::Query)>,
        answer: &mut [Self::Answer],
    ) {
        let state = self;
        let size = array.len();
        assert!(query.len() <= answer.len());
        assert!(query.iter().all(|p| p.0 < p.1 && p.1 <= size));
        if query.is_empty() {
            return;
        }
        let batch = (size as f64 / (query.len() as f64).sqrt()).ceil() as usize;
        let mut q = vec![];
        std::mem::swap(&mut q, &mut query);
        let mut query = (0..(size / batch + 1)).map(|_| vec![]).collect::<Vec<_>>();
        for (i, (l, r, op)) in q.into_iter().enumerate() {
            query[l / batch].push((r, l, i, op));
        }
        state.init();
        let mut x = 0;
        let mut y = 0;
        for (i, mut query) in query.into_iter().enumerate() {
            query.sort_unstable_by_key(|p| p.0);
            if i & 1 == 1 {
                query.reverse();
            }
            for (r, l, k, op) in query.into_iter() {
                while l < x {
                    x -= 1;
                    state.insert(&array[x]);
                }
                while y < r {
                    state.insert(&array[y]);
                    y += 1;
                }
                while x < l {
                    state.delete(&array[x]);
                    x += 1;
                }
                while r < y {
                    y -= 1;
                    state.delete(&array[y]);
                }
                answer[k] = state.answer(op);
            }
        }
    }
}
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

use std::io::Write;

struct State {
    cnt: Vec<usize>,
    a: Vec<usize>,
}

impl MoOperator for State {
    type Value = usize;
    type Query = (usize, usize, usize);
    type Answer = i32;
    fn init(&mut self) {
        let len = self.cnt.len();
        self.cnt.clear();
        self.cnt.resize(len, 0);
    }
    fn insert(&mut self, v: &Self::Value) {
        self.cnt[*v] += 1;
    }
    fn delete(&mut self, v: &Self::Value) {
        self.cnt[*v] -= 1;
    }
    fn answer(&mut self, (l, r, k): Self::Query) -> Self::Answer {
        let mut res = -1;
        for _ in 0..100 {
            let c = self.a[l + rand() % (r - l)];
            if self.cnt[c] * k > r - l && (res == -1 || res > c as i32) {
                res = c as i32;
            }
        }
        res
    }
}

fn run() {
    input! {
        n: usize,
        q: usize,
        a: [usize; n],
        ask: [(usize1, usize, usize); q],
    }
    let mut ans = vec![0; q];
    State {
        cnt: vec![0; n + 1],
        a: a.clone(),
    }.solve(&a, ask.into_iter().map(|(l, r, k)| (l, r, (l, r, k))).collect(), &mut ans);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}