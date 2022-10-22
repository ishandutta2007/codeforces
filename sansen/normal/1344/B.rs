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

fn transpose<T: Clone>(a: &[Vec<T>]) -> Vec<Vec<T>> {
    if a.is_empty() {
        return vec![];
    }
    let h = a.len();
    let w = a[0].len();
    assert!(a.iter().all(|a| a.len() == w));
    let mut ta = Vec::with_capacity(w);
    for j in 0..w {
        let mut b = Vec::with_capacity(h);
        for i in 0..h {
            b.push(a[i][j].clone());
        }
        ta.push(b);
    }
    ta
}

fn impossible() {
    println!("-1");
    std::process::exit(0);
}

fn run() {
    input! {
        h: usize,
        w: usize,
        s: [chars; h],
    }
    let ts = transpose(&s);
    let all_white = |s: &[char]| -> bool {
        s.iter().all(|c| *c == '.')
    };
    let row = s.iter().any(|s| all_white(s));
    let col = ts.iter().any(|s| all_white(s));
    if row ^ col {
        impossible();
    }
    for s in [&s, &ts].iter() {
        for s in s.iter() {
            if all_white(s) {
                continue;
            }
            let l = s.iter().position(|c| *c == '#').unwrap();
            let r = s.iter().rposition(|c| *c == '#').unwrap();
            if s[l..=r].iter().any(|c| *c == '.') {
                impossible();
            }
        }
    }
    let mut s = s;
    let mut ans = 0;
    for i in 0..h {
        for j in 0..w {
            if s[i][j] == '.' {
                continue;
            }
            ans += 1;
            s[i][j] = '.';
            let mut stack = vec![(i, j)];
            while let Some((r, c)) = stack.pop() {
                for &(x, y) in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)].iter() {
                    if x < h && y < w && s[x][y] == '#' {
                        s[x][y] = '.';
                        stack.push((x, y));
                    }
                }
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}