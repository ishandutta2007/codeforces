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

fn solve(n: usize, cs: Vec<i32>) {
    let mut deltas = vec![0; n];
    let mut ans = vec![1; n];
    /*
        a[0] = 0 iff c[0] = 0
        if a[0] = 1, a[0] is the index of the first 0

        in general, if we know a[i],
        then after deducting the contribution from before this joined the sorted prefix,
        the ith zero is a[i] positions after position i
    */
    if cs[0] == 0 {
        ans[0] = 0;
    }
    for i in 0..n {
        if cs[i] == 0 {
            ans[i] = 0;
        }
        let pf = cs[i] - if ans[i] == 1 {i} else {0} as i32;
        if i as i32 + pf < n as i32 {
            ans[i + pf as usize] = 0;
        }
    }
    for x in ans {
        print!("{} ", x);
    }
    print!("\n");
}

fn main() {
    let mut cin = TokenReader::from_stdin(io::stdin());
    let t : usize = cin.get();
    for _ in 0..t {
        let n = cin.get();
        let cs = (0..n).map(|_| cin.get()).collect();
        solve(n, cs);
    }
}