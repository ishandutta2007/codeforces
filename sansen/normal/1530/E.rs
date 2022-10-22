// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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
// ---------- end input macro ----------

use std::io::Write;
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// 1
// 2
// f1
//
// 
// f01
// f1
// 2OK
// 
// f
// f=1
// 2
// 
// 2
// ab
// aabababab...abbbbbbbb
// f=1
// 1
// abaaaaaaaaaaaaa...ab
// 2
// abaaa....aaacb...
// 1
// 
// a
// aabababab... f=1
// 
// baf=2
// a ?
// 
// abaaaaaaaaaaaa...ac...
// 
// 
// aaa
// aababab..abaca
// 
// 
// (n-2)/2+2
// baaaaa.....aabbbbb
// 
// 
//
// 
// 1
// 1
// 
// (n-2)/2+2
// aabab...abbb...
// 
// 
// 3
// aba....acbb...bcc...
// 
// 
// baa.....aabb.....
// f=1
// 
// WA
// 
// 1
// 1?
// f=0, f=0
// 
// k
// k - 2 <= n - k 
// aabab...ababbbbb...
// f=1
// a
// aa
// a
// ...
// 
// k - 2 > n - k
// ?
// aa.. a
// ab 
// abaaaa....aaaaa cb....
// 
// 
// 2
// baa...aabb.. a
// abb...bbaaa...

fn run() {
    input! {
        t: usize,
        ask: [chars; t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for s in ask {
        let n = s.len();
        let mut map = Map::new();
        for s in s {
            *map.entry(s).or_insert(0) += 1;
        }
        let mut p = map.into_iter().collect::<Vec<_>>();
        if p.len() == 1 {
            let s = (0..n).map(|_| p[0].0).collect::<String>();
            writeln!(out, "{}", s).ok();
            continue;
        }
        if let Some(x) = p.iter().position(|p| p.1 == 1) {
            let mut ans = String::new();
            ans.push(p[x].0);
            p[x].1 -= 1;
            for (c, p) in p {
                for _ in 0..p {
                    ans.push(c);
                }
            }
            writeln!(out, "{}", ans).ok();
            continue;
        }
        let cnt = p[0].1;
        p[0].1 = 0;
        if cnt - 2 <= n - cnt {
            let mut ans = String::new();
            ans.push(p[0].0);
            ans.push(p[0].0);
            for _ in 2..cnt {
                let x = p.iter().position(|p| p.1 > 0).unwrap();
                ans.push(p[x].0);
                p[x].1 -= 1;
                ans.push(p[0].0);
            }
            while let Some(x) = p.iter().position(|p| p.1 > 0) {
                ans.push(p[x].0);
                p[x].1 -= 1;
            }
            writeln!(out, "{}", ans).ok();
            continue;
        }
        if p.len() > 2 {
            let mut ans = String::new();
            ans.push(p[0].0);
            ans.push(p[1].0);
            p[1].1 -= 1;
            for _ in 1..cnt {
                ans.push(p[0].0);
            }
            ans.push(p[2].0);
            p[2].1 -= 1;
            while let Some(x) = p.iter().position(|p| p.1 > 0) {
                ans.push(p[x].0);
                p[x].1 -= 1;
            }
            writeln!(out, "{}", ans).ok();
            continue;
        }
        let mut ans = String::new();
        ans.push(p[0].0);
        for _ in 0..p[1].1 {
            ans.push(p[1].0);
        }
        for _ in 1..cnt {
            ans.push(p[0].0);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}