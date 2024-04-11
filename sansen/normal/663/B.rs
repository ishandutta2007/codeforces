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

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        s: [chars; n],
    }
    let mut p = 0;
    let mut map = std::collections::BTreeMap::new();
    for n in (1989i64..).take(100000) {
        let mut key = vec![];
        let mut d = 1;
        loop {
            key.insert(0, n / d % 10);
            d *= 10;
            let mut s = String::new();
            for k in key.iter() {
                s.push_str(&format!("{}", *k));
            }
            if map.contains_key(&s) {
                continue;
            }
            if n != s.parse::<i64>().unwrap() {
//                println!("{} : {}", n, s);
                if p == 0 {
                    p = n;
                }
            } else if p > 0 {
//                println!("{} {}", p, n);
                p = 0;
            }
            map.insert(s, n);
            break;
        }
    }
    let solve = |n: String| -> String {
        if let Some(v) = map.get(&n) {
            return format!("{}", v);
        }
        let v = n.parse::<i64>().unwrap();
        let q = v / 10000;
        let r = v % 10000;
        let mut cond = false;
        cond |= q < 10i64.pow((n.len() - 4) as u32) / 9;
        cond |= format!("{}", q).chars().all(|c| c == '1') && r < 3099;
        if cond {
            let d = 10i64.pow(n.len() as u32);
            format!("{}", v + d)
        } else {
            n
        }
    };
    for s in s {
        let n = s[4..].iter().cloned().collect::<String>();
        let ans = solve(n);
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}