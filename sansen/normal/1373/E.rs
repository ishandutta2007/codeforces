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

use std::io::Write;


fn digit_sum(mut n: u64) -> u64 {
    let mut s = 0;
    while n > 0 {
        s += n % 10;
        n /= 10;
    }
    s
}

fn test() {
    for k in 1..=9 {
        let mut set = (0..=150).collect::<std::collections::BTreeSet<_>>();
        let mut sum = 0;
        for x in 0..=100000000 {
            sum += digit_sum(x);
            if x < k {
                continue;
            }
            if set.contains(&sum) {
                println!("K = {}, N = {}: {}", k, sum, x - k);
                set.remove(&sum);
            }
            sum -= digit_sum(x - k);
        }
        println!("K = {}, remain {}", k, set.len());
    }
}

// K = 0 
// K > 0 ?
// K = 1 
// K = 1 
// N K = 1 8,9
// (1~9)9...9(8, 9) 

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [(u64, u64); t],
    }
    let mut map = std::collections::BTreeMap::new();
    for x in 0..=100000 {
        let mut sum = 0;
        for k in 0..=9 {
            sum += digit_sum(x + k);
            if sum > 150 {
                break;
            }
            if !map.contains_key(&(sum, k)) {
                map.insert((sum, k), x);
            }
        }
    }
    for k in 0..=9 {
        for d in 1u64..=16 {
            let d = 10u64.pow(d as u32 + 2);
            for s in 1..=9 {
                for r in 8..=9 {
                    for p in (9 - k)..=9 {
                        let x = d - 100 + s * d + r * 10 + p;
                        let mut sum = 0;
                        for i in 0..=k {
                            sum += digit_sum(x + i);
                        }
                        if !map.contains_key(&(sum, k)) {
                            map.insert((sum, k), x);
                        }
                    }
                }
            }
        }
    }
    for (n, k) in ask {
        if let Some(v) = map.get(&(n, k)) {
            writeln!(out, "{}", v).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}

fn main() {
    run();
//    test();
}