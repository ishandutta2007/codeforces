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

fn cond(b: bool) {
    if !b {
        println!("NO");
        std::process::exit(0);
    }
}

fn run() {
    input! {
        n: usize,
        s: [bytes; n],
    }
    let s: Vec<Vec<usize>> = s
        .iter()
        .map(|s| s.iter().map(|s| (*s - b'a') as usize).collect())
        .collect();
    let w = 26;
    let mut g = vec![vec![]; w];
    let mut deg = vec![0; 26];
    let mut used = vec![false; w];
    for s in s.iter() {
        let mut z = s.clone();
        z.sort();
        z.dedup();
        cond(z.len() == s.len());
        for s in s.iter() {
            used[*s] = true;
        }
        for v in s.windows(2) {
            let a = v[0];
            let b = v[1];
            g[a].push(b);
            deg[b] += 1;
        }
    }
    for g in g.iter_mut() {
        g.sort();
        g.dedup();
        cond(g.len() <= 1);
    }
    let mut ans = vec![];
    let mut elem = vec![false; w];
    while let Some(x) = (0..w).find(|x| used[*x] && deg[*x] == 0) {
        used[x] = false;
        ans.push(x);
        elem[x] = true;
        let mut pos = x;
        while g[pos].len() > 0 && !elem[g[pos][0]] {
            pos = g[pos][0];
            elem[pos] = true;
            ans.push(pos);
        }
    }
    let mut b = ans.clone();
    b.sort();
    b.dedup();
    cond(b.len() == ans.len());
    for s in s.iter() {
        cond(ans.len() >= s.len());
        cond(ans.windows(s.len()).any(|a| a == s.as_slice()));
    }
    let ans = ans
        .into_iter()
        .map(|s| (b'a' + s as u8) as char)
        .collect::<String>();
    println!("{}", ans);
}

fn main() {
    run();
}