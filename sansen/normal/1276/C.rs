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

fn run_length_encoding<T: Clone + Eq>(a: &[T]) -> Vec<(T, usize)> {
    if a.len() == 0 {
        return vec![];
    }
    let mut x = a[0].clone();
    let mut cnt = 1;
    let mut ans = vec![];
    for y in &a[1..] {
        if x == *y {
            cnt += 1;
        } else {
            ans.push((x, cnt));
            x = y.clone();
            cnt = 1;
        }
    }
    ans.push((x, cnt));
    ans
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        a: [u32; n],
    }
    let mut a = a;
    a.sort();
    let mut a = run_length_encoding(&a);
    a.sort_by_key(|a| a.1);
    let mut cnt = vec![0; n + 1];
    for &(_, k) in &a {
        cnt[k] += 1;
    }
    let mut ans = (0, 0, 0);
    let mut rev_sum = a.len();
    let mut sum = 0;
    for h in 1..=n {
        let w = rev_sum + sum / h;
        if w >= h {
            ans = std::cmp::max(ans, (h * w, h, w));
        }
        sum += h * cnt[h];
        rev_sum -= cnt[h];
    }
    let (s, h, w) = ans;
    writeln!(out, "{}\n{} {}", s, h, w).ok();
    for a in &mut a {
        a.1 = std::cmp::min(a.1, h);
    }
    let mut b = vec![vec![0; w]; h];
    for j in 0..w {
        for i in 0..h {
            let (v, c) = a.pop().unwrap();
            b[i][j] = v;
            if c > 1 {
                a.push((v, c - 1));
            }
        }
    }
    for i in 1..h {
        b[i].rotate_right(i);
    }
    for i in 0..h {
        let mut set = std::collections::BTreeSet::new();
        for j in 0..w {
            assert!(set.insert(b[i][j]));
        }
    }
    for j in 0..w {
        let mut set = std::collections::BTreeSet::new();
        for i in 0..h {
            assert!(set.insert(b[i][j]));
        }
    }
    for i in 0..ans.1 {
        for j in 0..ans.2 {
            if j > 0 {
                write!(out, " ").ok();
            }
            write!(out, "{}", b[i][j]).ok();
        }
        writeln!(out, "").ok();
    }
}

fn main() {
    run();
}