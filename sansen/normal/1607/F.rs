// ---------- begin recurse ----------
// reference
// https://twitter.com/noshi91/status/1393952665566994434
// https://twitter.com/shino16_cp/status/1393933468082397190
pub fn recurse<A, R, F>(f: F) -> impl Fn(A) -> R
where
    F: Fn(&dyn Fn(A) -> R, A) -> R,
{
    fn call<A, R, F>(f: &F, a: A) -> R
    where
        F: Fn(&dyn Fn(A) -> R, A) -> R,
    {
        f(&|a| call(f, a), a)
    }
    move |a| call(&f, a)
}
// ---------- end recurse ----------
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
        pub fn read(&mut self, del: u8) {
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

use std::io::Write;

fn main() {
    let stdin = std::io::stdin();
    let mut sc = scanner::Scanner::new(stdin.lock());
    run(&mut sc);
}

fn run<R: std::io::BufRead>(sc: &mut scanner::Scanner<R>) {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let t: u32 = sc.next(b'\n');
    for _ in 0..t {
        sc.read(b'\n');
        let h: usize = sc.next(b' ');
        let w: usize = sc.next(b'\n');
        let pos = |x: usize, y: usize| x * w + y;
        let mut s = vec![0u8; h * w];
        for s in s.chunks_mut(w) {
            s.copy_from_slice(&sc.next_bytes(b'\n'));
        }
        let mut dp = vec![0usize; h * w];
        let mut time = vec![0usize; h * w];
        let mut dfs = vec![];
        for i in 0..h {
            for j in 0..w {
                if dp[pos(i, j)] > 0 {
                    continue;
                }
                dfs.push((i, j));
                let mut cycle = 0;
                for i in 0.. {
                    let (mut x, mut y) = dfs[i];
                    time[pos(x, y)] = i + 1;
                    match s[pos(x, y)] {
                        b'L' => y -= 1,
                        b'R' => y += 1,
                        b'U' => x -= 1,
                        _ => x += 1,
                    }
                    if !(x < h && y < w) {
                        break;
                    }
                    if dp[pos(x, y)] > 0 {
                        break;
                    }
                    if time[pos(x, y)] > 0 {
                        cycle = i + 1 - time[pos(x, y)] + 1;
                        break;
                    }
                    dfs.push((x, y));
                }
                if cycle > 0 {
                    let s = dfs.len() - cycle;
                    for (x, y) in dfs.drain(s..) {
                        dp[pos(x, y)] = cycle;
                        time[pos(x, y)] = 0;
                    }
                }
                for (mut x, mut y) in dfs.drain(..).rev() {
                    time[pos(x, y)] = 0;
                    let save = (x, y);
                    match s[pos(x, y)] {
                        b'L' => y -= 1,
                        b'R' => y += 1,
                        b'U' => x -= 1,
                        _ => x += 1,
                    }
                    dp[pos(save.0, save.1)] = 1 + if x < h && y < w { dp[pos(x, y)] } else { 0 };
                }
            }
        }
        let max = *dp.iter().max().unwrap();
        let pos = dp.iter().position(|p| *p == max).unwrap();
        writeln!(out, "{} {} {}", pos / w + 1, pos % w + 1, max).ok();
    }
}