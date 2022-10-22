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
        a: usize,
        b: usize,
        c: usize,
        m: usize,
        p: [(u64, chars); m],
    }
    let mut x = vec![];
    let mut y = vec![];
    for (v, s) in p {
        if s[0] == 'U' {
            x.push(v);
        } else {
            y.push(v);
        }
    }
    x.sort();
    y.sort();
    x.reverse();
    y.reverse();
    let mut ans = 0;
    let mut cnt = 0;
    for (x, a) in [(&mut x, a), (&mut y, b)].iter_mut() {
        for _ in 0..std::cmp::min(x.len(), *a) {
            ans += x.pop().unwrap();
            cnt += 1;
        }
    }
    x.append(&mut y);
    x.sort();
    x.reverse();
    for _ in 0..c {
        if let Some(v) = x.pop() {
            ans += v;
            cnt += 1;
        }
    }
    println!("{} {}", cnt, ans);
}

fn main() {
    run();
}