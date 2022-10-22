// ---------- begin scannner ----------
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
// ---------- end scannner ----------

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
    let mut stack = vec![1u64];
    let mut sum = 0u64;
    for _ in 0..t {
        let s: String = sc.next();
        match s.as_str() {
            "add" => {
                sum = sum.saturating_add(*stack.last().unwrap());
            },
            "for" => {
                let v: u64 = sc.next();
                let x = v.saturating_mul(*stack.last().unwrap());
                stack.push(x);
            },
            "end" => {
                stack.pop();
            },
            _ => unreachable!(),
        }
    }
    if sum >= 1u64 << 32 {
        println!("OVERFLOW!!!");
    } else {
        println!("{}", sum);
    }
}