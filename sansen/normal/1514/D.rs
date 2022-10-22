// ---------- begin rollback Mo algorithm ----------
pub trait MoOperator {
    type Value;
    type Query: Clone;
    type Answer;
    fn init(&mut self);
    fn add(&mut self, v: &Self::Value);
    fn snap(&mut self);
    fn rollback(&mut self, v: &Self::Value);
    fn answer(&mut self, op: &Self::Query) -> Self::Answer;
}

pub struct MoSolver<State: MoOperator> {
    state: State,
    array: Vec<State::Value>,
    query: Vec<(usize, usize, State::Query)>,
}

impl<State: MoOperator> MoSolver<State> {
    pub fn new(state: State, array: Vec<State::Value>) -> Self {
        MoSolver {
            state: state,
            array: array,
            query: vec![],
        }
    }
    pub fn add(&mut self, l: usize, r: usize, op: State::Query) {
        assert!(l < r && r <= self.array.len());
        self.query.push((l, r, op));
    }
    pub fn solve(&mut self, answer: &mut [State::Answer]) {
        assert!(answer.len() >= self.query.len());
        let size = self.array.len();
        let batch = (size as f64 / (self.query.len() as f64).sqrt()).ceil() as usize;
        let state = &mut self.state;
        state.init();
        state.snap();
        let mut q = vec![vec![]; size / batch + 1];
        for (k, p) in self.query.iter().enumerate() {
            let (l, r) = (p.0, p.1);
            if r - l <= batch {
                for v in self.array[l..r].iter() {
                    state.add(v);
                }
                answer[k] = state.answer(&p.2);
                for v in self.array[l..r].iter().rev() {
                    state.rollback(v);
                }
            } else {
                q[l / batch].push((r, l, k, p.2.clone()));
            }
        }
        for (i, q) in q.iter_mut().enumerate() {
            q.sort_by_key(|p| p.0);
            state.init();
            let mid = (i + 1) * batch;
            let mut right = mid;
            for p in q.iter() {
                let (r, l, k) = (p.0, p.1, p.2);
                for v in self.array[right..r].iter() {
                    state.add(v);
                }
                right = r;
                state.snap();
                for v in self.array[l..mid].iter().rev() {
                    state.add(v);
                }
                answer[k] = state.answer(&p.3);
                for v in self.array[l..mid].iter() {
                    state.rollback(v);
                }
            }
        }
    }
}
// ---------- end rollback Mo algorithm ----------
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

use std::io::Write;

struct State {
    cnt: Vec<usize>,
    max: usize,
    snap: usize,
}

impl MoOperator for State {
    type Value = usize;
    type Query = ();
    type Answer = usize;
    fn init(&mut self) {
        self.cnt.iter_mut().for_each(|c| *c = 0);
        self.max = 0;
    }
    fn add(&mut self, v: &Self::Value) {
        let po = &mut self.cnt[*v];
        *po += 1;
        self.max = self.max.max(*po);
    }
    fn snap(&mut self) {
        self.snap = self.max;
    }
    fn rollback(&mut self, v: &Self::Value) {
        self.max = self.snap;
        self.cnt[*v] -= 1;
    }
    fn answer(&mut self, op: &Self::Query) -> Self::Answer {
        self.max
    }
}

fn run() {
    input! {
        n: usize,
        q: usize,
        a: [usize1; n],
        ask: [(usize1, usize); q],
    }
    let state = State {
        cnt: vec![0; n],
        max: 0,
        snap: 0,
    };
    let mut solver = MoSolver::new(state, a);
    for &(l, r) in ask.iter() {
        solver.add(l, r, ());
    }
    let mut ans = vec![0; q];
    solver.solve(&mut ans);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (&(l, r), a) in ask.iter().zip(ans) {
        let d = r - l;
        let ans = a.saturating_sub(d - a).max(1);
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}