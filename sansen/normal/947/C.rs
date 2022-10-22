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

#[derive(Clone, Default)]
struct Node {
    cnt: u32,
    next: [u32; 4],
}

fn run() {
    input! {
        n: usize,
        a: [u32; n],
        p: [u32; n],
    }
    let w = 15;
    let mut node = vec![Node::default()];
    for p in p {
        let mut pos = 0;
        for i in (0..w).rev() {
            let x = (p >> (2 * i) & 3) as usize;
            if node[pos].next[x] == 0 {
                node[pos].next[x] = node.len() as u32;
                node.push(Node::default());
            }
            pos = node[pos].next[x] as usize;
            node[pos].cnt += 1;
        }
    }
    let mut ans = String::new();
    use std::fmt::Write;
    for a in a {
        let mut v = 0;
        let mut pos = 0;
        for i in (0..w).rev() {
            let next = node[pos].next;
            let mut x = (a >> (2 * i) & 3) as usize;
            let k = (0..4)
                .find(|k| {
                    let x = x ^ k;
                    next[x] > 0 && node[next[x] as usize].cnt > 0
                })
                .unwrap();
            x ^= k;
            v |= k << (2 * i);
            pos = next[x] as usize;
            node[pos].cnt -= 1;
        }
        write!(&mut ans, "{} ", v).ok();
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}