// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std;
    use std::io::Read;
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error"),
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
    for _ in 0..t {
        let r: u64 = sc.next();
        let mut a = vec![];
        let mut depth = 0;
        loop {
            let mut s = sc.next_chars();
            for &c in s.iter() {
                if c == '(' {
                    depth += 1;
                } else if c == ')' {
                    depth -= 1;
                }
            }
            a.append(&mut s);
            if depth == 0 {
                break;
            }
        }
        let mut a = parse(&a, &mut 0);
        calc(&mut a);
        let cnt = eval(&a);
        let mut val = vec![];
        fill(&a, &mut val, cnt * r);
        write!(out, "REVOLTING").ok();
        for v in val {
            write!(out, " {}", v).ok();
        }
        writeln!(out, "").ok();
    }
}

enum Circuit {
    Parallel(Vec<Circuit>, u64),
    Series(Vec<Circuit>, u64),
    Resistor,
}

fn parse(s: &[char], k: &mut usize) -> Circuit {
    let c = s[*k];
    *k += 1;
    if c == '*' {
        return Circuit::Resistor;
    }
    assert!(c == '(');
    let mut a = vec![];
    a.push(parse(s, k));
    let op = s[*k];
    while s[*k] != ')' {
        assert!(op == s[*k]);
        *k += 1;
        a.push(parse(s, k));
    }
    *k += 1;
    if op == 'P' {
        Circuit::Parallel(a, 0)
    } else {
        Circuit::Series(a, 0)
    }
}

fn calc(a: &mut Circuit) -> u64 {
    match a {
        Circuit::Resistor => 1,
        Circuit::Series(ref mut a, v) => {
            let mut ans = std::u64::MAX;
            for a in a.iter_mut() {
                ans = std::cmp::min(ans, calc(a));
            }
            *v = ans;
            ans
        },
        Circuit::Parallel(ref mut a, v) => {
            let mut sum = 0;
            for a in a.iter_mut() {
                sum += calc(a);
            }
            *v = sum;
            sum
        },
    }
}

fn eval(a: &Circuit) -> u64 {
    match a {
        Circuit::Resistor => 1,
        Circuit::Series(_, v) => *v,
        Circuit::Parallel(_, v) => *v,
    }
}

fn fill(a: &Circuit, val: &mut Vec<u64>, x: u64) {
    match a {
        Circuit::Resistor => {
            val.push(x);
        },
        Circuit::Series(ref a, v) => {
            let mut used = false;
            for a in a.iter() {
                if !used && eval(a) == *v {
                    used = true;
                    fill(a, val, x);
                } else {
                    fill(a, val, 0);
                }
            }
        },
        Circuit::Parallel(ref a, _) => {
            for a in a.iter() {
                fill(a, val, x);
            }
        },
    }
}