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
        p: [(u32, u32, u32, u32); 3],
    }
    let mut z = vec![];
    for &(a, b, c, d) in &p {
        z.push(a);
        z.push(b);
        z.push(c);
        z.push(d);
        z.push(c - 1);
        z.push(d - 1);
    }
    z.sort();
    z.dedup();
    let n = z.len();
    let mut ok = vec![vec![true; n]; n];
    for &(a, b, c, d) in &p[1..] {
        let a = z.binary_search(&a).unwrap();
        let b = z.binary_search(&b).unwrap();
        let c = z.binary_search(&c).unwrap();
        let d = z.binary_search(&d).unwrap();
        for i in a..c {
            for j in b..d {
                ok[i][j] = false;
            }
        }
    }
    let (a, b, c, d) = p[0];
    let a = z.binary_search(&a).unwrap();
    let b = z.binary_search(&b).unwrap();
    let c = z.binary_search(&c).unwrap();
    let d = z.binary_search(&d).unwrap();
    for i in a..c {
        for j in b..d {
            if ok[i][j] {
                println!("YES");
                return;
            }
        }
    }
    println!("NO");
}

fn main() {
    run();
}