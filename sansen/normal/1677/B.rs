use std::io::Write;
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// 
// 

fn run() {
    input! {
        t: usize,
        ask: [(usize, usize, bytes); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (h, w, s) in ask {
        let mut state = vec![false; w];
        let mut ans = vec![0u32; h * w];
        let mut cnt = 0;
        for (ans, s) in ans.chunks_mut(w).zip(s.chunks(w)) {
            for (ans, (state, s)) in ans.iter_mut().zip(state.iter_mut().zip(s.iter())) {
                if *s == b'1' && !*state {
                    *state = true;
                    cnt += 1;
                }
                *ans = cnt;
            }
        }
        let mut sum = vec![0; h * w + 1];
        for (i, s) in s.iter().enumerate() {
            sum[i + 1] = sum[i];
            if *s == b'1' {
                sum[i + 1] += 1;
            }
        }
        let mut add = vec![0; h * w];
        for i in 0..(h * w) {
            if i < w {
                add[i] = (sum[i + 1] > 0) as u32;
            } else {
                add[i] = add[i - w] + (sum[i + 1] - sum[i + 1 - w] > 0) as u32;
            }
        }
        use util::*;
        writeln!(out, "{}", ans.iter().zip(add).map(|p| *p.0 + p.1).join(" ")).ok();
    }
}

fn main() {
    run();
}

mod util {
    pub trait Join {
        fn join(self, sep: &str) -> String;
    }

    impl<T, I> Join for I
    where
        I: Iterator<Item = T>,
        T: std::fmt::Display,
    {
        fn join(self, sep: &str) -> String {
            let mut s = String::new();
            use std::fmt::*;
            for (i, v) in self.enumerate() {
                if i > 0 {
                    write!(&mut s, "{}", sep).ok();
                }
                write!(&mut s, "{}", v).ok();
            }
            s
        }
    }
}
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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