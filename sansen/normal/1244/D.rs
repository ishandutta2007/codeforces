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
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        c: [[u64; n]; 3],
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    if g.iter().any(|g| g.len() > 2) {
        writeln!(out, "-1").unwrap();
        return;
    }
    let src = g.iter().position(|d| d.len() == 1).unwrap();
    let mut q = vec![];
    q.push(src);
    q.push(g[src][0]);
    for i in 2..n {
        let v = q[i - 1];
        let p = q[i - 2];
        for &u in &g[v] {
            if u != p {
                q.push(u);
            }
        }
    }
    let mut ans = (0, 0, std::u64::MAX);
    for i in 0..3 {
        for j in 0..3 {
            if i == j {
                continue;
            }
            let mut sum = 0;
            let t = [i, j, i ^ j ^ 3];
            for k in 0..n {
                sum += c[t[k % 3]][q[k]];
            }
            if ans.2 > sum {
                ans = (i, j, sum);
            }
        }
    }
    writeln!(out, "{}", ans.2).unwrap();
    let mut color = vec![0; n];
    let t = [ans.0, ans.1, ans.0 ^ ans.1 ^ 3];
    for i in 0..n {
        color[q[i]] = t[i % 3];
    }
    for i in 0..n {
        if i > 0 {
            write!(out, " ").unwrap();
        }
        write!(out, "{}", color[i] + 1).unwrap();
    }
    writeln!(out, "").unwrap();
}

fn main() {
    run();
}