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
        a: [i64; n],
        e: [(usize1, i64); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (i, &(p, w)) in e.iter().enumerate() {
        let i = i + 1;
        g[i].push((p, w));
        g[p].push((i, w));
    }
    let mut q = vec![];
    let mut stack = vec![(0, 0)];
    while let Some((v, p)) = stack.pop() {
        q.push(v);
        let g = &mut g[v];
        if let Some(k) = g.iter().position(|u| u.0 == p) {
            g.remove(k);
        }
        for &(u, _) in g.iter() {
            stack.push((u, v));
        }
    }
    let mut ans = vec![0; n];
    type Heap = std::collections::BinaryHeap<i64>;
    let mut h: Vec<(i64, Option<Heap>)> = vec![(0, None); n];
    for &v in q.iter().rev() {
        let child = &mut g[v];
        if child.is_empty() {
            h[v].1 = Some(Heap::new());
            h[v].1.as_mut().unwrap().push(-a[v]);
            continue;
        }
        child.sort_by_cached_key(|c| h[c.0].1.as_ref().unwrap().len());
        let large = child.pop().unwrap();
        let mut pq = h[large.0].1.take().unwrap();
        let add = h[large.0].0 + large.1;
        for &(u, w) in child.iter() {
            let mut he = h[u].1.take().unwrap();
            let a = h[u].0 + w;
            while let Some(v) = he.pop() {
                pq.push(v + a - add);
            }
        }
        while let Some(&v) = pq.peek() {
            if v + add > 0 {
                pq.pop();
            } else {
                break;
            }
        }
        ans[v] = pq.len();
        pq.push(-a[v] - add);
        h[v] = (add, Some(pq));
    }
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}