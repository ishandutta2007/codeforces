use std::io;
use std::str::FromStr;
use std::fmt::Debug;

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
    let n = reader.u();
    let a = reader.arr_i();

    let mut nums = vec![0; 0];
    let mut num = 1;
    let mut lst = a[0];
    for i in 1..n {
        if a[i] == lst {
            num += 1;
        } else {
            nums.push(num);
            lst = a[i];
            num = 1;
        }
    }
    nums.push(num);

    if nums.len() < 3 { println!("0 0 0"); return; }

    let mut cur = 1;
    let mut sum_b = 0;
    while cur < nums.len() && sum_b <= nums[0] {
        sum_b += nums[cur];
        cur += 1;
    }
    let max_c = (n / 2) as i32 - nums[0] - sum_b;

    if sum_b <= nums[0]  { println!("0 0 0"); return; }
    let mut sum_c = 0;
    while cur < nums.len() && sum_c + nums[cur] <= max_c {
        sum_c += nums[cur];
        cur += 1;
    }
    if sum_c > nums[0] { println!("{} {} {}", nums[0], sum_b, sum_c) }
    else { println!("0 0 0"); }
}

fn main() {
    let mut reader = Reader::new();
    // solve(&mut reader);
    let t = reader.u();
    for _ in 0..t { solve(&mut reader) }
}