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

fn run() {
    input! {
        n: i32,
    }
    let neighbor = |x: i32, y: i32| -> [(i32, i32); 8] {
        let mut res = [(x, y); 8];
        let d = [1, 2];
        for (i, res) in res.iter_mut().enumerate() {
            let mut dx = d[i & 1];
            let mut dy = 3 - dx;
            if i & 2 == 2 {
                dx *= -1;
            }
            if i & 4 == 4 {
                dy *= -1;
            }
            res.0 = x + dx;
            res.1 = y + dy;
        }
        res
    };
    let mut map = std::collections::BTreeMap::new();
    let mut s = vec![];
    let mut d = [(-1, 0), (1, 0), (-1, 2), (1, 2)];
    let mut add = [(-1, 1), (1, 1), (-1, 1), (1, 1)];
    for i in 0..n {
        s.push(d[0]);
        map.insert(d[0], 4);
        d[0].0 += add[0].0;
        d[0].1 += add[0].1;
        d.rotate_left(1);
        add.rotate_left(1);
        /*
        if i % 6 == 5 {
            d.iter_mut().for_each(|d| {
                d.0 += 1;
                d.1 += 1;
            });
        }
        */
    }
    let save = s.clone();
    let mut ans = 0;
    while let Some((x, y)) = s.pop() {
        ans += 1;
        for &(x, y) in neighbor(x, y).iter() {
            let po = map.entry((x, y)).or_insert(0);
            *po += 1;
            if *po == 4 {
                s.push((x, y));
            }
        }
    }
    assert!(n * n / 10 <= ans);
    for (a, b) in save {
        println!("{} {}", a, b);
    }
}

fn main() {
    run();
}