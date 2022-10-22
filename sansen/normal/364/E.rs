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

// ---------- begin transpose ----------
fn transpose<T>(a: Vec<Vec<T>>) -> Vec<Vec<T>> {
    if a.is_empty() {
        return a;
    }
    let h = a.len();
    let w = a[0].len();
    assert!(a.iter().all(|a| a.len() == w));
    let mut ta: Vec<_> = (0..w).map(|_| Vec::with_capacity(h)).collect();
    for a in a {
        for (ta, a) in ta.iter_mut().zip(a) {
            ta.push(a);
        }
    }
    ta
}
// ---------- end transpose ----------
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
        h: usize,
        w: usize,
        k: usize,
        s: [bytes; h],
    }
    /*
    let mut s = vec![vec![b'0'; w]; h];
    for _ in 0..100 {
        let x = rand() % h;
        let y = rand() % w;
        s[x][y] = b'1';
    }
    */
    let s: Vec<Vec<_>> = s.into_iter().map(|s| s.into_iter().map(|s| s == b'1').collect()).collect();
    const LEN: usize = 7;
    type T = [usize; LEN];
    let merge = |mut a: T, mut b: T| -> T {
        let mut res = [0; LEN];
        let mut x = 0;
        let mut y = 0;
        while x + y < LEN {
            if a[x] == 0 {
                x += 1;
            } else if b[y] == 0 {
                y += 1;
            } else {
                let v = a[x].min(b[y]);
                res[x + y] += v;
                a[x] -= v;
                b[y] -= v;
            }
        }
        res
    };
    let mut ans = 0u64;
    let mut dfs = vec![s];
    let mut a = vec![[0; LEN]; h + w];
    let mut b = vec![[0; LEN]; h + w];
    let mut dp_a = a.clone();
    let mut dp_b = b.clone();
    while let Some(mut s) = dfs.pop() {
        if s.len() < s[0].len() {
            s = transpose(s);
        }
        if s.len() == 1 {
            if k == 0 && !s[0][0] {
                ans += 1;
            }
            if k == 1 && s[0][0] {
                ans += 1;
            }
            continue;
        }
        let h = s.len();
        let w = s[0].len();
        let mut u = s;
        let d = u.split_off(h / 2);
        u.reverse();
        a.clear();
        b.clear();
        a.resize(w, [0; LEN]);
        b.resize(w, [0; LEN]);
        for (u, a) in [(&u, &mut a), (&d, &mut b)].iter_mut() {
            for (i, a) in a.iter_mut().enumerate() {
                let mut po = 0;
                for u in u.iter() {
                    if u[i] {
                        po += 1;
                    }
                    if po >= LEN {
                        break;
                    }
                    a[po] += 1;
                }
            }
        }
        dfs.push(u);
        dfs.push(d);
        dp_a.clear();
        dp_b.clear();
        dp_a.extend(&a);
        dp_b.extend(&b);
        for j in 1..=w {
            for (a, b) in dp_a.iter().zip(&dp_b) {
                for (a, b) in a.iter().zip(b[..=k].iter().rev()) {
                    ans += *a as u64 * *b as u64;
                }
            }
            dp_a.pop();
            dp_b.pop();
            for (dp, a) in dp_a.iter_mut().zip(&a[j..]) {
                *dp = merge(*dp, *a);
            }
            for (dp, a) in dp_b.iter_mut().zip(&b[j..]) {
                *dp = merge(*dp, *a);
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}