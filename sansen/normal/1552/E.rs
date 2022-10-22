fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> usize {
    static mut X: usize = 0;
    unsafe {
        if X == 0 {
            X = rand_memory();
        }
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}

fn shuffle<T>(a: &mut [T]) {
    for i in 1..a.len() {
        let p = rand() % (i + 1);
        a.swap(i, p);
    }
}

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

fn solve(n: usize, k: usize, c: &[usize]) -> Vec<(usize, usize, usize)> {
    let mut g = vec![vec![]; n];
    for (i, c) in c.iter().enumerate() {
        g[*c].push(i);
    }
    let mut p = vec![];
    for (i, g) in g.iter().enumerate() {
        for g in g.windows(2) {
            p.push((g[0], g[1], i));
        }
    }
    p.sort_by_key(|p| p.1);
    let mut ans = vec![];
    let mut used = vec![false; n];
    let mut cnt = vec![0; n * k];
    for (l, r, x) in p {
        if used[x] {
            continue;
        }
        if cnt[l..=r].iter().all(|c| *c + 1 <= (n + k - 2) / (k - 1)) {
            cnt[l..=r].iter_mut().for_each(|c| *c += 1);
            ans.push((l, r, x));
            used[x] = true;
        }
    }
    assert!(ans.len() == n, "Hack! {:?}", c);
    ans
}

fn run() {
    input! {
        n: usize,
        k: usize,
        c: [usize1; n * k],
    }
    let mut ans = solve(n, k, &c);
    ans.sort_by_key(|p| p.2);
    for (l, r, _) in ans {
        println!("{} {}", l + 1, r + 1);
    }
    /*
    let n = 20;
    let k = 3;
    let mut a = vec![];
    for i in 0..n {
        for _ in 0..k {
            a.push(i);
        }
    }
    for _ in 0..10000 {
        shuffle(&mut a);
        solve(n, k, &a);
    }
    */
}

fn main() {
    run();
}