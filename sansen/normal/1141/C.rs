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
    input!{
        n: usize,
        q: [i64; n - 1],
    }
    let mut s = q.clone();
    for i in 1..(n - 1) {
        s[i] += s[i - 1];
    }
    let v = *s.iter().min().unwrap();
    let p = if v > 0 {
        let mut p = vec![0; n];
        p[0] = 1;
        for i in 0..(n - 1) {
            p[i + 1] = s[i] + 1;
        }
        p
    } else {
        let mut p = vec![0; n];
        p[0] = -v + 1;
        for i in 0..(n - 1) {
            p[i + 1] = s[i] + p[0];
        }
        p
    };
    let mut used = vec![false; n + 1];
    for i in 0..n {
        let k = p[i] as usize;
        if k <= 0 || k > n || used[k] {
            println!("-1");
            return;
        }
        used[k] = true;
    }
    let mut ans = String::new();
    for p in p {
        ans.push_str(&format!("{} ", p));
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}