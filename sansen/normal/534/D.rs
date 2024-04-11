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

fn no() {
    println!("Impossible");
    std::process::exit(0);
}

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let mut set = vec![std::collections::BTreeSet::new(); 3];
    for (i, &a) in a.iter().enumerate() {
        set[a % 3].insert((a, i + 1));
    }
    let mut ans = vec![];
    let mut x = 0;
    while let Some(&p) = set[x % 3].range((x, 0)..).next() {
        if p.0 != x {
            no();
        }
        set[x % 3].remove(&p);
        ans.push(p.1);
        x += 1;
    }
    if set.iter().any(|set| set.range((x, 0)..).next().is_some()) {
        no();
    }
    while ans.len() < n {
        while set[x % 3].range((x, 0)..).next().is_none() {
            if x < 3 {
                no();
            }
            x -= 3;
        }
        let p = *set[x % 3].range((x, 0)..).next().unwrap();
        set[x % 3].remove(&p);
        ans.push(p.1);
        x += 1;
    }
    println!("Possible");
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}