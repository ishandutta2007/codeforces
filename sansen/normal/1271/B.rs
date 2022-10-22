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
    }
    let mut cnt = vec![0; 2];
    for &c in s.iter() {
        let k = if c == 'W' {0} else {1};
        cnt[k] += 1;
    }
    if cnt[0] % 2 == 1 && cnt[1] % 2 == 1 {
        println!("-1");
        return;
    }
    let mut s = s;
    let mut ans = vec![];
    let (a, b) = if cnt[1] % 2 == 0 {('W', 'B')} else {('B', 'W')};
    for i in 1..n {
        if s[i - 1] == b {
            s[i - 1] = a;
            if s[i] == b {
                s[i] = a;
            } else {
                s[i] = b;
            }
            ans.push(i);
        }
    }
    let mut out = String::new();
    out.push_str(&ans.len().to_string());
    out.push('\n');
    for a in ans {
        out.push_str(&a.to_string());
        out.push(' ');
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}