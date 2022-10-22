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
        a: [u32; n],
        p: [usize1; n - 1],
    }
    let mut g = vec![vec![]; n];
    for (i, &p) in p.iter().enumerate() {
        g[i + 1].push(p);
        g[p].push(i + 1);
    }
    let mut topo = vec![0];
    let mut depth = vec![0; n];
    for i in 0..n {
        let v = topo[i];
        for u in g[v].clone() {
            let x = g[u].iter().position(|p| *p == v).unwrap();
            g[u].remove(x);
            topo.push(u);
            depth[u] = depth[v] + 1;
        }
    }
    let max = *depth.iter().max().unwrap();
    let mut xor = 0;
    for (i, a) in a.iter().enumerate() {
        if (max - depth[i]) & 1 == 0 {
            xor ^= *a;
        }
    }
    let mut ans = 0;
    let mut map = std::collections::BTreeMap::<(u32, u32), u64>::new();
    let mut cnt = [0; 2];
    for (i, a) in a.iter().enumerate() {
        let p = (max - depth[i]) & 1;
        ans += map.get(&(p ^ 1, xor ^ a)).cloned().unwrap_or(0);
        if xor == 0 {
            ans += cnt[p as usize];
        }
        cnt[p as usize] += 1;
        *map.entry((p, *a)).or_insert(0u64) += 1;
    }
    println!("{}", ans);
}

fn main() {
    run();
}