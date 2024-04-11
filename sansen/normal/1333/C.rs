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
        a: [i64; n],
    }
    let mut sum = a.clone();
    sum.push(0);
    for i in (0..n).rev() {
        sum[i] += sum[i + 1];
    }
    let mut set = std::collections::BTreeSet::new();
    let mut q = std::collections::VecDeque::new();
    set.insert(0);
    q.push_back(0);
    let mut ans = 0u64;
    for (&a, &s) in a.iter().zip(sum.iter()).rev() {
        if a == 0 {
            set.clear();
            q.clear();
            set.insert(0);
            q.push_back(0);
        } else {
            if set.contains(&s) {
                while let Some(v) = q.pop_front() {
                    set.remove(&v);
                    if v == s {
                        break;
                    }
                }
            }
            set.insert(s);
            q.push_back(s);
            ans += set.len() as u64 - 1;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}