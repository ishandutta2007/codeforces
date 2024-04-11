// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    #[derive(Clone)]
    enum Operation {
        AND(usize, usize, usize),
        OR(usize, usize, usize),
        XOR(usize, usize, usize),
        Assign(usize, Vec<u8>),
    }
    let mut index = std::collections::BTreeMap::new();
    index.insert(vec![b'?'], 0);
    let mut line = vec![];
    for _ in 0..n {
        let a = sc.next_bytes();
        let id = index.len();
        index.insert(a, id);
        sc.next::<String>();
        let v = sc.next_bytes();
        if v[0] == b'0' || v[0] == b'1' {
            line.push(Operation::Assign(id, v));
        } else {
            let v = *index.get(&v).unwrap();
            let op = sc.next::<String>();
            let u = sc.next_bytes();
            let u = *index.get(&u).unwrap();
            line.push(match op.as_str() {
                "AND" => Operation::AND,
                "OR" => Operation::OR,
                "XOR" => Operation::XOR,
                _ => unreachable!(),
            }(id, v, u));
        }
    }
    let mut min = String::new();
    let mut max = String::new();
    for j in 0..m {
        let mut cnt = [0; 2];
        for (i, cnt) in cnt.iter_mut().enumerate() {
            let mut state = vec![0; n + 1];
            state[0] = i;
            for line in line.iter() {
                match *line {
                    Operation::Assign(x, ref v) => {
                        state[x] = (v[j] - b'0') as usize;
                    },
                    Operation::AND(x, a, b) => {
                        state[x] = state[a] & state[b];
                    },
                    Operation::OR(x, a, b) => {
                        state[x] = state[a] | state[b];
                    },
                    Operation::XOR(x, a, b) => {
                        state[x] = state[a] ^ state[b];
                    },
                }
            }
            for v in state[1..].iter() {
                *cnt += *v;
            }
        }
        if cnt[0] == cnt[1] {
            min.push('0');
            max.push('0');
        } else if cnt[0] >= cnt[1] {
            min.push('1');
            max.push('0');
        } else {
            min.push('0');
            max.push('1');
        }
    }
    println!("{}", min);
    println!("{}", max);
}