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

//

fn run() {
    input! {
        n: usize,
        p: [usize1; n - 1],
    }
    let mut child = vec![vec![]; n];
    for (i, p) in p.iter().enumerate() {
        child[*p].push(i + 1);
    }
    let mut size = vec![1; n];
    for (i, p) in p.iter().enumerate().rev() {
        size[*p] += size[i + 1];
    }
    let mut ans = vec![1f64; n];
    for i in 0..n {
        if child[i].is_empty() {
            continue;
        }
        for &c in child[i].iter() {
            ans[c] = ans[i] + (size[i] - size[c] - 1) as f64 * 0.5 + 1f64;
        }
    }
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{:.1} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}