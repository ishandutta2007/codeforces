// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
// ---------- begin Scanner(require delimiter) ----------
mod scanner {
    pub struct Scanner<R> {
        reader: R,
        buf: Vec<u8>,
    }
    #[allow(dead_code)]
    impl<R: std::io::BufRead> Scanner<R> {
        pub fn new(reader: R) -> Self {
            Scanner {
                reader: reader,
                buf: Vec::with_capacity(1024),
            }
        }
        fn read(&mut self, del: u8) {
            self.buf.clear();
            self.reader.read_until(del, &mut self.buf).ok();
            assert!(self.buf.pop().unwrap() == del);
        }
        pub fn next<T: std::str::FromStr>(&mut self, del: u8) -> T {
            self.read(del);
            std::str::from_utf8(&self.buf)
                .unwrap()
                .trim()
                .parse::<T>()
                .ok()
                .unwrap()
        }
        pub fn next_bytes(&mut self, del: u8) -> Vec<u8> {
            self.read(del);
            std::str::from_utf8(&self.buf)
                .unwrap()
                .trim()
                .bytes()
                .collect()
        }
    }
}
// ---------- end scanner(require delimiter) ----------

fn main() {
    let stdin = std::io::stdin();
    let mut sc = scanner::Scanner::new(stdin.lock());
    run(&mut sc);
}

fn run<R: std::io::BufRead>(sc: &mut scanner::Scanner<R>) {
    let n: usize = sc.next(b' ');
    let a: i64 = sc.next(b'\n');
    let mut p = vec![(0i64, 0i64); n];
    for p in p.iter_mut() {
        p.0 = sc.next(b' ');
        p.1 = sc.next(b'\n');
    }
    let mut ans = 0;
    let mut dfs = vec![p.as_mut_slice()];
    let mut left = vec![];
    let mut right = vec![];
    while let Some(p) = dfs.pop() {
        if p.len() == 1 {
            ans.chmax(a - p[0].1);
            continue;
        }
        let m = p.len() / 2;
        let (l, r) = p.split_at_mut(m);
        l.reverse();
        let ini = (r[0].0 - l[0].0).pow(2);
        for (l, left) in [(&l, &mut left), (&r, &mut right)].iter_mut() {
            left.clear();
            let mut sum = a - l[0].1;
            let mut max = sum;
            let mut pena = ini;
            let mut prev = l[0].0;
            left.push((sum, max, pena));
            for &(d, c) in l.iter().skip(1) {
                sum += a - c;
                max.chmax(sum);
                pena.chmax((d - prev).pow(2));
                prev = d;
                left.push((sum, max, pena));
            }
        }
        while left.len() > 0 && right.len() > 0 {
            if left.last().unwrap().2 >= right.last().unwrap().2 {
                let (s, _, p) = left.pop().unwrap();
                ans.chmax(s + right.last().unwrap().1 - p);
            } else {
                let (s, _, p) = right.pop().unwrap();
                ans.chmax(s + left.last().unwrap().1 - p);
            }
        }
        l.reverse();
        dfs.push(l);
        dfs.push(r);
    }
    println!("{}", ans);
}