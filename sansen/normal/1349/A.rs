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
        a: [usize; n],
    }
    let m = 200_000;
    let mut p: Vec<usize> = (0..=m).collect();
    for i in 2..=m {
        if p[i] == i {
            let mut j = i;
            while let Some(p) = p.get_mut(j) {
                *p = i;
                j += i;
            }
        }
    }
    let mut f = vec![];
    for a in a.iter().take(2) {
        let mut x = *a;
        while x > 1 {
            let p = p[x];
            f.push(p);
            while x % p == 0 {
                x /= p;
            }
        }
    }
    f.sort();
    f.dedup();
    let mut cnt = vec![vec![]; f.len()];
    for a in a.iter() {
        let mut x = *a;
        let mut y = vec![0; f.len()];
        while x > 1 {
            let p = p[x];
            let mut c = 0;
            while x % p == 0 {
                x /= p;
                c += 1;
            }
            if let Ok(k) = f.binary_search(&p) {
                y[k] = c;
            }
        }
        for (c, y) in cnt.iter_mut().zip(y.iter()) {
            c.push(*y);
        }
    }
    let mut ans = 1u64;
    for (p, c) in f.iter().zip(cnt.iter_mut()) {
        c.sort();
        let a = c[1];
        ans *= (*p as u64).pow(a as u32);
    }
    println!("{}", ans);
}

fn main() {
    run();
}