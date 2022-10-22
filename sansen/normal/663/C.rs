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
        m: usize,
        e: [(usize1, usize1, chars); m],
    }
    let mut graph = vec![vec![]; n];
    for (i, (a, b, c)) in e.into_iter().enumerate() {
        let c = if c[0] == 'R' {
            1
        } else {
            0
        };
        graph[a].push((b, c));
        graph[b].push((a, c));
    }
    let mut ans = vec![n; n + 1];
    for p in 0..2 {
        let mut used = vec![false; n];
        let mut state = vec![2; n];
        let mut res = (0, vec![]);
        for i in 0..n {
            if used[i] {
                continue;
            }
            let mut cost = (n + 1, vec![]);
            for k in 0..2 {
                state[i] = k;
                let mut ok = true;
                let mut topo = vec![i];
                for j in 0.. {
                    if j >= topo.len() {
                        break;
                    }
                    let v = topo[j];
                    used[v] = true;
                    for &(u, c) in graph[v].iter() {
                        if state[u] == 2 {
                            state[u] = p ^ state[v] ^ c;
                            topo.push(u);
                        } else if state[u] ^ state[v] ^ c != p {
                            ok = false;
                        }
                    }
                }
                if ok {
                    let mut a = vec![];
                    for &v in topo.iter() {
                        if state[v] == 1 {
                            a.push(v);
                        }
                        state[v] = 2;
                    }
                    if cost.0 > a.len() {
                        cost = (a.len(), a);
                    }
                }
            }
            res.0 += cost.0;
            res.1.append(&mut cost.1);
            if cost.0 > n {
                res.0 = n + 1;
                break;
            }
        }
        if res.0 == res.1.len() && ans.len() > res.1.len() {
            ans = res.1;
        }
    }
    if ans.len() <= n {
        let mut s = String::new();
        s.push_str(&format!("{}\n", ans.len()));
        for a in ans {
            s.push_str(&format!("{} ", a + 1));
        }
        s.pop();
        println!("{}", s);
    } else {
        println!("-1");
    }
}

fn main() {
    run();
}