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

fn replace(k: usize, l: usize, r: usize, x: usize, y: usize, seg: &mut [(u64, usize)], d: &[usize]) {
    if r <= x || y <= l || seg[k].1 <= 2 {
        return;
    }
    if l + 1 == r {
        let v = seg[k].1;
        seg[k] = (d[v] as u64, d[v]);
    } else {
        let m = (l + r) / 2;
        replace(2 * k, l, m, x, y, seg, d);
        replace(2 * k + 1, m, r, x, y, seg, d);
        let (a, b) = seg[2 * k];
        let (c, d) = seg[2 * k + 1];
        seg[k] = (a + c, std::cmp::max(b, d));
    }
}

fn sum(k: usize, l: usize, r: usize, x: usize, y: usize, seg: &[(u64, usize)]) -> u64 {
    if r <= x || y <= l {
        return 0;
    }
    if x <= l && r <= y {
        return seg[k].0;
    }
    let m = (l + r) / 2;
    sum(2 * k, l, m, x, y, seg) + sum(2 * k + 1, m, r, x, y, seg)
}

fn run() {
    input! {
        n: usize,
        m: usize,
        a: [usize; n],
        ask: [(u8, usize1, usize); m],
    }
    let mut d = vec![0; *a.iter().max().unwrap() + 1];
    for i in 1..=d.len() {
        let mut j = i;
        while let Some(d) = d.get_mut(j) {
            *d += 1;
            j += i;
        }
    }
    let size = n.next_power_of_two();
    let mut seg = vec![(0u64, 0usize); 2 * size];
    for (s, a) in seg[size..].iter_mut().zip(a.iter()) {
        *s = (*a as u64, *a);
    }
    for i in (1..size).rev() {
        let (a, b) = seg[2 * i];
        let (c, d) = seg[2 * i + 1];
        seg[i] = (a + c, std::cmp::max(b, d));
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (t, l, r) in ask {
        if t == 1 {
            replace(1, 0, size, l, r, &mut seg, &d);
        } else {
            let ans = sum(1, 0, size, l, r, &seg);
            writeln!(out, "{}", ans).ok();
        }
    }
}

fn main() {
    run();
}