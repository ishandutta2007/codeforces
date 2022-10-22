//---------- begin scanner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
//---------- end scanner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let h: usize = sc.next();
        let g: usize = sc.next();
        let mut a: Vec<u64> = vec![0];
        for _ in 1..(1 << h) {
            a.push(sc.next());
        }
        for _ in 0..(1 << h) {
            a.push(0);
        }
        let mut op = vec![];
        for i in 1..(1 << h) {
            while a[i] > 0 && eval(&a, i) >= (1 << g) {
                pop(&mut a, i);
                op.push(i);
            }
        }
        let ans = a.iter().fold(0, |s, a| s + *a);
        let mut s = String::new();
        s.push_str(&format!("{}\n", ans));
        for op in op {
            s.push_str(&format!("{} ", op));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}

fn eval(a: &[u64], mut k: usize) -> usize {
    assert!(a[k] > 0);
    loop {
        let l = a[2 * k];
        let r = a[2 * k + 1];
        if std::cmp::max(l, r) == 0 {
            return k;
        }
        if l > r {
            k = 2 * k;
        } else {
            k = 2 * k + 1;
        }
    }
}

fn pop(a: &mut [u64], mut k: usize) {
    assert!(a[k] > 0);
    loop {
        let l = a[2 * k];
        let r = a[2 * k + 1];
        if std::cmp::max(l, r) == 0 {
            a[k] = 0;
            return;
        }
        if l > r {
            a[k] = l;
            k = 2 * k;
        } else {
            a[k] = r;
            k = 2 * k + 1;
        }
    }
}