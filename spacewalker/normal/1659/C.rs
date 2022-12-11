use std::{
    collections::*,
    *
};

struct TokenReader {
    input : io::Stdin,
    token_buffer : VecDeque<String>
}

impl TokenReader {
    fn from_stdin(stdin: io::Stdin) -> TokenReader {
        TokenReader {
            input: stdin,
            token_buffer: VecDeque::new()
        }
    }
    fn get_input(&mut self) {
        let mut new_tokens_found = false;
        while !new_tokens_found {
            let mut line = String::new();
            self.input.read_line(&mut line).expect("Failed to read line");
            for token in line.split_whitespace() {
                new_tokens_found = true;
                self.token_buffer.push_back(token.to_string());
            }
        }
    }
    fn get_token(&mut self) -> String {
        if self.token_buffer.len() == 0 { 
            self.get_input();
        }
        return self.token_buffer.pop_front().expect("get_token called when no tokens could be read");
    }
    fn get<T: str::FromStr>(&mut self) -> T
        where T: str::FromStr,
              <T as str::FromStr>::Err: fmt::Debug {
        return T::from_str(&self.get_token())
            .expect(any::type_name::<T>());
    }
}

fn solve(n: usize, a: i64, b: i64, xs: Vec<i64>) -> i64 {
   let suffix_sums : Vec<i64> = xs.iter().rev().scan(0, |state, &x| {
       *state += x;
       Some(*state)
   }).collect::<Vec<i64>>().iter().rev().copied().collect();
   let ans = xs.iter().enumerate().map(|(i, &v)| {
    a * v + b * (suffix_sums[i] - (n - i - 1) as i64 * v)
   }).min().unwrap();
   cmp::min(ans, b * suffix_sums[0])
}

fn main() {
    let mut cin = TokenReader::from_stdin(io::stdin());
    let t : usize = cin.get();
    for _ in 0..t {
        let (n, a, b) = (cin.get(), cin.get(), cin.get());
        let xs = (0..n).map(|_| cin.get()).collect();
        println!("{}", solve(n, a, b, xs));
    }
}