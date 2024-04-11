use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::min;

struct Reader { row: String }
#[allow(dead_code)] impl Reader {
    fn new() -> Reader { Reader { row: "".to_string() } }
    fn get_next_line(&mut self) -> &str {
        self.row.clear();
        io::stdin().read_line(&mut self.row).ok().unwrap();
        return &self.row;
    }
    fn var<T: FromStr>(&mut self) -> T where T::Err: Debug {
        return self.get_next_line().trim().parse().unwrap();
    }
    fn arr<T: FromStr>(&mut self) -> Vec<T> where T::Err: Debug {
        return self.get_next_line().split_whitespace().map(|s| s.parse().unwrap()).collect();
    }
    fn bytes(&mut self) -> &[u8] { return self.get_next_line().trim().as_bytes(); }
    fn i(&mut self) -> i32 { return self.var(); }
    fn u(&mut self) -> usize { return self.var(); }
    fn arr_i(&mut self) -> Vec<i32> { return self.arr(); }
    fn arr_u(&mut self) -> Vec<usize> { return self.arr(); }
    fn arr_l(&mut self) -> Vec<i64> { return self.arr(); }
    fn u2(&mut self) -> (usize, usize) { let a = self.arr_u(); (a[0], a[1]) }
}

fn solve(reader: &mut Reader) {
    let a = reader.bytes();
    let n = a.len();
    let mut v = vec![0u8; 0];
    let mut mn = vec![0u8; 0];
    let mut ans = vec![0u8; 0];
    mn.push(a[n - 1]);
    for i in 0..n - 1 { mn.push(min(mn[i], a[n - i - 2])); }
    mn.reverse();

    let mut pos = 0usize;
    while pos < n || !v.is_empty() {
        if !v.is_empty() && (pos == n || *v.last().unwrap() <= mn[pos]) {
            ans.push(v.pop().unwrap());
        } else {
            v.push(a[pos]);
            pos += 1;
        }
    }
    for c in ans { print!("{}", c as char); }
    println!();
}

fn main() {
    let mut reader = Reader::new();
    solve(&mut reader);
    // let t = reader.u();
    // for _ in 0..t { solve(&mut reader) }
}