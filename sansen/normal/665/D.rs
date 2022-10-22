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
        a: [usize; n],
    }
    let m = 2_000_000;
    let mut is_prime = vec![true; m + 1];
    for i in 2.. {
        if i * i > m {
            break;
        }
        if is_prime[i] {
            let mut j = i * i;
            while j <= m {
                is_prime[j] = false;
                j += i;
            }
        }
    }
    let mut cnt = 0;
    for a in a.iter() {
        if *a == 1 {
            cnt += 1;
        }
    }
    let mut ans = vec![];
    if cnt > 0 {
        for _ in 0..cnt {
            ans.push(1);
        }
        for a in a.iter() {
            if *a > 1 && is_prime[*a + 1] {
                ans.push(*a);
                break;
            }
        }
        if ans.len() == 1 {
            ans.clear();
            'outer1: for i in 0..n {
                for j in 0..i {
                    if is_prime[a[i] + a[j]] {
                        ans.push(a[i]);
                        ans.push(a[j]);
                        break 'outer1;
                    }
                }
            }
        }
    } else {
        'outer: for i in 0..n {
            for j in 0..i {
                if is_prime[a[i] + a[j]] {
                    ans.push(a[i]);
                    ans.push(a[j]);
                    break 'outer;
                }
            }
        }
    }
    if ans.len() == 0 {
        ans.push(a[0]);
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