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
        p: [(usize, usize); n],
    }
    let mut c = vec![0; n];
    let mut g = vec![vec![]; n];
    let mut root = 0;
    for (i, p) in p.iter().enumerate() {
        c[i] = p.1;
        if p.0 == 0 {
            root = i;
        } else {
            g[p.0 - 1].push(i);
        }
    }
    let mut q = vec![];
    let mut stack = vec![root];
    while let Some(v) = stack.pop() {
        q.push(v);
        for &u in g[v].iter() {
            stack.push(u);
        }
    }
    let mut size = vec![1; n];
    for &v in q.iter().rev() {
        for &u in g[v].iter() {
            size[v] += size[u];
        }
        if c[v] >= size[v] {
            println!("NO");
            return;
        }
    }
    let mut used = vec![false; n + 1];
    let mut ans = vec![0; n];
    for &v in q.iter() {
        let mut cnt = 0;
        for i in 1..=n {
            if !used[i] && cnt == c[v] {
                ans[v] = i;
                used[i] = true;
                break;
            }
            if !used[i] {
                cnt += 1;
            }
        }
    }
    let mut out = String::new();
    out.push_str("YES\n");
    for a in ans {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}