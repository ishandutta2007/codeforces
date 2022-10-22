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

fn run() {
    input! {
        n: usize,
        q: usize,
        p: [usize1; n - 1],
        ask: [usize1; q],
    }
    let mut p = p;
    p.insert(0, 0);
    let mut g = vec![vec![]; n];
    for (i, &p) in p.iter().enumerate().skip(1) {
        g[p].push(i);
        g[i].push(p);
    }
    let mut topo = vec![(0, 0)];
    for i in 0..n {
        let (v, p) = topo[i];
        let g = &mut g[v];
        if let Some(k) = g.iter().position(|u| *u == p) {
            g.remove(k);
        }
        for &u in g.iter() {
            topo.push((u, v));
        }
    }
    let mut size = vec![1; n];
    let mut ans = (0..n).collect::<Vec<_>>();
    for &(v, _) in topo.iter().rev() {
        let mut child = vec![];
        for &u in g[v].iter() {
            size[v] += size[u];
            child.push((size[u], u));
        }
        child.sort();
        if child.is_empty() {
            continue;
        }
        let (max, u) = *child.last().unwrap();
        if size[v] < 2 * max {
            let mut x = ans[u];
            while size[v] < 2 * (size[v] - size[x]) {
                x = p[x];
            }
            ans[v] = x;
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for v in ask {
        writeln!(out, "{}", ans[v] + 1).ok();
    }
}

fn main() {
    run();
}