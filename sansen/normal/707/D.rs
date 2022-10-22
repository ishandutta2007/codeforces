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
    let h: usize = sc.next();
    let w: usize = sc.next();
    let q: usize = sc.next();
    let mut state = State::new(h, w);
    let mut child = vec![vec![]; q + 1];
    for i in 1..=q {
        let op: u8 = sc.next();
        if op == 1 {
            let x = sc.next::<usize>() - 1;
            let y = sc.next::<usize>() - 1;
            child[i - 1].push((i, 1, x, y));
        } else if op == 2 {
            let x = sc.next::<usize>() - 1;
            let y = sc.next::<usize>() - 1;
            child[i - 1].push((i, 2, x, y));
        } else if op == 3 {
            let x = sc.next::<usize>() - 1;
            child[i - 1].push((i, 3, x, w));
        } else {
            let p = sc.next::<usize>();
            child[p].push((i, 4, h, w));
        }
    }
    let mut ans = vec![0; q + 1];
    dfs(0, &child, &mut ans, &mut state);
    for a in ans[1..].iter() {
        writeln!(out, "{}", *a).ok();
    }
}

fn dfs(v: usize, child: &[Vec<(usize, u8, usize, usize)>], ans: &mut [i32], state: &mut State) {
    ans[v] = state.count();
    for &(u, op, x, y) in child[v].iter() {
        if op == 1 {
            state.insert(x, y);
        } else if op == 2 {
            state.remove(x, y);
        } else if op == 3 {
            state.flip(x);
        }
        dfs(u, child, ans, state);
        if op != 4 {
            state.undo();
        }
    }
}

struct State {
    a: Vec<StateRow>,
    cnt: i32,
    stack: Vec<Option<(usize, usize, usize)>>,
}

impl State {
    fn new(h: usize, w: usize) -> State {
        State {
            a: (0..h).map(|_| StateRow::new(w)).collect::<Vec<_>>(),
            cnt: 0,
            stack: vec![],
        }
    }
    fn insert(&mut self, x: usize, y: usize) {
        let diff = self.a[x].insert(y);
        if diff != 0 {
            self.cnt += diff;
            self.stack.push(Some((1, x, y)));
        } else {
            self.stack.push(None);
        }
    }
    fn remove(&mut self, x: usize, y: usize) {
        let diff = self.a[x].remove(y);
        if diff != 0 {
            self.cnt += diff;
            self.stack.push(Some((2, x, y)));
        } else {
            self.stack.push(None);
        }
    }
    fn flip(&mut self, x: usize) {
        self.cnt += self.a[x].flip();
        self.stack.push(Some((3, x, 0)));
    }
    fn undo(&mut self) {
        self.stack.pop().unwrap().map(|(op, x, y)| {
            if op == 1 {
                self.cnt += self.a[x].remove(y);
            } else if op == 2 {
                self.cnt += self.a[x].insert(y);
            } else {
                self.cnt += self.a[x].flip();
            }
        });
    }
    fn count(&self) -> i32 {
        self.cnt
    }
}

struct StateRow {
    a: Vec<bool>,
    flip: bool,
    cnt: i32,
}

impl StateRow {
    fn new(w: usize) -> Self {
        StateRow {
            a: vec![false; w],
            flip: false,
            cnt: 0,
        }
    }
    fn insert(&mut self, x: usize) -> i32 {
        let po = &mut self.a[x];
        if !(*po ^ self.flip) {
            *po ^= true;
            self.cnt += 1;
            1
        } else {
            0
        }
    }
    fn remove(&mut self, x: usize) -> i32 {
        let po = &mut self.a[x];
        if *po ^ self.flip {
            *po ^= true;
            self.cnt -= 1;
            -1
        } else {
            0
        }
    }
    fn flip(&mut self) -> i32 {
        self.flip ^= true;
        let res = self.a.len() as i32 - 2 * self.cnt;
        self.cnt = self.a.len() as i32 - self.cnt;
        res
    }
}