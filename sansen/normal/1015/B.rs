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
        s: chars,
        t: chars,
    }
    let mut x = s.clone();
    let mut y = t.clone();
    x.sort();
    y.sort();
    if x != y {
        println!("-1");
        return;
    }
    let mut s = s;
    let mut ans = vec![];
    for i in 0..n {
        if s[i] == t[i] {
            continue;
        }
        let mut j = i + 1;
        while s[j] != t[i] {
            j += 1;
        }
        for k in (i..j).rev() {
            ans.push(k + 1);
            s.swap(k, k + 1);
        }
    }
    assert!(s == t);
    let mut out = String::new();
    out.push_str(&format!("{}\n", ans.len()));
    for k in ans {
        out.push_str(&format!("{} ", k));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}