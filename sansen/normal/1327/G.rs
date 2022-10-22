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
        k: usize,
        t: [(bytes, i64); k],
        s: bytes,
    }
    const P: usize = 14;
    let mut next = vec![[0; P]];
    let mut score = vec![0];
    for (t, c) in t {
        let mut pos = 0;
        for t in t {
            let x = (t - b'a') as usize;
            if next[pos][x] == 0 {
                let node = next.len();
                next[pos][x] = node;
                next.push([0; P]);
                score.push(0);
            }
            pos = next[pos][x];
        }
        score[pos] += c;
    }
    let mut fail = vec![0; score.len()];
    let mut q = std::collections::VecDeque::new();
    for i in 0..P {
        if next[0][i] != 0 {
            q.push_back(next[0][i]);
        }
    }
    while let Some(v) = q.pop_front() {
        score[v] += score[fail[v]];
        for j in 0..P {
            let u = next[v][j];
            if u == 0 {
                continue;
            }
            q.push_back(u);
            let mut f = fail[v];
            while f > 0 && next[f][j] == 0 {
                f = fail[f];
            }
            fail[u] = next[f][j];
        }
    }
    let mut topo = vec![0];
    for i in 0..score.len() {
        let v = topo[i];
        for j in 0..P {
            let u = next[v][j];
            if u == 0 {
                next[v][j] = next[fail[v]][j];
            } else {
                topo.push(u);
            }
        }
    }
    let (next, score) = (next, score);
    let mut dp = vec![((0usize, (1 << P) - 1), 0)];
    let mut l = 0;
    while l < s.len() {
        let r = l + s[l..]
            .iter()
            .position(|s| *s == b'?')
            .unwrap_or(s.len() - l);
        let mut skip = (0..score.len()).map(|p| (p, 0)).collect::<Vec<_>>();
        for s in s[l..r].iter() {
            let x = (*s - b'a') as usize;
            for po in skip.iter_mut() {
                po.0 = next[po.0][x];
                po.1 += score[po.0];
            }
        }
        let mut next_dp = vec![];
        for ((pos, rem), dp) in dp {
            let dp = dp + skip[pos].1;
            let pos = skip[pos].0;
            if r == s.len() {
                next_dp.push(((pos, rem), dp));
                continue;
            }
            for j in 0..P {
                if rem >> j & 1 == 1 {
                    let rem = rem ^ (1 << j);
                    let pos = next[pos][j];
                    let dp = dp + score[pos];
                    next_dp.push(((pos, rem), dp));
                }
            }
        }
        dp = next_dp;
        dp.sort_by_key(|p| p.0);
        dp.dedup_by(|a, b| {
            a.0 == b.0 && {
                b.1 = a.1.max(b.1);
                true
            }
        });
        l = r + 1;
    }
    let ans = dp.iter().map(|dp| dp.1).max().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}