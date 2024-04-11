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

fn z_algorithm<T: Eq>(s: &[T]) -> Vec<usize> {
    let n = s.len();
    let mut a = vec![0; n];
    a[0] = n;
    let mut i = 1;
    let mut j = 0;
    while i < n {
        while i + j < n && s[j] == s[i + j] {
            j += 1;
        }
        a[i] = j;
        if j == 0 {
            i += 1;
            continue;
        }
        let mut k = 1;
        while i + k < n && k + a[k] < j {
            a[i + k] = a[k];
            k += 1;
        }
        i += k;
        j -= k;
    }
    a
}

fn longest_prefix(s: &[char], t: &[char]) -> usize {
    let mut a = vec![];
    a.extend_from_slice(t);
    a.push('$');
    let start = a.len();
    let x = s.len();
    let y = t.len();
    if x >= y {
        a.extend_from_slice(&s[(x - y)..]);
    } else {
        a.extend_from_slice(s);
    }
    let prefix = z_algorithm(&a);
    for (i, &v) in prefix[start..].iter().enumerate() {
        if a.len() - start - i == v {
            return v;
        }
    }
    0
}

fn run() {
    input! {
        n: usize,
        s: [chars; n],
    }
    let mut ans = s[0].clone();
    for s in s[1..].iter() {
        let len = longest_prefix(&ans, s);
        for &c in s[len..].iter() {
            ans.push(c);
        }
    }
    let out: String = ans.into_iter().collect();
    println!("{}", out);
}

fn main() {
    run();
}