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
        a: [i32; n],
    }
    if n % 2 != 0 {
        println!("-1");
        return;
    }
    let mut ans = vec![];
    let mut i = 0;
    while i < n {
        let mut set = std::collections::BTreeSet::new();
        let mut used = std::collections::BTreeSet::new();
        let mut j = i;
        while j < n {
            let a = a[j];
            j += 1;
            if a > 0 {
                if used.contains(&a) {
                    println!("-1");
                    return;
                }
                used.insert(a);
                set.insert(a);
            } else {
                let a = -a;
                if !set.contains(&a) {
                    println!("-1");
                    return;
                }
                set.remove(&a);
            }
            if set.is_empty() {
                break;
            }
        }
        if !set.is_empty() {
            println!("-1");
            return;
        }
        ans.push(j - i);
        i = j;
    }
    let mut out = String::new();
    out.push_str(&format!("{}\n", ans.len()));
    for a in ans {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}