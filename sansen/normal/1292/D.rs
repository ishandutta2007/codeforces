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
        n: usize,
        a: [usize; n],
    }
    let m = 5000;
    let mut weight = vec![0; m + 1];
    for a in a {
        if a == 0 {
            weight[1] += 1;
        } else {
            weight[a] += 1;
        }
    }
    let mut factor: Vec<usize> = vec![m; m + 1];
    let mut prime = vec![];
    for i in 2..=m {
        if factor[i] == m {
            for j in 1..=(m / i) {
                factor[j * i] = prime.len();
            }
            prime.push(i);
        }
    }
    let mut cnt = vec![vec![0; prime.len()]; m + 1];
    for i in 2..=m {
        let mut c = cnt[i - 1].clone();
        let mut t = i;
        while t > 1 {
            let k = factor[t];
            let p = prime[k];
            while t % p == 0 {
                c[k] += 1;
                t /= p;
            }
        }
        cnt[i] = c;
    }
    let cnt = cnt;
    let mut root_sum = 0u64;
    for i in 1..=m {
        root_sum += cnt[i].iter().fold(0, |s, a| s + *a) * weight[i];
    }
    let all = n as u64;
    let root_sum = root_sum;
    let mut dfs = vec![(2, m + 1, prime.len() - 1, 0, all - weight[1], root_sum)];
    let mut ans = root_sum;
    while let Some((l, r, index, num, sum, w)) = dfs.pop() {
        ans = std::cmp::min(ans, w);
        if 2 * sum <= all || l >= r || index >= prime.len() {
            continue;
        }
        assert!(num <= cnt[l][index]);
        if cnt[l][index] > num {
            dfs.push((l, r, index, num + 1, sum, w + all - 2 * sum));
        } else if cnt[l][index] == cnt[r - 1][index] {
            dfs.push((l, r, index - 1, 0, sum, w));
        } else {
            let mut zero = 0;
            let mut k = l;
            while k < r && cnt[k][index] == cnt[l][index] {
                zero += weight[k];
                k += 1;
            }
            dfs.push((l, k, index - 1, 0, zero, w));
            dfs.push((k, r, index, num, sum - zero, w));
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}