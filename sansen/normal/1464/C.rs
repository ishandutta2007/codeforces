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

type Set = std::collections::BTreeSet<Vec<i8>>;

fn dfs(n: usize) -> Set {
    let mut ans = Set::new();
    if n == 1 {
        ans.insert(vec![1]);
    } else {
        for i in 1..n {
            let l = dfs(i);
            let r = dfs(n - i);
            for l in l.iter() {
                for r in r.iter() {
                    let mut a = vec![];
                    a.extend_from_slice(l);
                    a.extend_from_slice(r);
                    a[..i].iter_mut().for_each(|a| *a *= -1);
                    ans.insert(a);
                }
            }
        }
    }
    ans
}

fn test() {
    for n in 2..=10 {
    let set = dfs(n);
    println!("{}", set.len());
    for a in set {
        for a in a.iter() {
            if *a == -1 {
                print!("0");
            } else {
                print!("1");
            }
        }
        println!();
    }
    }
}

fn run() {
    input! {
        n: usize,
        t: i64,
        s: bytes,
    }
    let mut cnt = vec![0; 26];
    for &c in s.iter().take(n - 2) {
        let k = (c - b'a') as usize;
        cnt[k] += 1;
    }
    let mut t = t;
    t += 1i64 << ((s[n - 2] - b'a') as i64);
    t -= 1i64 << ((s[n - 1] - b'a') as i64);
    for (i, &c) in cnt.iter().enumerate().rev() {
        let mut c = c;
        let v = 1i64 << i;
        let u = c.min(t.abs() / v);
        c -= u;
        if t < 0 {
            t += u * v;
        } else {
            t -= u * v;
        }
        c %= 2;
        if c > 0 {
            if t > 0 {
                t -= v;
            } else {
                t += v;
            }
        }
    }
    if t == 0 {
        println!("Yes");
    } else {
        println!("No");
    }
}

fn main() {
    run();
}