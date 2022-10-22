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

fn count(s: &[String]) -> Vec<i32> {
    let mut cnt = vec![0; 1 + 8];
    let mut map = std::collections::BTreeMap::new();
    map.insert("M".to_string(), 0);
    let mut id = 1;
    for i in 0..=3 {
        for c in "SL".chars() {
            let mut s = String::new();
            for _ in 0..i {
                s.push('X');
            }
            s.push(c);
            map.insert(s, id);
            id += 1;
        }
    }
    for s in s.iter() {
        cnt[*map.get(s).unwrap()] += 1;
    }
    cnt
}

fn run() {
    input! {
        n: usize,
        a: [String; n],
        b: [String; n],
    }
    let a = count(&a);
    let b = count(&b);
    let mut ans = 0;
    for (a, b) in a.iter().zip(b.iter()) {
        ans += std::cmp::max(*a - *b, 0);
    }
    println!("{}", ans);
}

fn main() {
    run();
}