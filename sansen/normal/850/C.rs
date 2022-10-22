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

// Grundyok
// 
// 1
// 2^29 ...
// 
// dfs

fn factorize(mut n: u32) -> Vec<(u32, usize)> {
    let mut ans = vec![];
    for k in 2.. {
        if k * k > n {
            break;
        }
        if n % k == 0 {
            let mut c = 0;
            while n % k == 0 {
                n /= k;
                c += 1;
            }
            ans.push((k, c));
        }
    }
    if n > 1 {
        ans.push((n, 1));
    }
    ans
}

fn calc(bit: usize, memo: &mut std::collections::BTreeMap<usize, usize>) -> usize {
    if bit == 1 {
        return 0;
    }
    if let Some(&v) = memo.get(&bit) {
        return v;
    }
    let mut set = std::collections::BTreeSet::new();
    for k in 1.. {
        let mask = (1 << k) - 1;
        let x = bit >> k;
        if x == 0 {
            break;
        }
        let y = bit & mask;
        set.insert(calc(x | y, memo));
    }
    let mut g = 0;
    while set.contains(&g) {
        g += 1;
    }
    memo.insert(bit, g);
    g
}

fn run() {
    input! {
        n: usize,
        a: [u32; n],
    }
    let mut map = std::collections::BTreeMap::new();
    for a in a {
        let f = factorize(a);
        for (p, c) in f {
            *map.entry(p).or_insert(0) |= 1 << c;
        }
    }
    let mut memo = std::collections::BTreeMap::new();
    let mut ans = 0;
    for (_, bit) in map {
        ans ^= calc(bit, &mut memo);
    }
    if ans == 0 {
        println!("Arpa");
    } else {
        println!("Mojtaba");
    }
}

fn main() {
    run();
}