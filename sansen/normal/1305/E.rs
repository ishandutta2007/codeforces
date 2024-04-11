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
        m: usize,
    }
    if n == 1 {
        if m == 0 {
            println!("1");
            return;
        }
        println!("-1");
        return;
    }
    let mut ans = vec![];
    ans.push(1);
    ans.push(2);
    let inf = 1_000_000_000;
    let mut cnt = 0;
    for i in 2..n {
        if cnt == m {
            ans.push(inf - 100_000 * (n - 1 - i));
        } else if cnt + ans.len() / 2 > m {
            let d = m - cnt;
            let len = ans.len();
            let v = ans[len - 1] + ans[len - 2 * d];
            ans.push(v);
            cnt += d;
        } else {
            cnt += ans.len() / 2;
            ans.push(i + 1);
        }
    }
    if cnt < m {
        println!("-1");
        return;
    }
    assert!(cnt == m);
    let mut out = String::new();
    for a in ans {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}