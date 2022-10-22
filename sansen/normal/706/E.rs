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

fn run() {
    input! {
        h: usize,
        w: usize,
        q: usize,
        v: [[u32; w]; h],
        ask: [(usize, usize, usize, usize, usize, usize); q],
    }
    // 
    let mut s = vec![([(h + 2) * (w + 2); 4], 0); (h + 2) * (w + 2)];
    for i in 0..(h + 2) {
        for j in 0..(w + 2) {
            let v = i * (w + 2) + j;
            if i > 0 {
                let u = (i - 1) * (w + 2) + j;
                s[u].0[1] = v;
                s[v].0[3] = u;
            }
            if j > 0 {
                let u = i * (w + 2) + (j - 1);
                s[u].0[0] = v;
                s[v].0[2] = u;
            }
        }
    }
    for (i, v) in v.iter().enumerate() {
        for (j, v) in v.iter().enumerate() {
            s[(i + 1) * (w + 2) + j + 1].1 = *v;
        }
    }
    for (a, b, c, d, h, w) in ask {
        let pos = |a: usize, b: usize, s: &[([usize; 4], u32)]| -> usize {
            let mut v = 0;
            for _ in 0..a {
                v = s[v].0[1];
            }
            for _ in 0..b {
                v = s[v].0[0];
            }
            v
        };
        let mut a = pos(a, b, &s);
        let mut b = pos(c, d, &s);
        for (i, &len) in [w, h, w, h].iter().enumerate() {
            let dir = (i + 3) % 4;
            for _ in 0..len {
                let c = s[a].0[dir];
                let d = s[b].0[dir];
                s[a].0[dir] = d;
                s[b].0[dir] = c;
                s[c].0[dir ^ 2] = b;
                s[d].0[dir ^ 2] = a;
                a = s[a].0[i];
                b = s[b].0[i];
            }
            a = s[a].0[i ^ 2];
            b = s[b].0[i ^ 2];
        }
    }
    let mut pos = s[0].0[1];
    pos = s[pos].0[0];
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for _ in 0..h {
        let mut x = pos;
        for j in 0..w {
            if j > 0 {
                write!(out, " ").ok();
            }
            write!(out, "{}", s[x].1).ok();
            x = s[x].0[0];
        }
        writeln!(out).ok();
        pos = s[pos].0[1];
    }
}

fn main() {
    run();
}