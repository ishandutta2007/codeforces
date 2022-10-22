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

// 2 <= k < n <= 1000
// 
// 
// 1, ..., n - 1  k2
// c = ceil((n - 1) / (k - 1)) 
// 2
// 1k
// k=2
// k?

fn dfs(l: usize, r: usize, color: &mut [Vec<u32>], id: u32, k: usize) {
    if l + 1 >= r {
        return;
    }
    let mut cnt = vec![(r - l) / k; k];
    for cnt in cnt.iter_mut().take((r - l) % k) {
        *cnt += 1;
    }
    let mut dp = cnt.clone();
    let mut kind = vec![0; r - l];
    let mut pos = 0;
    for id in kind.iter_mut() {
        if dp[pos] == 0 {
            pos += 1;
        }
        *id = pos;
        dp[pos] -= 1;
    }
    for (i, a) in kind.iter().enumerate() {
        for (j, b) in kind.iter().enumerate().take(i) {
            if *a != *b {
                color[l + j][l + i] = id;
                color[l + i][l + j] = id;
            }
        }
    }
    let mut sum = l;
    for cnt in cnt {
        dfs(sum, sum + cnt, color, id + 1, k);
        sum += cnt;
    }
}

fn run() {
    input!(n: usize, k: usize);
    let mut color = vec![vec![0; n]; n];
    dfs(0, n, &mut color, 1, k);
    let mut s = String::new();
    for i in 0..n {
        for j in (i + 1)..n {
            s.push_str(&format!("{} ", color[i][j]));
        }
    }
    s.pop();
    let max = *color.iter().flatten().max().unwrap();
    println!("{}", max);
    println!("{}", s);
}

fn main() {
    run();
}