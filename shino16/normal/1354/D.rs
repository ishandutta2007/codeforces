use std::iter::FromIterator;

#[derive(Default, Debug, Clone)]
pub struct FenwickTree {
    data: Vec<Item>,
}

impl FromIterator<Item> for FenwickTree {
    fn from_iter<I: IntoIterator<Item = Item>>(iter: I) -> Self {
        iter.into_iter().collect::<Vec<Item>>().into()
    }
}

impl From<Vec<Item>> for FenwickTree {
    fn from(data: Vec<Item>) -> FenwickTree {
        let mut res: FenwickTree = FenwickTree { data };
        res.build();
        res
    }
}

#[allow(dead_code)]
impl FenwickTree {
    fn build(&mut self) {
        for i in 0..self.len() {
            let j = i | (i + 1);
            if j < self.len() {
                self.data[j] = op(self.data[j], self.data[i]);
            }
        }
    }

    fn len(&self) -> usize {
        self.data.len()
    }

    fn take_fold(&self, index: usize) -> Item {
        let mut res = id();
        let mut x = index as isize - 1;
        while x >= 0 {
            res = op(res, self.data[x as usize]);
            x &= x + 1;
            x -= 1;
        }
        res
    }

    fn fold_over(&self, l: usize, r: usize) -> Item {
        op(inv(self.take_fold(l)), self.take_fold(r))
    }

    fn fold_search<F: Fn(Item) -> bool>(&self, pred: F) -> usize {
        let mut x = id();
        let mut i = -1_isize; // inclusive
        let mut k =
            1_isize << (std::mem::size_of::<usize>() * 8
                        - self.len().leading_zeros() as usize);
        while k != 0 {
            if i + k < self.len() as isize {
                let x1 = op(x, self.data[(i+k) as usize]);
                if !pred(x1) {
                    x = x1;
                    i += k;
                }
            }
            k /= 2;
        }
        (i + 2) as usize
    }

    fn lower_bound(&self, v: Item) -> usize {
        self.fold_search(|s| s >= v)
    }

    fn add(&mut self, index: usize, a: Item) {
        let mut x = index;
        while x < self.len() {
            self.data[x] = op(a, self.data[x]);
            x |= x + 1;
        }
    }
}

type Item = i32;
fn id() -> Item { 0 }
fn op(x: Item, y: Item) -> Item { x + y }
fn inv(x: Item) -> Item { -x }

use std::io::Read;
use std::str::FromStr;

pub struct Scanner<R> {
    reader: R,
    buf: Vec<u8>,
}

impl<R: Read> Scanner<R> {
    pub fn new(reader: R) -> Self {
        Scanner {
            reader: reader,
            buf: Vec::with_capacity(1024),
        }
    }
    pub fn next<T: FromStr>(&mut self) -> T {
        let it = self.reader
            .by_ref()
            .bytes()
            .map(|c| c.unwrap())
            .skip_while(|&c| c == b' ' || c == b'\n' || c == b'\r')
            .take_while(|&c| c != b' ' && c != b'\n' && c != b'\r');
        self.buf.clear();
        for c in it {
            self.buf.push(c);
        }
        std::str::from_utf8(&self.buf)
            .unwrap()
            .parse::<T>()
            .ok()
            .unwrap()
    }
}

fn main() {
    let stdin = std::io::stdin();
    let mut scan = Scanner::new(stdin.lock());
    let n: usize = scan.next();
    let q: usize = scan.next();
    let mut rsq: FenwickTree = vec![0; n+1].into();
    for _ in 0..n {
        rsq.add(scan.next(), 1);
    }
    for _ in 0..q {
        let k: i32 = scan.next();
        if k > 0 {
            rsq.add(k as usize, 1);
        } else {
            let i = rsq.lower_bound(-k);
            rsq.add(i-1, -1);
        }
    }
    let i = rsq.lower_bound(1) - 1;
    println!("{}", if i == rsq.len() { 0 } else { i });
}