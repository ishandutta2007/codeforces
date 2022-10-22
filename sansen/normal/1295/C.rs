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
        t: usize,
        p: [(chars, chars); t],
    }
    let mut map = std::collections::BTreeMap::new();
    for (i, c) in "qwertyuiopasdfghjklzxcvbnm".chars().enumerate() {
        map.insert(c, i);
    }
    assert!(map.len() == 26);
    for (s, t) in p {
        let s: Vec<usize> = s.into_iter().map(|c| *map.get(&c).unwrap()).collect();
        let t: Vec<usize> = t.into_iter().map(|c| *map.get(&c).unwrap()).collect();
        let inf = 1_000_000_000_000u64;
        let mut step = vec![inf; 26];
        let n = s.len();
        for i in (0..n).rev() {
            for s in step.iter_mut() {
                *s += 1;
            }
            step[s[i]] = 0;
        }
        let mut next = vec![vec![]; n];
        for i in (0..n).rev() {
            for s in step.iter_mut() {
                *s += 1;
            }
            step[s[i]] = 0;
            next[i] = step.clone();
        }
        let mut ans = 0;
        let mut state = 0;
        for t in t {
            ans += next[state][t] + 1;
            state = ((state as u64 + next[state][t] + 1) % n as u64) as usize;
        }
        if ans < inf {
            let n = n as u64;
            writeln!(out, "{}", (ans + n - 1) / n).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}

fn main() {
    run();
}