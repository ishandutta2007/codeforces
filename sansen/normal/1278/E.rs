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

use std::io::Write;

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut topo = vec![];
    let mut stack = vec![(0, 0)];
    while let Some((v, p)) = stack.pop() {
        topo.push(v);
        let child = &mut g[v];
        if let Some(k) = child.iter().position(|u| *u == p) {
            child.remove(k);
        }
        for &u in child.iter() {
            stack.push((u, v));
        }
    }
    // 
    let mut ans: Vec<Option<Vec<(usize, usize, usize)>>> = vec![None; n];
    for &v in topo.iter().rev() {
        let child = &g[v];
        if child.is_empty() {
            ans[v] = Some(vec![(v, 0, 1)]);
            continue;
        }
        let mut a = vec![];
        for &u in child.iter() {
            a.push(ans[u].take().unwrap());
        }
        a.sort_by_key(|a| a.len());
        let mut ini = a.pop().unwrap();
        let mut add = 2 * ini.len() - 1;
        for a in a.iter_mut() {
            for p in a.iter_mut() {
                p.1 += add;
                p.2 += add;
            }
            add += 2 * a.len() - 1;
        }
        let mut root = (v, add, 0);
        add += 1;
        for a in a.iter_mut().rev() {
            a.last_mut().unwrap().2 = add;
            add += 1;
        }
        ini.last_mut().unwrap().2 = add;
        add += 1;
        root.2 = add;
        for mut a in a {
            ini.append(&mut a);
        }
        ini.push(root);
        ans[v] = Some(ini);
    }
    let mut ans = ans[0].take().unwrap();
    ans.sort();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (_, l, r) in ans {
        writeln!(out, "{} {}", l + 1, r + 1).ok();
    }
}

fn main() {
    run();
}