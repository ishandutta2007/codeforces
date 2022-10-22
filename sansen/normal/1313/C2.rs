mod persistent_stack {
    use std::rc::*;
    type Link<T> = Option<Rc<Node<T>>>;
    #[derive(Clone)]
    struct Node<T: Clone> {
        val: T,
        next: Link<T>,
    }
    #[derive(Clone)]
    pub struct Stack<T: Clone> {
        root: Link<T>,
    }
    impl<T> Stack<T>
    where
        T: Clone,
    {
        pub fn new() -> Self {
            Stack { root: None }
        }
        pub fn push(&mut self, val: T) {
            self.root = Some(Rc::new(Node {
                val: val,
                next: self.root.clone(),
            }));
        }
        pub fn pop(&mut self) -> Option<T> {
            self.root.take().map(|t| {
                self.root = t.next.clone();
                t.val.clone()
            })
        }
        pub fn top(&self) -> Option<&T> {
            self.root.as_ref().map(|t| &t.val)
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

#[derive(Clone)]
struct State {
    stack: persistent_stack::Stack<(u64, u64)>,
    sum: u64,
}

impl State {
    fn new() -> Self {
        State {
            stack: persistent_stack::Stack::new(),
            sum: 0,
        }
    }
    fn push(&mut self, v: u64) {
        let mut cnt = 1;
        while let Some(p) = self.stack.top() {
            if p.0 >= v {
                cnt += p.1;
                self.sum -= p.0 * p.1;
                self.stack.pop();
            } else {
                break;
            }
        }
        self.sum += cnt * v;
        self.stack.push((v, cnt));
    }
    fn find(&self) -> u64 {
        self.sum
    }
}

fn run() {
    input! {
        n: usize,
        a: [u64; n],
    }
    let mut a = a;
    let mut dp = vec![];
    for _ in 0..2 {
        let mut res = vec![];
        let mut state = State::new();
        res.push(state.clone());
        for &a in a.iter() {
            state.push(a);
            res.push(state.clone());
        }
        dp.push(res);
        a.reverse();
    }
    dp[1].reverse();
    let mut ans = (0, 0);
    for i in 0..=n {
        let v = dp[0][i].find() + dp[1][i].find();
        ans = std::cmp::max(ans, (v, i));
    }
    let mut b = vec![];
    for i in 0..2 {
        let mut stack = dp[i][ans.1].stack.clone();
        while let Some(p) = stack.pop() {
            b.push(p);
        }
        b.reverse();
    }
    b.reverse();
    let mut out = String::new();
    for (v, c) in b {
        for _ in 0..c {
            out.push_str(&format!("{} ", v));
        }
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}