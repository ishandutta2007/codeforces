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
        k: usize,
        s: chars,
    }
    let mut s = s;
    s.push('(');
    s.reverse();
    s.push(')');
    s.reverse();
    let mut l = vec![n; n + 2];
    let mut r = vec![1; n + 2];
    for i in 1..=n {
        l[i] = i - 1;
        r[i] = i + 1;
    }
    let mut stack = vec![];
    for i in 2..=n {
        if s[i - 1] == '(' && s[i] == ')' {
            stack.push((i - 1, i));
        }
    }
    let mut used = vec![false; n + 2];
    for _ in 0..(k / 2) {
        let (x, y) = stack.pop().unwrap();
        used[x] = true;
        used[y] = true;
        assert!(r[x] == y && l[y] == x);
        let (p, q) = (l[x], r[y]);
        r[p] = q;
        l[q] = p;
        if s[p] == '(' && s[q] == ')' {
            stack.push((p, q));
        }
    }
    let mut ans = String::new();
    for i in 1..=n {
        if used[i] {
            ans.push(s[i]);
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}