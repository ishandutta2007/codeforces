// ---------- begin persistent stack ----------
#[allow(dead_code)]
mod persistent_stack {
    use std::rc::Rc;

    type Ref<T> = Rc<Node<T>>;
    type Link<T> = Option<Ref<T>>;

    #[derive(Debug)]
    struct Node<T> {
        value: T,
        next: Link<T>,
    }

    #[derive(Clone, Debug)]
    pub struct Stack<T> {
        size: usize,
        node: Link<T>,
    }

    impl<T> Drop for Stack<T> {
        fn drop(&mut self) {
            let mut root = self.node.take();
            while let Some(node) = root.as_mut() {
                if let Some(node) = Rc::get_mut(node) {
                    root = node.next.take();
                } else {
                    break;
                }
            }
        }
    }

    impl<T> Stack<T> {
        pub fn new() -> Self {
            Stack {
                size: 0,
                node: None,
            }
        }
        pub fn push(&mut self, value: T) {
            let node = Some(Rc::new(Node {
                value: value,
                next: self.node.take(),
            }));
            self.node = node;
            self.size += 1;
        }
        pub fn top(&self) -> Option<&T> {
            self.node.as_ref().map(|node| &node.value)
        }
        pub fn len(&self) -> usize {
            self.size
        }
    }

    impl<T: Clone> Stack<T> {
        pub fn pop(&mut self) -> Option<T> {
            self.node.take().map(|p| {
                self.node = p.next.clone();
                self.size -= 1;
                p.value.clone()
            })
        }
    }

    pub struct Iter<'a, T> {
        next: Option<&'a Ref<T>>,
    }

    impl<T> Stack<T> {
        pub fn iter(&self) -> Iter<T> {
            Iter {
                next: self.node.as_ref(),
            }
        }
    }

    impl<'a, T> Iterator for Iter<'a, T> {
        type Item = &'a T;
        fn next(&mut self) -> Option<Self::Item> {
            self.next.take().map(|p| {
                self.next = p.next.as_ref();
                &p.value
            })
        }
    }
}
// ---------- end persistent stack ----------
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

use persistent_stack::*;

fn run() {
    input! {
        n: usize,
        d: usize,
        a: [usize; n],
    }
    let p = 10;
    let mut dp = vec![(0f64, Stack::<usize>::new()); p];
    for a in a {
        let add = (a as f64).ln();
        let mut next = dp.clone();
        for (i, (mut val, mut s)) in dp.into_iter().enumerate() {
            if s.len() > 0 {
                val += add;
                s.push(a);
                let x = i * a % p;
                if next[x].0 < val {
                    next[x] = (val, s);
                }
            }
        }
        if add > next[a % p].0 {
            let mut s = Stack::new();
            s.push(a);
            next[a % p] = (add, s);
        }
        dp = next;
    }
    if dp[d].1.len() == 0 {
        println!("-1");
        return;
    }
    let mut ans = vec![];
    for s in dp[d].1.iter() {
        ans.push(*s);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", ans.len()).ok();
    for (i, a) in ans.iter().enumerate() {
        if i > 0 {
            write!(out, " ").ok();
        }
        write!(out, "{}", *a).ok();
    }
    writeln!(out).ok();
}

fn main() {
    run();
}