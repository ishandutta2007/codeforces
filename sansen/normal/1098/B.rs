// ---------- begin transpose ----------
fn transpose<T: Clone>(a: &[Vec<T>]) -> Vec<Vec<T>> {
    if a.is_empty() {
        return vec![];
    }
    let h = a.len();
    let w = a[0].len();
    assert!(a.iter().all(|a| a.len() == w));
    let mut ta: Vec<_> = (0..w).map(|_| Vec::with_capacity(h)).collect();
    for a in a.iter() {
        for (ta, a) in ta.iter_mut().zip(a.iter()) {
            ta.push(a.clone());
        }
    }
    ta
}
// ---------- end transpose ----------
// ---------- begin next_permutation ----------
fn next_permutation<T: Ord>(a: &mut [T]) -> bool {
    a.windows(2).rposition(|a| a[0] < a[1]).map_or(false, |x| {
        let y = a.iter().rposition(|b| a[x] < *b).unwrap();
        a.swap(x, y);
        a[(x + 1)..].reverse();
        true
    })
}
// ---------- end next_permutation ----------
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
        s: [bytes; h],
    }
    let mut s = s;
    let mut ans = (h * w + 1, s.clone());
    let mut op = "AGCT".bytes().collect::<Vec<_>>();
    op.sort();
    while {
        let x = [[op[0], op[1]], [op[2], op[3]]];
        for it in 0..2 {
            let mut a = s.clone();
            let mut cost = 0;
            for (x, a) in x.iter().cycle().zip(a.iter_mut()) {
                let mut cnt = [[0; 2]; 2];
                for (i, &a) in a.iter().enumerate() {
                    let cnt = &mut cnt[i & 1];
                    for (x, c) in x.iter().zip(cnt.iter_mut()) {
                        if *x == a {
                            *c += 1;
                        }
                    }
                }
                let y = if cnt[0][0] + cnt[1][1] >= cnt[0][1] + cnt[1][0] {
                    cost += a.len() - (cnt[0][0] + cnt[1][1]);
                    [x[0], x[1]]
                } else {
                    cost += a.len() - (cnt[0][1] + cnt[1][0]);
                    [x[1], x[0]]
                };
                for (x, a) in y.iter().cycle().zip(a.iter_mut()) {
                    *a = *x;
                }
            }
            for _ in 0..it {
                a = transpose(&a);
            }
            ans = std::cmp::min(ans, (cost, a));
            s = transpose(&s);
        }
        next_permutation(&mut op)
    } {}
    let mut s = String::new();
    for a in ans.1 {
        for a in a {
            s.push(a as char);
        }
        s.push('\n');
    }
    print!("{}", s);
}

fn rec(x: usize, y: usize, a: &mut [Vec<usize>]) {
    if x == a.len() {
        for a in a.iter() {
            for a in a.iter() {
                print!("{}", *a);
            }
            println!();
        }
        println!();
        return;
    }
    if y == a[0].len() {
        rec(x + 1, 0, a);
        return;
    }
    for i in 0..4 {
        a[x][y] = i;
        let mut ok = true;
        if x > 0 && y > 0 {
            let mut b = 1u32 << a[x][y];
            b |= 1 << a[x - 1][y];
            b |= 1 << a[x][y - 1];
            b |= 1 << a[x - 1][y - 1];
            ok &= b.count_ones() == 4;
        }
        if ok {
            rec(x, y + 1, a);
        }
    }
}

#[allow(dead_code)]
fn test() {
    let h = 4;
    let w = 4;
    let mut a = vec![vec![0; w]; h];
    rec(0, 0, &mut a);
}

fn main() {
    run();
}