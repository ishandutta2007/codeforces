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

struct BIT {
    a: Vec<(usize, u32)>,
}

impl BIT {
    const SIZE: usize = 10000;
    fn new() -> Self {
        BIT {
            a: vec![(0, 0); BIT::SIZE + 1],
        }
    }
    fn add(&mut self, x: u32) {
        let v = x;
        let mut x = x as usize;
        while let Some(p) = self.a.get_mut(x) {
            p.0 += 1;
            p.1 += v;
            x += x & (!x + 1);
        }
    }
    fn sub(&mut self, x: u32) {
        let v = x;
        let mut x = x as usize;
        while let Some(p) = self.a.get_mut(x) {
            p.0 -= 1;
            p.1 -= v;
            x += x & (!x + 1);
        }
    }
    fn find(&self, k: usize) -> u32 {
        let a = &self.a;
        let mut i = 1;
        while 2 * i < a.len() {
            i <<= 1;
        }
        let mut ans = 0;
        let mut x = 0;
        let mut m = 0;
        while i > 0 {
            if x + i < a.len() && m + a[x + i].0 < k {
                x += i;
                m += a[x].0;
                ans += a[x].1;
            }
            i >>= 1;
        }
        ans + ((x + 1) * (k - m)) as u32
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        book: [(u32, usize, usize); n],
    }
    let mut a = vec![vec![vec![]; 2]; 2];
    for (i, &(t, x, y)) in book.iter().enumerate() {
        a[x][y].push((t, i));
    }
    for a in a.iter_mut().flatten() {
        a.sort();
    }
    let len = std::cmp::min(a[1][0].len(), a[0][1].len());
    while a[0][1].len() > len {
        let v = a[0][1].pop().unwrap();
        a[0][0].push(v);
    }
    while a[1][0].len() > len {
        let v = a[1][0].pop().unwrap();
        a[0][0].push(v);
    }
    let mut x = a[1][1].clone();
    let mut y = vec![];
    for (&(a, b), &(c, d)) in a[0][1].iter().zip(a[1][0].iter()) {
        y.push((a + c, b, d));
    }
    if x.len() + y.len() < k {
        println!("-1");
        return;
    }
    let mut bit = BIT::new();
    for x in x.iter().chain(a[0][0].iter()) {
        bit.add(x.0);
    }
    x.insert(0, (0, n));
    y.insert(0, (0, n, n));
    for i in 1..x.len() {
        x[i].0 += x[i - 1].0;
    }
    for i in 1..y.len() {
        y[i].0 += y[i - 1].0;
    }
    let mut ans = (std::u32::MAX, std::usize::MAX);
    let mut j = y.len() - 1;
    for (i, &(v, _)) in x.iter().enumerate() {
        while j > 0 && i + j > k {
            let (_, a, b) = y[j];
            bit.add(book[a].0);
            bit.add(book[b].0);
            j -= 1;
        }
        if i + j == k && i + 2 * j <= m {
            let val = v + y[j].0 + bit.find(m - i - 2 * j);
            ans = std::cmp::min(ans, (val, i));
        }
        if i + 1 < x.len() {
            let (_, a) = x[i + 1];
            bit.sub(book[a].0);
        }
    }
    if ans.0 == std::u32::MAX {
        println!("-1");
        return;
    }
    let (sum, i) = ans;
    let mut ans = vec![];
    for a in a[1][1]
        .iter()
        .take(i)
        .chain(a[0][1].iter().take(k - i))
        .chain(a[1][0].iter().take(k - i))
    {
        ans.push(a.1);
    }
    let mut b: Vec<(u32, usize)> = a[0][0]
        .iter()
        .chain(a[1][1].iter().skip(i))
        .chain(a[0][1].iter().skip(k - i))
        .chain(a[1][0].iter().skip(k - i))
        .cloned()
        .collect();
    b.sort();
    for b in b.iter().take(m - ans.len()) {
        ans.push(b.1);
    }
    assert!(ans.len() == m);
    assert!(ans.iter().map(|a| book[*a].0).sum::<u32>() == sum);
    let mut out = String::new();
    out.push_str(&format!("{}\n", sum));
    for a in ans {
        out.push_str(&format!("{} ", a + 1));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}