use std::io;
use std::str::FromStr;
use std::fmt::Debug;

struct Reader { row: String }
#[allow(dead_code)] impl Reader {
    fn new() -> Reader { Reader { row: "".to_string() } }
    fn get_next_line(&mut self) -> &str {
        self.row.clear();
        io::stdin().read_line(&mut self.row).ok().expect("");
        return &self.row;
    }
    fn var<T: FromStr>(&mut self) -> T where T::Err: Debug {
        return self.get_next_line().trim().parse().unwrap();
    }
    fn arr<T: FromStr>(&mut self) -> Vec<T> where T::Err: Debug {
        return self.get_next_line().split_whitespace().map(|s| s.parse().expect("")).collect();
    }
    fn bytes(&mut self) -> &[u8] { return self.get_next_line().as_bytes(); }
    fn i(&mut self) -> i32 { return self.var(); }
    fn arr_i(&mut self) -> Vec<i32> { return self.arr(); }
    fn i2(&mut self) -> (i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1]); }
    fn i3(&mut self) -> (i32, i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1], arr[2]); }
}

fn solve(reader: &mut Reader) {
    let (n, k) = reader.i2();
    let mut a = reader.arr_i();
    let mut b = reader.arr_i();
    a.sort_by_key(|x| -x);
    b.sort_by_key(|x| -x);

    let mut sum = 0;
    let mut cur_a: usize = 0;
    let mut cur_b: usize = 0;
    for _ in 0..n {
        if cur_b >= k as usize || (cur_a < n as usize && a.get(cur_a) > b.get(cur_b)) {
            sum += a.get(cur_a).expect("");
            cur_a += 1;
        } else {
            sum += b.get(cur_b).expect("");
            cur_b += 1;
        }
    }
    println!("{}", sum);
}

fn main() {
    let mut reader = Reader::new();
    let t = reader.i();
    for _ in 0..t { solve(&mut reader) }
}