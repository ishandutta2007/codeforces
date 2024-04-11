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
        a: chars,
        b: chars,
    }
    let mut a = a;
    let mut b = b;
    for a in [&mut a, &mut b].iter_mut() {
        a.reverse();
        while let Some(&c) = a.last() {
            if c == '0' {
                a.pop();
            } else {
                break;
            }
        }
        a.reverse();
    }
    let ans = if a.len() == b.len() {
        match a.cmp(&b) {
            std::cmp::Ordering::Equal => '=',
            std::cmp::Ordering::Less => '<',
            std::cmp::Ordering::Greater => '>',
        }
    } else if a.len() > b.len() {
        '>'
    } else {
        '<'
    };
    println!("{}", ans);
}

fn main() {
    run();
}