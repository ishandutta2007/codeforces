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

use std::io::Write;

fn main() {
    let stdin = std::io::stdin();
    let mut sc = scanner::Scanner::new(stdin.lock());
    run(&mut sc);
}

fn run<R: std::io::BufRead>(sc: &mut scanner::Scanner<R>) {
    let n: usize = sc.next(b' ');
    let m: usize = sc.next(b'\n');
    let mut a = vec![(0usize, 1usize); m];
    for (i, a) in a.iter_mut().enumerate() {
        let mut del = b' ';
        if i == m - 1 {
            del = b'\n';
        }
        a.0 = sc.next(del);
    }
    a.sort_by_key(|p| p.0);
    a.dedup_by(|a, b| {
        a.0 == b.0 && {
            b.1 += a.1;
            true
        }
    });
    let mut elem = vec![false; 1 << n];
    for &(a, _) in a.iter() {
        elem[a] = true;
    }
    let mut ans = 0;
    let mut used = vec![false; 1 << n];
    for &(a, c) in a.iter() {
        if !elem[a] {
            continue;
        }
        elem[a] = false;
        let mut dfs = vec![a];
        let mut cnt = 0;
        while let Some(v) = dfs.pop() {
            cnt += 1;
            let mut p = vec![!v & ((1 << n) - 1)];
            while let Some(v) = p.pop() {
                if used[v] {
                    continue;
                }
                used[v] = true;
                if elem[v] {
                    dfs.push(v);
                    elem[v] = false;
                }
                for i in 0..n {
                    if v >> i & 1 == 1 {
                        p.push(v ^ (1 << i));
                    }
                }
            }
        }
        if cnt > 1 {
            ans += 1;
        } else {
            ans += c;
        }
    }
    println!("{}", ans);
}