fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s: Vec<char> = s.trim().chars().collect();
    let n = s.len();
    let mut ans: Vec<char> = vec!['0'; n];
    let mut stack = std::collections::VecDeque::<(usize, char)>::new();
    for (i, &c) in s.iter().enumerate() {
        if c == '0' && stack.len() > 0 && stack.back().unwrap().1 == '1' {
            let (k, _) = stack.pop_back().unwrap();
            ans[k] = '1';
        } else {
            stack.push_back((i, c));
        }
    }
    let ans: String = ans.into_iter().collect();
    println!("{}", ans);
}

fn main() {
    run();
}