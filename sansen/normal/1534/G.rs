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

// reference
// https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8

mod slopetrick {

    #[derive(Default, Debug)]
    struct InternalHeap {
        h: std::collections::BinaryHeap<i64>,
        add: i64,
    }

    impl InternalHeap {
        fn push(&mut self, val: i64) {
            self.h.push(val - self.add);
        }
        fn pop(&mut self) -> Option<i64> {
            self.h.pop().map(|v| v + self.add)
        }
        fn peek(&self) -> Option<i64> {
            self.h.peek().map(|v| v + self.add)
        }
        fn add(&mut self, v: i64) {
            self.add += v;
        }
        fn clear(&mut self) {
            self.h.clear();
            self.add = 0;
        }
    }

    #[derive(Default, Debug)]
    pub struct SlopeTrick {
        min_f: i64,
        left: InternalHeap,
        right: InternalHeap,
    }

    #[allow(dead_code)]
    impl SlopeTrick {
        pub fn new() -> Self {
            SlopeTrick::default()
        }
        pub fn find_min(&self) -> i64 {
            self.min_f
        }
        pub fn add_const(&mut self, a: i64) {
            self.min_f += a;
        }
        // max(0, x - a), _/
        pub fn add_x_a(&mut self, mut a: i64) {
            if self.left.peek().map_or(false, |p| a < p) {
                self.min_f += self.left.peek().unwrap() - a;
                self.left.push(a);
                a = self.left.pop().unwrap();
            }
            self.right.push(-a);
        }
        // max(0, a - x), \_
        pub fn add_a_x(&mut self, mut a: i64) {
            if self.right.peek().map_or(false, |p| -p < a) {
                self.min_f += a + self.right.peek().unwrap();
                self.right.push(-a);
                a = -self.right.pop().unwrap();
            }
            self.left.push(a);
        }
        // \/
        pub fn add_abs(&mut self, x: i64) {
            self.add_a_x(x);
            self.add_x_a(x);
        }
        // f(x) = min f(y) (y <= x),
        // \_/ => _/
        pub fn left_min(&mut self) {
            self.left.clear();
        }
        // f(x) = min f(y) (x <= y),
        // \_/ => \_
        pub fn right_min(&mut self) {
            self.right.clear();
        }
        // f(x) => f(x - shift)
        // |x| -> |x - shift|
        pub fn shift(&mut self, shift: i64) {
            self.left.add(shift);
            self.right.add(-shift);
        }
        // g(x) = f(y) (x - b <= y <= x - a)
        pub fn slide_min(&mut self, a: i64, b: i64) {
            assert!(a <= b);
            self.left.add(a);
            self.right.add(-b);
        }
    }
}

fn run() {
    input! {
        n: usize,
        p: [(i64, i64); n],
    }
    let mut p = p;
    p.sort_by_key(|p| p.0 + p.1);
    let mut pre = 0;
    let mut slope = slopetrick::SlopeTrick::new();
    for (x, y) in p {
        let d = x + y - pre;
        pre = x + y;
        if d > 0 {
            slope.slide_min(0, d);
        }
        slope.add_abs(x);
    }
    let ans = slope.find_min();
    println!("{}", ans);
}

fn main() {
    run();
}