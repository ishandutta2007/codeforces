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
        s: chars,
    }
    let mut map = std::collections::BTreeMap::new();
    for c in s {
        *map.entry(c).or_insert(0) += 1;
    }
    let mut a = vec![];
    for (_, v) in map {
        a.push(v);
    }
    let ans = if a.len() == 1 {
        false
    } else if a.len() == 2 {
        a[0] > 1 && a[1] > 1
    } else if a.len() == 3 {
        *a.iter().max().unwrap() > 1
    } else if a.len() == 4 {
        true
    } else {
        false
    };
    let ans = if ans {
        "Yes"
    } else {
        "No"
    };
    println!("{}", ans);
}

fn main() {
    run();
}