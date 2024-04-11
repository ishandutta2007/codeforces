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
        n: usize,
        a: [i64; n],
    }
    let b = a.iter().cloned().cycle().take(2 * n).collect::<Vec<_>>();
    let mut next = vec![2 * n; 2 * n + 1];
    let mut sum = 0;
    let mut map = std::collections::BTreeMap::new();
    map.insert(sum, 0);
    for (i, b) in b.iter().enumerate() {
        sum += *b;
        if let Some(x) = map.insert(sum, i + 1) {
            next[x] = i + 1;
        }
    }
    let mut table = vec![];
    while next.iter().any(|p| *p != 2 * n) {
        let mut p = next.clone();
        for i in 0..=(2 * n) {
            p[i] = next[next[i]];
        }
        table.push(next);
        next = p;
    }
    let mut ans = n - 1;
    for i in 0..n {
        let mut pos = i;
        let mut cnt = 1;
        for (j, table) in table.iter().enumerate().rev() {
            if table[pos] < i + n {
                pos = table[pos];
                cnt += 1 << j;
            }
        }
        ans = ans.min(n - cnt);
    }
    println!("{}", ans);
}

fn main() {
    run();
}