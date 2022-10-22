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
        a: [[u32; w]; h],
        b: [[u32; w]; h],
    }
    let mut cnt = vec![0; w];
    let mut fix = vec![vec![false; w]; h - 1];
    for (b, fix) in b.windows(2).zip(fix.iter_mut()) {
        for (j, (x, y)) in b[0].iter().zip(b[1].iter()).enumerate() {
            if *x > *y {
                fix[j] = true;
                cnt[j] += 1;
            }
        }
    }
    let mut used = vec![false; w];
    let mut row = vec![false; h - 1];
    let mut ans = vec![];
    while let Some(y) = (0..w).find(|&y| !used[y] && cnt[y] == 0) {
        ans.push(y);
        used[y] = true;
        for (i, b) in b.windows(2).enumerate() {
            if row[i] {
                continue;
            }
            if b[0][y] < b[1][y] {
                row[i] = true;
                for k in 0..w {
                    if fix[i][k] {
                        cnt[k] -= 1;
                    }
                    fix[i][k] = false;
                }
            }
        }
    }
    ans.reverse();
    let mut a = a;
    let mut buf = vec![vec![]; 1500 + 1];
    for x in ans.iter() {
        for (i, a) in a.iter().enumerate() {
            buf[a[*x] as usize].push(i);
        }
        let mut next = vec![];
        for b in buf.iter_mut() {
            for x in b.drain(..) {
                next.push(std::mem::take(&mut a[x]));
            }
        }
        a = next;
    }
    if a != b {
        println!("-1");
    } else {
        println!("{}", ans.len());
        let mut s = String::new();
        for x in ans {
            s.push_str(&format!("{} ", x + 1));
        }
        s.pop();
        println!("{}", s);
    }
}

fn main() {
    run();
}