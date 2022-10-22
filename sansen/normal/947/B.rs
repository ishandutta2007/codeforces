use std::cmp::*;

const BOUND: i64 = 1_000_000_000_000;
const INF: i64 = BOUND * 200_000 + 1;

struct MaxCntSecond {
    max: i64,
    max_cnt: i64,
    second_max: i64,
}

impl MaxCntSecond {
    fn new(max: i64, max_cnt: i64, second_max: i64) -> Self {
        assert!(max_cnt > 0);
        assert!(max > second_max);
        MaxCntSecond {
            max: max,
            max_cnt: max_cnt,
            second_max: second_max,
        }
    }
    fn fold(&self, rhs: &Self) -> Self {
        match self.max.cmp(&rhs.max) {
            Ordering::Equal => MaxCntSecond::new(
                self.max,
                self.max_cnt + rhs.max_cnt,
                max(self.second_max, rhs.second_max),
            ),
            Ordering::Less => {
                MaxCntSecond::new(rhs.max, rhs.max_cnt, max(self.max, rhs.second_max))
            }
            Ordering::Greater => {
                MaxCntSecond::new(self.max, self.max_cnt, max(self.second_max, rhs.max))
            }
        }
    }
    fn tag(&self, val: i64) -> bool {
        self.second_max < val && val < self.max
    }
    fn chmin(&mut self, val: i64) -> i64 {
        assert!(self.tag(val));
        let diff = val - self.max;
        self.max = val;
        diff * self.max_cnt
    }
    fn add(&mut self, val: i64) {
        self.max += val;
        self.second_max += val;
    }
    fn update(&mut self, val: i64) {
        assert!(self.second_max < -BOUND);
        self.max = val;
        self.second_max = -INF;
    }
    fn parts(&self) -> (i64, i64, i64) {
        (self.max, self.max_cnt, self.second_max)
    }
}

struct MinCntSecond {
    min: i64,
    min_cnt: i64,
    second_min: i64,
}

impl MinCntSecond {
    fn new(min: i64, min_cnt: i64, second_min: i64) -> Self {
        assert!(min_cnt > 0);
        assert!(min < second_min);
        MinCntSecond {
            min: min,
            min_cnt: min_cnt,
            second_min: second_min,
        }
    }
    fn fold(&self, rhs: &Self) -> Self {
        match self.min.cmp(&rhs.min) {
            Ordering::Equal => MinCntSecond::new(
                self.min,
                self.min_cnt + rhs.min_cnt,
                min(self.second_min, rhs.second_min),
            ),
            Ordering::Greater => {
                MinCntSecond::new(rhs.min, rhs.min_cnt, min(self.min, rhs.second_min))
            }
            Ordering::Less => {
                MinCntSecond::new(self.min, self.min_cnt, min(self.second_min, rhs.min))
            }
        }
    }
    fn tag(&self, val: i64) -> bool {
        self.second_min > val && val > self.min
    }
    fn chmax(&mut self, val: i64) -> i64 {
        assert!(self.tag(val));
        let diff = val - self.min;
        self.min = val;
        diff * self.min_cnt
    }
    fn add(&mut self, val: i64) {
        self.min += val;
        self.second_min += val;
    }
    fn update(&mut self, val: i64) {
        assert!(self.second_min > BOUND);
        self.min = val;
        self.second_min = INF;
    }
    fn parts(&self) -> (i64, i64, i64) {
        (self.min, self.min_cnt, self.second_min)
    }
}

struct Value {
    max: MaxCntSecond,
    min: MinCntSecond,
    sum: i64,
    add: i64,
    len: i64,
}

