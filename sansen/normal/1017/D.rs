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

fn eval(s: &Vec<char>) -> usize {
    let mut ans = 0;
    for &c in s.iter().rev() {
        let k = c as usize - '0' as usize;
        ans = 2 * ans + k;
    }
    ans
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        q: usize,
        w: [usize; n],
        a: [chars; m],
        b: [(chars, usize); q],
    }
    let mut cnt = vec![0; 1 << n];
    for a in a {
        let a = eval(&a);
        cnt[a] += 1;
    }
    let mut score = vec![0; 1 << n];
    for i in 0..(1 << n) {
        let s = &mut score[i];
        for j in 0..n {
            if (i >> j) & 1 == 0 {
                *s += w[j];
            }
        }
    }
    let mut ans = vec![vec![0; 1 << n]; 100 + 1];
    for t in 0..(1 << n) {
        for bit in 0..(1 << n) {
            let v = score[t ^ bit];
            if v <= 100 {
                ans[v][t] += cnt[bit];
            }
        }
    }
    for t in 0..(1 << n) {
        for i in 1..=100 {
            ans[i][t] += ans[i - 1][t];
        }
    }
    for (s, k) in b {
        let t = eval(&s);
        writeln!(out, "{}", ans[k][t]).ok();
    }
}

fn main() {
    run();
}