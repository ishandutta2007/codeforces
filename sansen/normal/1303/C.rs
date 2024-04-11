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

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        s: [chars; t],
    }
    for s in s {
        let mut map = std::collections::BTreeMap::new();
        let mut set = std::collections::BTreeSet::new();
        let mut now = 0i32;
        let mut ok = true;
        map.insert(now, s[0]);
        set.insert(s[0]);
        for &c in s[1..].iter() {
            if map.get(&(now - 1)).map_or(false, |x| *x == c) {
                now -= 1;
            } else if map.get(&(now + 1)).map_or(false, |x| *x == c) {
                now += 1;
            } else if set.contains(&c) {
                ok = false;
                break;
            } else if map.get(&(now + 1)).is_none() {
                map.insert(now + 1, c);
                set.insert(c);
                now += 1;
            } else if map.get(&(now - 1)).is_none() {
                map.insert(now - 1, c);
                set.insert(c);
                now -= 1;
            } else {
                ok = false;
                break;
            }
        }
        if !ok {
            writeln!(out, "NO").ok();
        } else {
            writeln!(out, "YES").ok();
            let mut ans = String::new();
            for (_, v) in map.into_iter() {
                ans.push(v);
            }
            for c in "abcdefghijklmnopqrstuvwxyz".chars() {
                if !set.contains(&c) {
                    ans.push(c);
                }
            }
            writeln!(out, "{}", ans).ok();
        }
    }
}

fn main() {
    run();
}