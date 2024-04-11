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

// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
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

fn run<R: std::io::BufRead>(sc: &mut scanner::Scanner<R>) {
    let h: usize = sc.next(b' ');
    let w: usize = sc.next(b' ');
    let v: i64 = sc.next(b'\n');
    let mut a = vec![vec![0i64; w]; h];
    for a in a.iter_mut() {
        for (i, a) in a.iter_mut().enumerate() {
            *a = sc.next(" \n".bytes().nth((i == w - 1) as usize).unwrap());
        }
    }
    let inf = std::i64::MAX / 3;
    let bfs = |src: (usize, usize), dst: (usize, usize)| -> (i64, i64) {
        let mut dp = vec![vec![inf; w]; h];
        dp[src.0][src.1] = 0;
        let mut portal = inf;
        let mut q = std::collections::VecDeque::new();
        q.push_back((src.0, src.1));
        while let Some((x, y)) = q.pop_front() {
            let d = dp[x][y];
            if a[x][y] > 0 {
                portal.chmin(d + a[x][y]);
            }
            let d = d + v;
            for &(x, y) in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)].iter() {
                if x < h && y < w && a[x][y] >= 0 && dp[x][y].chmin(d) {
                    q.push_back((x, y));
                }
            }
        }
        (dp[dst.0][dst.1], portal)
    };
    let (a, b) = bfs((0, 0), (h - 1, w - 1));
    let (_, d) = bfs((h - 1, w - 1), (0, 0));
    let ans = a.min(b + d);
    if ans >= inf {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}