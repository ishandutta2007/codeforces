use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;

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
    fn i2(&mut self) -> (i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1]); }
    fn i3(&mut self) -> (i32, i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1], arr[2]); }
}

fn solve(reader: &mut Reader) {
    let mut a = reader.bytes().to_vec();
    a.iter_mut().for_each(|x| *x -= '0' as u8);
    //println!("{:?}", a);

    let mut ans = 0;
    for c1 in 0..(10 as u8) {
        for c2 in 0..(10 as u8) {
            let mut cur = 0;
            for val in &a {
                if cur % 2 == 0 && *val == c1 {
                    cur += 1;
                } else {
                    if cur % 2 == 1 && *val == c2 { cur += 1; }
                }
            }
            if c1 != c2 && cur % 2 == 1 { cur -= 1; }
            ans = max(ans, cur);
        }
    }
    println!("{}", a.len() as i32 - ans);
}

fn main() {
    let mut reader = Reader::new();
    let t = reader.i();
    for _ in 0..t { solve(&mut reader) }
}