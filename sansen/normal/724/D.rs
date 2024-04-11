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

// a
// ab
// abc
// ...
// 
// 
// 

fn run() {
    input! {
        m: usize,
        s: bytes,
    }
    let f = 26;
    let mut index = vec![vec![]; f];
    for (i, c) in s.iter().enumerate() {
        let x = (*c - b'a') as usize;
        index[x].push(i);
    }
    // 0: 
    // 1: 
    // 2: 
    let mut state = vec![2; s.len()];
    let mut ans = String::new();
    for (i, index) in index.iter().enumerate() {
        for x in index.iter() {
            state[*x] = 1;
        }
        let mut ok = true;
        let mut last = s.len();
        for (i, state) in state.iter().enumerate().rev() {
            if *state < 2 {
                last = i;
            }
            if last - i >= m {
                ok = false;
                break;
            }
        }
        if ok {
            let c = (b'a' + i as u8) as char;
            let mut prev = s.len();
            let mut last = s.len();
            for (i, state) in state.iter().enumerate().rev() {
                if *state == 0 {
                    last = i;
                } else if *state == 1 {
                    prev = i;
                }
                if last - i >= m {
                    last = prev;
                    ans.push(c);
                }
            }
            println!("{}", ans);
            return;
        }
        for x in index.iter() {
            state[*x] = 0;
            ans.push((b'a' + i as u8) as char);
        }
    }
}

fn main() {
    run();
}