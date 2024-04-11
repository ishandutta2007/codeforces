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

fn solve(n: i32, k: i32, bstr: &str) {
    let n : usize = n as usize;
    let mut bstr : Vec<i32> = bstr.chars().map(|c| if c == '1' {1} else {0}).collect();
    if k % 2 == 1 {
        bstr = bstr.iter().map(|v| 1 ^ v).collect();
    }
    let mut flips_left = k;
    let mut flips_taken : Vec<i32> = bstr.iter().map(|&ch| {
        if flips_left > 0 && ch == 0 {
            flips_left -= 1;
            1
        } else {
            0
        }
    }).collect();
    flips_taken[n-1] += flips_left;
    let answer_str : Vec<i32> = flips_taken.iter()
        .zip(bstr.iter())
        .map(|(flips, ch)| {
            (flips % 2 == 1) as i32 ^ ch
        }).collect();
    for bit in answer_str {
        print!("{}", bit);
    }
    println!("");
    for ct in flips_taken {
        print!("{} ", ct);
    }
    println!("");

}

fn main() {
    let mut cin = TokenReader::from_stdin(io::stdin());
    let t : usize = cin.get();
    for _ in 0..t {
        let (n, k) : (i32, i32) = (cin.get(), cin.get());
        let bstr: String = cin.get();
        solve(n, k, &bstr);
    }
}