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

type Ref = Box<Node>;
type Link = Option<Ref>;

struct Node {
    val: u8,
    rev: bool,
    size: usize,
    left: Link,
    right: Link,
}

fn get_size(node: &Link) -> usize {
    node.as_ref().map_or(0, |p| p.size)
}

fn update(node: &mut Ref) {
    node.size = 1 + get_size(&node.left) + get_size(&node.right);
}

fn propagate(node: &mut Ref) {
    if node.rev {
        std::mem::swap(&mut node.left, &mut node.right);
        node.left.as_mut().map(|p| p.rev ^= true);
        node.right.as_mut().map(|p| p.rev ^= true);
        node.val ^= b'0' ^ b'1';
        node.rev = false;
    }
}

fn merge(l: Link, r: Link) -> Link {
    if l.is_none() {
        return r;
    }
    if r.is_none() {
        return l;
    }
    let a = get_size(&l);
    let b = get_size(&r);
    if rand() % (a + b) < a {
        let mut node = l.unwrap();
        propagate(&mut node);
        node.right = merge(node.right.take(), r);
        update(&mut node);
        Some(node)
    } else {
        let mut node = r.unwrap();
        propagate(&mut node);
        node.left = merge(l, node.left.take());
        update(&mut node);
        Some(node)
    }
}

fn split(node: Link, k: usize) -> (Link, Link) {
    let size = get_size(&node);
    assert!(k <= size);
    if k == 0 {
        return (None, node);
    }
    if k == size {
        return (node, None);
    }
    let mut node = node.unwrap();
    propagate(&mut node);
    let l = get_size(&node.left);
    if k >= l + 1 {
        let (x, y) = split(node.right.take(), k - l - 1);
        node.right = x;
        update(&mut node);
        (Some(node), y)
    } else {
        let (x, y) = split(node.left.take(), k);
        node.left = y;
        update(&mut node);
        (x, Some(node))
    }
}

fn build(a: &[u8]) -> Link {
    if a.len() == 0 {
        None
    } else {
        let m = a.len() / 2;
        Some(Box::new(Node {
            val: a[m],
            rev: false,
            size: a.len(),
            left: build(&a[..m]),
            right: build(&a[(m + 1)..]),
        }))
    }
}

fn check(node: Link, b: &[u8], k: &mut usize) {
    if node.is_none() {
        return;
    }
    let mut node = node.unwrap();
    propagate(&mut node);
    check(node.left.take(), b, k);
    assert!(b[*k] == node.val);
    *k += 1;
    check(node.right.take(), b, k);
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [(usize, bytes, bytes); t],
    }
    for (n, a, b) in ask {
        let mut ans = vec![];
        let mut l = 0;
        let mut r = n;
        let mut pos = 0;
        for (i, &b) in b.iter().enumerate().skip(1).rev() {
            if pos == 0 {
                if a[r - 1] == b {
                    r -= 1;
                } else {
                    if a[l] == b {
                        ans.push(1);
                    }
                    ans.push(i + 1);
                    l += 1;
                    pos ^= 1;
                }
            } else {
                if a[l] != b {
                    l += 1;
                } else {
                    if a[r - 1] != b {
                        ans.push(1);
                    }
                    ans.push(i + 1);
                    r -= 1;
                    pos ^= 1;
                }
            }
        }
        if pos == 0 {
            if a[r - 1] == b[0] {
            } else {
                ans.push(1);
            }
        } else {
            if a[r - 1] != b[0] {
            } else {
                ans.push(1);
            }
        }
        // check
        let mut x = build(&a);
        for &a in ans.iter() {
            let (mut p, q) = split(x, a);
            p.as_mut().unwrap().rev ^= true;
            x = merge(p, q);
        }
        check(x, &b, &mut 0);
        let mut s = String::new();
        s.push_str(&format!("{}", ans.len()));
        for a in ans {
            s.push_str(&format!(" {}", a));
        }
        writeln!(out, "{}", s).ok();
    }
}

fn main() {
    run();
}