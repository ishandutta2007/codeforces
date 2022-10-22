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
        n: usize,
        a: [u32; n],
    }
    let xor = a.iter().fold(0, |s, a| s ^ *a);
    if n % 2 == 0 && xor != 0 {
        println!("NO");
        return;
    }
    let mut ans = vec![];
    if n % 2 == 1 {
        let mut x = 0;
        while x + 2 < n {
            ans.push((x, x + 1, x + 2));
            x += 2;
        }
        x -= 2;
        while x > 0 {
            x -= 2;
            ans.push((x, x + 1, x + 2));
        }
    } else {
        let mut x = 0;
        while x + 3 < n {
            ans.push((x, x + 1, x + 2));
            x += 2;
        }
        x -= 2;
        while x > 0 {
            x -= 2;
            ans.push((x, x + 1, x + 2));
        }
    }
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "YES\n{}", ans.len()).ok();
    let mut x = a;
    for (a, b, c) in ans {
        let v = x[a] ^ x[b] ^ x[c];
        x[a] = v;
        x[b] = v;
        x[c] = v;
        writeln!(out, "{} {} {}", a + 1, b + 1, c + 1).ok();
    }
}

fn main() {
    run();
}