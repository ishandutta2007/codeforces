use std::cmp::*;

struct IntervalHeap<T> {
    array: Vec<T>,
}

#[allow(dead_code)]
impl<T: Ord> IntervalHeap<T> {
    fn new() -> Self {
        IntervalHeap {
            array: vec![],
        }
    }
    fn len(&self) -> usize {
        self.array.len()
    }
    fn push(&mut self, val: T) {
        let a = &mut self.array;
        let mut k = a.len();
        a.push(val);
        if k & 1 == 1 && a[k].cmp(&a[k - 1]) == std::cmp::Ordering::Less {
            a.swap(k, k - 1);
            k -= 1;
        }
        IntervalHeap::up_heap(a, k);
    }
    fn valid(&self) {
        let a = &self.array;
        for i in 0..a.len() {
            if i & 1 == 0 {
                assert!(i + 1 >= a.len() || a[i].cmp(&a[i + 1]) == std::cmp::Ordering::Less);
                for &c in [2 * i + 2, 2 * i + 4].iter() {
                    assert!(c >= a.len() || a[i].cmp(&a[c]) == std::cmp::Ordering::Less);
                }
            } else {
                assert!(a[i - 1].cmp(&a[i]) == std::cmp::Ordering::Less);
                for &c in [2 * i + 1, 2 * i + 3].iter() {
                    assert!(c >= a.len() || a[c].cmp(&a[i]) == std::cmp::Ordering::Less);
                }
            }
        }
    }
    fn get_min(&self) -> Option<&T> {
        self.array.get(0)
    }
    fn get_max(&self) -> Option<&T> {
        if self.array.len() > 1 {
            self.array.get(1)
        } else {
            self.array.get(0)
        }
    }
    fn get_min_mut(&mut self) -> Option<&mut T> {
        self.array.get_mut(0)
    }
    fn get_max_mut(&mut self) -> Option<&mut T> {
        if self.array.len() > 1 {
            self.array.get_mut(1)
        } else {
            self.array.get_mut(0)
        }
    }
    fn pop_min(&mut self) -> Option<T> {
        self.array.pop().map(|mut v| {
            let a = &mut self.array;
            if !a.is_empty() {
                std::mem::swap(&mut a[0], &mut v);
                let mut k = 0;
                while 2 * k + 2 < a.len() {
                    let mut c = 2 * k + 2;
                    if c + 2 < a.len() && a[c + 2].cmp(&a[c]) == std::cmp::Ordering::Less {
                        c += 2;
                    }
                    if a[c].cmp(&a[k]) != std::cmp::Ordering::Less {
                        break;
                    }
                    a.swap(k, c);
                    k = c;
                }
                if k + 1 < a.len() && a[k + 1].cmp(&a[k]) == std::cmp::Ordering::Less {
                    a.swap(k, k + 1);
                    IntervalHeap::up_heap(a, k + 1);
                }
            }
            v
        })
    }
    fn pop_max(&mut self) -> Option<T> {
        self.array.pop().map(|mut v| {
            let a = &mut self.array;
            if a.len() >= 2 {
                std::mem::swap(&mut a[1], &mut v);
                let mut k = 1;
                while 2 * k + 1 < a.len() {
                    let mut c = 2 * k + 1;
                    if c + 2 < a.len() && a[c + 2].cmp(&a[c]) == std::cmp::Ordering::Greater {
                        c += 2;
                    }
                    if a[c].cmp(&a[k]) != std::cmp::Ordering::Greater {
                        break;
                    }
                    a.swap(k, c);
                    k = c;
                }
                if a[k - 1].cmp(&a[k]) == std::cmp::Ordering::Greater {
                    a.swap(k, k - 1);
                    IntervalHeap::up_heap(a, k - 1);
                }
            }
            v
        })
    }
    fn up_heap(a: &mut [T], mut k: usize) {
        while k >= 2 {
            let p = ((k >> 1) - 1) & !1;
            if a[p].cmp(&a[k]) != std::cmp::Ordering::Greater {
                break;
            }
            a.swap(p, k);
            k = p;
        }
        while k >= 2 {
            let p = ((k >> 1) - 1) | 1;
            if a[p].cmp(&a[k]) != std::cmp::Ordering::Less {
                break;
            }
            a.swap(p, k);
            k = p;
        }
    }
}

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
    let q: usize = sc.next();
    for _ in 0..q {
        let n: usize = sc.next();
        let m: i64 = sc.next();
        let capa: i64 = sc.next();
        let ini: i64 = sc.next();
        let mut a: Vec<(i64, i64, i64)> = (0..n).map(|_| {
            let t = sc.next();
            let a = sc.next();
            let b = sc.next();
            (t, a, b)
        }).collect();
        a.push((m, 1, 1));
        a.sort();
        let mut prev = 0;
        let mut tank = Tank::new(capa);
        tank.supply(ini, 0);
        let mut ans = 0;
        for (t, a, b) in a {
            if let Some(v) = tank.consume(t - prev) {
                ans += v;
                tank.supply(a, b);
                prev = t;
            } else {
                ans = -1;
                break;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

struct Tank {
    capa: i64,
    now: i64,
    heap: IntervalHeap<(i64, i64)>,
}

impl Tank {
    fn new(capa: i64) -> Tank {
        Tank {
            capa: capa,
            now: 0,
            heap: IntervalHeap::new(),
        }
    }
    fn supply(&mut self, volume: i64, cost: i64) {
        self.now += volume;
        self.heap.push((cost, volume));
        while self.now > self.capa {
            let p = self.heap.get_max_mut().unwrap();
            let u = std::cmp::min(self.now - self.capa, p.1);
            self.now -= u;
            if u == p.1 {
                drop(p);
                self.heap.pop_max();
            } else {
                p.1 -= u;
            }
        }
    }
    fn consume(&mut self, volume: i64) -> Option<i64> {
        if self.now < volume {
            return None;
        }
        let hope = self.now - volume;
        let mut ans = 0;
        while self.now > hope {
            let p = self.heap.get_min_mut().unwrap();
            let u = std::cmp::min(self.now - hope, p.1);
            ans += p.0 * u;
            self.now -= u;
            if u == p.1 {
                drop(p);
                self.heap.pop_min();
            } else {
                p.1 -= u;
            }
        }
        Some(ans)
    }
}