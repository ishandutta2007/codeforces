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

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let m = 1_000_000;
    let mut f: Vec<usize> = (0..=m).collect();
    for i in 2.. {
        if i * i > m {
            break;
        }
        if f[i] == i {
            let mut j = i * i;
            while j <= m {
                f[j] = i;
                j += i;
            }
        }
    }
    let mut e = vec![];
    for mut a in a {
        let mut v = 1;
        while a > 1 {
            let p = f[a];
            while (a % p) == 0 && (a / p) % p == 0 {
                a /= p;
                a /= p;
            }
            if a % p == 0 {
                v *= p;
                a /= p;
            }
        }
        if v == 1 {
            println!("1");
            return;
        }
        e.push(v);
    }
    e.sort();
    e.dedup();
    if e.len() < n {
        println!("2");
        return;
    }
    let mut graph = vec![vec![]; m + 1];
    for e in e {
        let (a, b) = if f[e] == e {
            (1, e)
        } else {
            let a = f[e];
            (a, e / a)
        };
        graph[a].push(b);
        graph[b].push(a);
    }
    let mut parent = vec![0; m + 1];
    let mut depth = vec![m + 1; m + 1];
    let mut ans = n + 1;
    for r in 1.. {
        if r * r > m {
            break;
        }
        let mut set = std::collections::BTreeSet::new();
        let mut q = std::collections::VecDeque::new();
        q.push_back(r);
        parent[r] = r;
        depth[r] = 0;
        set.insert(r);
        while let Some(v) = q.pop_front() {
            for &u in graph[v].iter() {
                if parent[u] == 0 {
                    parent[u] = v;
                    depth[u] = depth[v] + 1;
                    set.insert(u);
                    q.push_back(u);
                } else if u != parent[v] {
                    ans = std::cmp::min(depth[u] + depth[v] + 1, ans);
                }
            }
        }
        for v in set {
            parent[v] = 0;
        }
    }
    if ans > n {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}

fn main() {
    run();
}