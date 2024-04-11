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

use std::io::Write;

// DP?
// 2^10 * 10^5 * 10 
// 10^2k 
// 
// less 9

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        s: [chars; t],
    }
    for s in s {
        let s: Vec<usize> = s.into_iter().map(|c| c.to_digit(10).unwrap() as usize).collect();
        if s[0] == 1 && s[1..].iter().all(|c| *c == 0) {
            let mut ans = String::new();
            for _ in 2..s.len() {
                ans.push('9');
            }
            writeln!(out, "{}", ans).ok();
            continue;
        }
        if s[0] == 1 && *s.last().unwrap() == 1 && s[1..(s.len() - 1)].iter().all(|c| *c == 0) {
            let mut ans = String::new();
            for _ in 2..s.len() {
                ans.push('9');
            }
            writeln!(out, "{}", ans).ok();
            continue;
        }
        let n = s.len();
        let mut ans = vec![];
        let mut sup = vec![0; n + 1];
        for (i, &c) in s.iter().enumerate() {
            sup[i + 1] = sup[i] ^ (1 << c);
            ans.push(c);
        }
        'outer: for i in (0..n).rev() {
            ans.pop();
            for d in (0..s[i]).rev() {
                let v = sup[i] ^ (1usize << d);
                let cnt = v.count_ones() as usize;
                if ans.len() + 1 + cnt <= n {
                    ans.push(d);
                    let mut x = v;
                    while ans.len() < n {
                        for i in (0usize..10).rev() {
                            if (x >> i) & 1 == 1 || ans.len() + 1 + (x ^ (1 << i)).count_ones() as usize <= n {
                                ans.push(i);
                                x ^= 1 << i;
                                break;
                            }
                        }
                    }
                    assert!(x == 0);
                    break 'outer;
                }
            }
        }
        let mut s = String::new();
        for a in ans {
            s.push_str(&a.to_string());
        }
        writeln!(out, "{}", s).ok();
    }
}

fn main() {
    run();
}