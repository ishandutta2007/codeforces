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

fn run() {
    input! {
        n: usize,
        k: usize,
        s: [bytes; n],
    }
    let mut s = s;
    for s in s.iter_mut() {
        s.insert(0, b'X');
        s.push(b'X');
    }
    s.insert(0, vec![b'X'; n + 2]);
    s.push(vec![b'X'; n + 2]);
    let s = s;
    let mut id = 1usize;
    let mut cnt = vec![0];
    let mut hash = vec![vec![0; n + 2]; n + 2];
    for i in 1..=n {
        for j in 1..=n {
            if s[i][j] == b'X' || hash[i][j] > 0 {
                continue;
            }
            let mut c = 0;
            hash[i][j] = id;
            let mut q = std::collections::VecDeque::new();
            q.push_back((i, j));
            while let Some((x, y)) = q.pop_front() {
                c += 1;
                for &(x, y) in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)].iter() {
                    if hash[x][y] == 0 && s[x][y] == b'.' {
                        hash[x][y] = id;
                        q.push_back((x, y));
                    }
                }
            }
            cnt.push(c);
            id += 1;
        }
    }
    let mut ans = k * k;
    for i in 1..=(n - k + 1) {
        let mut elem = vec![0; id];
        let mut ban = 0;
        let mut sum = 0;
        for x in i..(i + k) {
            for y in 1..k {
                let p = hash[x][y];
                if p == 0 {
                    ban += 1;
                    continue;
                }
                elem[p] += 1;
                if elem[p] == 1 {
                    sum += cnt[p];
                }
            }
        }
        for j in 1..=(n - k + 1) {
            for x in i..(i + k) {
                let p = hash[x][j + k - 1];
                if p == 0 {
                    ban += 1;
                    continue;
                }
                elem[p] += 1;
                if elem[p] == 1 {
                    sum += cnt[p];
                }
            }
            let mut v = vec![];
            for &y in [j - 1, j + k].iter() {
                for x in i..(i + k) {
                    let p = hash[x][y];
                    if p == 0 {
                        continue;
                    }
                    v.push(p);
                }
            }
            for &x in [i - 1, i + k].iter() {
                for y in j..(j + k) {
                    let p = hash[x][y];
                    if p == 0 {
                        continue;
                    }
                    v.push(p);
                }
            }
            for &p in v.iter() {
                elem[p] += 1;
                if elem[p] == 1 {
                    sum += cnt[p];
                }
            }
            ans = std::cmp::max(ans, sum + ban);
            for p in v {
                elem[p] -= 1;
                if elem[p] == 0 {
                    sum -= cnt[p];
                }
            }
            for x in i..(i + k) {
                let p = hash[x][j];
                if p == 0 {
                    ban -= 1;
                    continue;
                }
                elem[p] -= 1;
                if elem[p] == 0 {
                    sum -= cnt[p];
                }
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}