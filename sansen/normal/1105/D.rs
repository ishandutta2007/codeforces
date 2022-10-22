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

fn run() {
    input! {
        h: usize,
        w: usize,
        p: usize,
        a: [usize; p],
        s: [bytes; h],
    }
    let mut dfs = vec![vec![]; p];
    for (i, s) in s.iter().enumerate() {
        for (j, s) in s.iter().enumerate() {
            if b'1' <= *s && *s <= b'9' {
                let k = (*s - b'1') as usize;
                dfs[k].push((i, j));
            }
        }
    }
    let mut s = s;
    while !dfs.iter().all(|p| p.is_empty()) {
        for (i, (&a, dfs)) in a.iter().zip(dfs.iter_mut()).enumerate() {
            let c = b'1' + i as u8;
            let mut now = std::mem::take(dfs);
            for _ in 0..a {
                if now.is_empty() {
                    break;
                }
                let mut next = vec![];
                for (i, j) in now {
                    for &(x, y) in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)].iter() {
                        if x < h && y < w && s[x][y] == b'.' {
                            s[x][y] = c;
                            next.push((x, y));
                        }
                    }
                }
                now = next;
            }
            *dfs = now;
        }
    }
    let mut ans = vec![0; p];
    for s in s.iter().flatten() {
        if b'1' <= *s && *s <= b'9' {
            ans[(*s - b'1') as usize] += 1;
        }
    }
    for i in 0..p {
        if i > 0 {
            print!(" ");
        }
        print!("{}", ans[i]);
    }
    println!();
}

fn main() {
    run();
}