impl Value {
    fn new(val: i64) -> Self {
        Value {
            max: MaxCntSecond::new(val, 1, -INF),
            min: MinCntSecond::new(val, 1,  INF),
            sum: val,
            add: 0,
            len: 1,
        }
    }
    fn get_sum(&self) -> i64 {
        self.sum
    }
    fn get_max(&self) -> i64 {
        self.max.max
    }
    fn get_min(&self) -> i64 {
        self.min.min
    }
    fn fold(&self, rhs: &Self) -> Self {
        let max = self.max.fold(&rhs.max);
        let min = self.min.fold(&rhs.min);
        assert!(max.max >= min.min);
        let sum = self.get_sum() + rhs.get_sum();
        let len = self.len + rhs.len;
        Value {
            max: max,
            min: min,
            sum: sum,
            add: 0,
            len: len,
        }
    }
    fn tag_max(&self, val: i64) -> bool {
        self.max.tag(val)
    }
    fn tag_min(&self, val: i64) -> bool {
        self.min.tag(val)
    }
    fn chmin(&mut self, x: i64) {
        assert!(self.tag_max(x));
        let (a, _, _) = self.max.parts();
        let (p, _, r) = self.min.parts();
        self.sum += self.max.chmin(x);
        if a == p {
            self.min.update(x);
        } else if r == a {
            self.min.second_min = x;
        }
    }
    fn chmax(&mut self, x: i64) {
        assert!(self.tag_min(x));
        let (a, _, _) = self.max.parts();
        let (p, _, r) = self.min.parts();
        self.sum += self.min.chmax(x);
        if a == p {
            self.max.update(x);
        } else if r == a {
            self.max.second_max = x;
        }
    }
    fn add(&mut self, val: i64) {
        self.max.add(val);
        self.min.add(val);
        self.sum += val * self.len;
        self.add += val;
    }
}

fn propagate(seg: &mut [Value], k: usize) {
    let v = seg[k].add;
    seg[k].add = 0;
    let max = seg[k].get_max();
    let min = seg[k].get_min();
    for s in seg[(2 * k)..].iter_mut().take(2) {
        s.add(v);
        if s.tag_max(max) {
            s.chmin(max);
        }
        if s.tag_min(min) {
            s.chmax(min);
        }
    }
}

fn update(seg: &mut [Value], k: usize) {
    assert!(seg[k].add == 0);
    seg[k] = seg[2 * k].fold(&seg[2 * k + 1]);
}

fn update_chmin(seg: &mut [Value], k: usize, l: usize, r: usize, x: usize, y: usize, val: i64) {
    if y <= l || r <= x || seg[k].get_max() <= val {
        return;
    }
    if x <= l && r <= y && seg[k].tag_max(val) {
        seg[k].chmin(val);
        return;
    }
    propagate(seg, k);
    let m = (l + r) / 2;
    update_chmin(seg, 2 * k, l, m, x, y, val);
    update_chmin(seg, 2 * k + 1, m, r, x, y, val);
    update(seg, k);
}

fn update_chmax(seg: &mut [Value], k: usize, l: usize, r: usize, x: usize, y: usize, val: i64) {
    if y <= l || r <= x || seg[k].get_min() >= val {
        return;
    }
    if x <= l && r <= y && seg[k].tag_min(val) {
        seg[k].chmax(val);
        return;
    }
    propagate(seg, k);
    let m = (l + r) / 2;
    update_chmax(seg, 2 * k, l, m, x, y, val);
    update_chmax(seg, 2 * k + 1, m, r, x, y, val);
    update(seg, k);
}

fn update_add(seg: &mut [Value], k: usize, l: usize, r: usize, x: usize, y: usize, val: i64) {
    if y <= l || r <= x {
        return;
    }
    if x <= l && r <= y {
        seg[k].add(val);
        return;
    }
    propagate(seg, k);
    let m = (l + r) / 2;
    update_add(seg, 2 * k, l, m, x, y, val);
    update_add(seg, 2 * k + 1, m, r, x, y, val);
    update(seg, k);
}

fn find_sum(seg: &mut [Value], k: usize, l: usize, r: usize, x: usize, y: usize) -> i64 {
    if y <= l || r <= x {
        return 0;
    }
    if x <= l && r <= y {
        return seg[k].get_sum();
    }
    propagate(seg, k);
    let m = (l + r) / 2;
    find_sum(seg, 2 * k, l, m, x, y) + find_sum(seg, 2 * k + 1, m, r, x, y)
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

fn run() {
    input! {
        n: usize,
        v: [i64; n],
        t: [i64; n],
    }
    let size = n.next_power_of_two();
    let mut seg: Vec<_> = (0..(2 * size)).map(|_| Value::new(0)).collect();
    for (s, v) in seg[size..].iter_mut().zip(v.iter()) {
        *s = Value::new(*v);
    }
    for i in (1..size).rev() {
        update(&mut seg, i);
    }
    let mut s = String::new();
    for (i, &t) in t.iter().enumerate() {
        let pre = find_sum(&mut seg, 1, 0, size, 0, i + 1);
        update_add(&mut seg, 1, 0, size, 0, i + 1, -t);
        update_chmax(&mut seg, 1, 0, size, 0, i + 1, 0);
        let now = find_sum(&mut seg, 1, 0, size, 0, i + 1);
        let ans = pre - now;
        s.push_str(&format!("{} ", ans));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}