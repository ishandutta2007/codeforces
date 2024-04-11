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
        p: [[(i32, i32); n]; n],
    }
    let mut s = vec![vec!['.'; n]; n];
    for i in 0..n {
        for j in 0..n {
            if s[i][j] != '.' {
                continue;
            }
            if p[i][j].0 < 0 {
                for &(x, y, c) in [(i - 1, j, 'U'), (i + 1, j, 'D'), (i, j - 1, 'L'), (i, j + 1, 'R')].iter() {
                    if x < n && y < n && p[x][y].0 < 0 {
                        s[i][j] = c;
                        break;
                    }
                }
                if s[i][j] == '.' {
                    println!("INVALID");
                    return;
                }
            } else {
                let (a, b) = p[i][j];
                let (x, y) = ((a - 1) as usize, (b - 1) as usize);
                if p[x][y] != (a, b) {
                    println!("INVALID");
                    return;
                }
                s[x][y] = 'X';
                let mut q = std::collections::VecDeque::new();
                q.push_back((x, y));
                while let Some((x, y)) = q.pop_front() {
                    for &(x, y, c) in [(x - 1, y, 'D'), (x + 1, y, 'U'), (x, y - 1, 'R'), (x, y + 1, 'L')].iter() {
                        if x < n && y < n && s[x][y] == '.' && p[x][y] == (a, b) {
                            s[x][y] = c;
                            q.push_back((x, y));
                        }
                    }
                }
                if s[i][j] == '.' {
                    println!("INVALID");
                    return;
                }
            }
        }
    }
    let mut out = String::new();
    out.push_str(&format!("VALID\n"));
    for s in s {
        for c in s {
            out.push(c);
        }
        out.push('\n');
    }
    print!("{}", out);
}

fn main() {
    run();
}