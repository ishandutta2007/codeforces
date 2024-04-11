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

// Mo
// N, X, Y 
// B
//
// 1/2 
//
// : (N / B) ^ 2 * Y
//  X * B
//
//  (N / B) ^ 2 * N
// dF/dB = X - (1 / 2) * (N^2 * Y + N^3) / B^3
//       = (2 * X * B^3 - (N^2 * Y + N^3)) / B^3
// 2
// B = ((N^2 * Y + N^3) / X) ^ (2 / 3)
// X = Y = Q
// B = (N^2 + N^3 / Q) ^ (2 / 3)

use std::io::Write;

struct State {
    cnt: Vec<usize>,
    elem: Vec<usize>,
    mex: usize,
}

impl State {
    fn new(n: usize) -> Self {
        let mut state = State {
            cnt: vec![0; n + 1],
            elem: vec![0; n + 1],
            mex: 0,
        };
        state.init();
        state
    }
    fn init(&mut self) {
        let len = self.cnt.len();
        self.cnt.clear();
        self.cnt.resize(len, 0);
        self.elem.clear();
        self.elem.resize(len, 0);
        self.elem[0] = len;
        self.mex = 1;
    }
    fn insert(&mut self, x: usize) {
        let c = &mut self.cnt[x];
        self.elem[*c] -= 1;
        *c += 1;
        self.elem[*c] += 1;
        let p = &mut self.mex;
        if self.elem[*c - 1] == 0 && *c - 1 < *p {
            *p = *c - 1;
        }
        while self.elem[*p] > 0 {
            *p += 1;
        }
    }
    fn delete(&mut self, x: usize) {
        let c = &mut self.cnt[x];
        self.elem[*c] -= 1;
        *c -= 1;
        self.elem[*c] += 1;
        let p = &mut self.mex;
        if self.elem[*c + 1] == 0 && *c + 1 < *p {
            *p = *c + 1;
        }
        while self.elem[*p] > 0 {
            *p += 1;
        }
    }
    fn find(&self) -> usize {
        self.mex
    }
}

fn run() {
    input! {
        n: usize,
        q: usize,
        a: [usize; n],
        ask: [(u8, usize1, usize); q],
    }
    let mut z = a.clone();
    for &(_, _, x) in ask.iter().filter(|p| p.0 == 2) {
        z.push(x);
    }
    z.sort();
    z.dedup();
    let mut a = a;
    for a in a.iter_mut() {
        *a = z.binary_search(a).unwrap();
    }
    let mut ask = ask;
    for p in ask.iter_mut().filter(|p| p.0 == 2) {
        p.2 = z.binary_search(&p.2).unwrap();
    }
    let batch = {
        let n = n as f64;
        (n.powi(2) * 8.0).cbrt().ceil() as usize
    };
    let mut update = vec![];
    let mut query = vec![vec![vec![]; n / batch + 1]; n / batch + 1];
    for (i, (op, a, b)) in ask.into_iter().enumerate() {
        if op == 1 {
            query[a / batch][b / batch].push((a, b, i));
        } else {
            update.push((a, b, i));
        }
    }
    let mut ans = vec![0; q];
    let mut state = State::new(z.len() + n);
    for (i, q) in query.iter().enumerate() {
        for q in q.iter() {
            if q.is_empty() {
                continue;
            }
            state.init();
            let mut a = a.clone();
            let mut x = i * batch;
            let mut y = i * batch;
            let mut z = 0;
            for &(l, r, k) in q.iter() {
                while z < update.len() && update[z].2 < k {
                    let p = update[z].0;
                    let v = update[z].1;
                    if x <= p && p < y {
                        state.delete(a[p]);
                        state.insert(v);
                    }
                    a[p] = v;
                    z += 1;
                }
                while l < x {
                    x -= 1;
                    state.insert(a[x]);
                }
                while y < r {
                    state.insert(a[y]);
                    y += 1;
                }
                while x < l {
                    state.delete(a[x]);
                    x += 1;
                }
                while r < y {
                    y -= 1;
                    state.delete(a[y]);
                }
                ans[k] = state.find();
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        if a > 0 {
            writeln!(out, "{}", a).ok();
        }
    }
}

fn main() {
    run();
}