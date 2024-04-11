fn read() -> (
    usize,
    usize,
    Vec<Vec<(usize, usize, i64)>>,
    Vec<(u8, usize, usize, usize, usize)>,
) {
    let mut s = String::new();
    use std::io::Read;
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let mut next = || it.next().unwrap();
    let h: usize = next().parse().unwrap();
    let w: usize = next().parse().unwrap();
    let k: usize = next().parse().unwrap();
    let mut a = vec![];
    for _ in 0..k {
        let len: usize = next().parse().unwrap();
        let mut p = vec![];
        for _ in 0..len {
            let x: usize = next().parse().unwrap();
            let y: usize = next().parse().unwrap();
            let v: i64 = next().parse().unwrap();
            p.push((x, y, v));
        }
        a.push(p);
    }
    let q: usize = next().parse().unwrap();
    let mut query = vec![(0, 0, 0, 0, 0); q];
    for q in query.iter_mut() {
        if next() == "SWITCH" {
            q.0 = 0;
            q.1 = next().parse::<usize>().unwrap();
        } else {
            q.0 = 1;
            q.1 = next().parse::<usize>().unwrap();
            q.2 = next().parse::<usize>().unwrap();
            q.3 = next().parse::<usize>().unwrap();
            q.4 = next().parse::<usize>().unwrap();
        }
    }
    (h, w, a, query)
}

fn diff(a: usize, b: usize) -> usize {
    a.max(b) - a.min(b)
}

fn main() {
    let (h, w, a, ask) = read();
    // id, ord, sum
    let mut board = vec![vec![(0, 0, 0); w + 2]; h + 2];
    for (i, a) in a.iter().enumerate() {
        let mut sum = 0;
        for (j, &(x, y, v)) in a.iter().enumerate().rev() {
            sum += v;
            board[x][y] = (i + 1, j, sum);
        }
    }
    let board = board;
    let mut state = vec![true; a.len() + 1];
    state[0] = false;
    for (op, p, q, r, s) in ask {
        if op == 0 {
            state[p] ^= true;
        } else {
            let mut ans = 0;
            for (state, a) in state[1..].iter().zip(a.iter()) {
                let (x, y, _) = a[0];
                if *state && p <= x && x <= r && q <= y && y <= s {
                    ans += board[x][y].2;
                }
            }
            for board in board[p..=r].iter() {
                for &(inner, outer) in [(q, q - 1), (s, s + 1)].iter() {
                    let (c, k, _) = board[inner];
                    if state[c] && c == board[outer].0 && diff(board[outer].1, k) == 1 {
                        if board[inner].1 > board[outer].1 {
                            ans += board[inner].2;
                        } else {
                            ans -= board[outer].2;
                        }
                    }
                }
            }
            for j in q..=s {
                for &(inner, outer) in [(p, p - 1), (r, r + 1)].iter() {
                    let (c, k, _) = board[inner][j];
                    if state[c] && c == board[outer][j].0 && diff(board[outer][j].1, k) == 1 {
                        if board[inner][j].1 > board[outer][j].1 {
                            ans += board[inner][j].2;
                        } else {
                            ans -= board[outer][j].2;
                        }
                    }
                }
            }
            println!("{}", ans);
        }
    }
}