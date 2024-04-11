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
        _n: usize,
        k: i32,
        s: chars,
    }
    let mut dp = vec![];
    dp.push(std::collections::BTreeSet::new());
    dp[0].insert(0i32);
    for &c in s.iter() {
        let mut set = std::collections::BTreeSet::new();
        for &v in dp.last().unwrap().iter() {
            if v.abs() >= k {
                continue;
            }
            match c {
                '?' => {
                    set.insert(v - 1);
                    set.insert(v);
                    set.insert(v + 1);
                },
                'W' => {
                    set.insert(v + 1);
                },
                'L' => {
                    set.insert(v - 1);
                },
                'D' => {
                    set.insert(v);
                },
                _ => unreachable!(),
            }
        }
        dp.push(set);
    }
    let ans = if dp.last().unwrap().contains(&k) {
        let mut now = k;
        let mut ans = vec![];
        for (i, &c) in s.iter().enumerate().rev() {
            match c {
                '?' => {
                    for &(d, c) in [(now - 1, 'W'), (now, 'D'), (now + 1, 'L')].iter() {
                        if d.abs() < k && dp[i].contains(&d) {
                            ans.push(c);
                            now = d;
                            break;
                        }
                    }
                },
                'W' => {
                    ans.push(c);
                    now -= 1;
                },
                'L' => {
                    ans.push(c);
                    now += 1;
                },
                'D' => {
                    ans.push(c);
                },
                _ => unreachable!(),
            }
        }
        ans.into_iter().rev().collect()
    } else if dp.last().unwrap().contains(&(-k)) {
        let mut now = -k;
        let mut ans = vec![];
        for (i, &c) in s.iter().enumerate().rev() {
            match c {
                '?' => {
                    for &(d, c) in [(now - 1, 'W'), (now, 'D'), (now + 1, 'L')].iter() {
                        if d.abs() < k && dp[i].contains(&d) {
                            ans.push(c);
                            now = d;
                            break;
                        }
                    }
                },
                'W' => {
                    ans.push(c);
                    now -= 1;
                },
                'L' => {
                    ans.push(c);
                    now += 1;
                },
                'D' => {
                    ans.push(c);
                },
                _ => unreachable!(),
            }
        }
        ans.into_iter().rev().collect()
    } else {
        "NO".to_string()
    };
    println!("{}", ans);
}

fn main() {
    run();
}