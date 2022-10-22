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
    let cond = |b: bool| {
        if !b {
            println!("Not unique");
            std::process::exit(0);
        }
    };
    let mut s = s;
    for s in s.iter_mut() {
        s.insert(0, b'*');
        s.push(b'*');
    }
    s.insert(0, vec![b'*'; w + 2]);
    s.push(vec![b'*'; w + 2]);
    let neighbor = |i: usize, j: usize| -> [(usize, usize, u8, u8); 4] {
        [
            (i - 1, j, b'v', b'^'),
            (i + 1, j, b'^', b'v'),
            (i, j - 1, b'>', b'<'),
            (i, j + 1, b'<', b'>'),
        ]
    };
    for i in 1..=h {
        for j in 1..=w {
            if s[i][j] != b'.' {
                continue;
            }
            let mut cnt = 0;
            let mut q = (0, 0, 0, 0);
            for &p in neighbor(i, j).iter() {
                if s[p.0][p.1] == b'.' {
                    cnt += 1;
                    q = p;
                }
            }
            if cnt == 1 {
                let mut que = std::collections::VecDeque::new();
                s[i][j] = q.2;
                s[q.0][q.1] = q.3;
                for &(x, y, _, _) in neighbor(i, j).iter().chain(neighbor(q.0, q.1).iter()) {
                    if s[x][y] == b'.' {
                        que.push_back((x, y));
                    }
                }
                while let Some((i, j)) = que.pop_front() {
                    if s[i][j] != b'.' {
                        continue;
                    }
                    let mut cnt = 0;
                    let mut q = (0, 0, 0, 0);
                    for &p in neighbor(i, j).iter() {
                        if s[p.0][p.1] == b'.' {
                            cnt += 1;
                            q = p;
                        }
                    }
                    if cnt == 1 {
                        s[i][j] = q.2;
                        s[q.0][q.1] = q.3;
                        for &(x, y, _, _) in neighbor(i, j).iter().chain(neighbor(q.0, q.1).iter())
                        {
                            if s[x][y] == b'.' {
                                que.push_back((x, y));
                            }
                        }
                    }
                }
            }
        }
    }
    cond(s.iter().flatten().all(|s| *s != b'.'));
    let mut ans = String::new();
    for i in 1..=h {
        for j in 1..=w {
            ans.push(s[i][j] as char);
        }
        ans.push('\n');
    }
    print!("{}", ans);
}

fn main() {
    run();
}