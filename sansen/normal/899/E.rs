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

fn run() {
    input! {
        n: usize,
        a: [u32; n],
    }
    let mut b = vec![(0, 0); 1];
    for a in a {
        if b.last().unwrap().0 == a {
            b.last_mut().unwrap().1 += 1;
        } else {
            b.push((a, 1));
        }
    }
    b.push((1_000_000_000 + 1, 0));
    let n = b.len() - 2;
    let mut left = vec![0; n + 2];
    let mut right = vec![n + 1; n + 2];
    let mut h = std::collections::BinaryHeap::new();
    for i in 1..=n {
        left[i] = i - 1;
        right[i] = i + 1;
        h.push((b[i].1, !i));
    }
    let mut used = vec![false; n + 2];
    let mut ans = 0;
    while let Some((_, k)) = h.pop() {
        let k = !k;
        if used[k] {
            continue;
        }
        used[k] = true;
        ans += 1;
        let l = left[k];
        let mut r = right[k];
        if b[l].0 == b[r].0 {
            used[r] = true;
            b[l].1 += b[r].1;
            h.push((b[l].1, !l));
            r = right[r];
        }
        left[r] = l;
        right[l] = r;
    }
    println!("{}", ans);
}

fn main() {
    run();
}