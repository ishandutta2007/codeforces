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
        a: [usize1; n],
    }
    let mut b = vec![];
    for (i, a) in a.into_iter().enumerate() {
        b.push((a, i));
    }
    b.sort();
    for b in b.windows(k + 1) {
        if b[0].0 == b[k].0 {
            println!("NO");
            return;
        }
    }
    let mut ans = vec![0; n];
    let mut c = 0;
    for b in b {
        ans[b.1] = c;
        c = (c + 1) % k;
    }
    let mut out = String::new();
    out.push_str("YES\n");
    for a in ans {
        out.push_str(&format!("{} ", a + 1));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}