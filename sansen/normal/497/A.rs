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
        _w: usize,
        s: [bytes; h],
    }
    let mut s = s;
    let mut x = 0;
    let mut range = vec![(0, h)];
    let mut ans = 0;
    while x < s[0].len() {
        let mut ok = true;
        for &(l, r) in range.iter() {
            ok &= s[l..r].windows(2).all(|s| s[0][x] <= s[1][x]);
        }
        if !ok {
            ans += 1;
            for s in s.iter_mut() {
                s.remove(x);
            }
        } else {
            let mut next = vec![];
            for &(l, r) in range.iter() {
                let mut p = l;
                let mut q = l;
                while q < r {
                    let c = s[q][x];
                    while q < r && s[q][x] == c {
                        q += 1;
                    }
                    next.push((p, q));
                    p = q;
                }
            }
            range = next;
            x += 1;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}