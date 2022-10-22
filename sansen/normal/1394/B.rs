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

// 

fn dfs(x: usize, p: &mut Vec<(usize, usize)>, set: &std::collections::BTreeSet<((usize, usize), (usize, usize))>, k: usize) -> usize {
    if x > k {
        return 1;
    }
    let mut ans = 0;
    for i in 1..=x {
        let mut ok = !set.contains(&((x, i), (x, i)));
        for p in p.iter() {
            ok &= !set.contains(&((*p, (x, i))));
        }
        if ok {
            p.push((x, i));
            ans += dfs(x + 1, p, set, k);
            p.pop();
        }
    }
    ans
}

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        e: [(usize1, usize1, u32); m],
    }
    let mut e = e;
    e.sort_by_key(|e| e.2);
    let mut deg = vec![0; n];
    for &(a, _, _) in e.iter() {
        deg[a] += 1;
    }
    let mut cnt = vec![0; n];
    let mut g = vec![std::collections::BTreeMap::new(); n];
    for &(a, b, _) in e.iter() {
        cnt[a] += 1;
        *g[b].entry((deg[a], cnt[a])).or_insert(0) += 1;
    }
    let mut invalid = std::collections::BTreeSet::new();
    for g in g.iter() {
        for (i, (&a, &c)) in g.iter().enumerate() {
            if c > 1 {
                invalid.insert((a, a));
            }
            for (&b, _) in g.iter().take(i) {
                invalid.insert((a, b));
                invalid.insert((b, a));
            }
        }
    }
    let ans = dfs(1, &mut vec![], &invalid, k);
    println!("{}", ans);
}

fn main() {
    run();
}