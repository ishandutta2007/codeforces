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
        m: u64,
        xaniar: (usize, usize, u64, u64),
        abol: (usize, usize, u64, u64),
    }
    let cond = |b: bool| {
        if !b {
            println!("-1");
            std::process::exit(0);
        }
    };
    let next = |h: usize| -> usize {
        let x = xaniar.2;
        let y = xaniar.3;
        ((h as u64 * x + y) % m) as usize
    };
    let mut time = vec![None; m as usize];
    let mut p = xaniar.0;
    time[p] = Some(0);
    let mut k = 1;
    p = next(p);
    while time[p].is_none() {
        time[p] = Some(k);
        k += 1;
        p = next(p);
    }
    let step = k - time[p].unwrap();
    let a = xaniar.1;
    cond(time[a].is_some());
    if time[a].unwrap() < time[p].unwrap() {
        let next = |h: usize| -> usize {
            let x = abol.2;
            let y = abol.3;
            ((h as u64 * x + y) % m) as usize
        };
        let t = time[a].unwrap();
        let mut p = abol.0;
        for _ in 0..t {
            p = next(p);
        }
        cond(p == abol.1);
        println!("{}", t);
        return;
    }
    let t = time[a].unwrap();
    let mut abol = abol;
    for _ in 0..t {
        abol.0 = {
            let x = abol.2;
            let y = abol.3;
            ((abol.0 as u64 * x + y) % m) as usize
        };
    }
    let mut mat = (1, 0);
    for _ in 0..step {
        mat = (mat.0 * abol.2 % m, (mat.1 * abol.2 + abol.3) % m);
    }
    abol.2 = mat.0;
    abol.3 = mat.1;
    let mut time = vec![None; m as usize];
    let next = |h: usize| -> usize {
        let x = abol.2;
        let y = abol.3;
        ((h as u64 * x + y) % m) as usize
    };
    let mut p = abol.0;
    time[abol.0] = Some(0);
    p = next(p);
    let mut k = 1;
    while time[p].is_none() {
        time[p] = Some(k);
        p = next(p);
        k += 1;
    }
    cond(time[abol.1].is_some());
    let ans = time[abol.1].unwrap() as u64 * step as u64 + t as u64;
    println!("{}", ans);
}

fn main() {
    run();
}