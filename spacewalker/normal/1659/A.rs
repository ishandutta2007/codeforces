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

fn solve(n: i32, r: i32, b: i32) -> String {
    let mut ans = String::with_capacity(n as usize);
    for i in 0..b + 1 {
        for _ in 0..r/(b+1) {
            ans.push('R');
        }
        if i < r % (b + 1) {
            ans.push('R') 
        }
        if i < b {
            ans.push('B');
        }
    }
    ans
}

fn main() {
    let mut cin = TokenReader::from_stdin(io::stdin());
    let t : usize = cin.get();
    for _ in 0..t {
        let (n, r, b) = (cin.get(), cin.get(), cin.get());
        println!("{}", solve(n, r, b));
    }
}