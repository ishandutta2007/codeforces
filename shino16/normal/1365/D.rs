#[allow(unused_imports)]
use std::io::{stdin, stdout, BufWriter, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn neigh(r: usize, c: usize, h: usize, w: usize) -> impl Iterator<Item = (usize, usize)> {
    let dr = [1, -1, 0, 0];
    let dc = [0, 0, 1, -1];
    let mut res = Vec::new();
    for (dr, dc) in dr.iter().zip(dc.iter()) {
        let r1 = r as isize + dr;
        let c1 = c as isize + dc;
        if r1 >= 0 && r1 < h as isize && c1 >= 0 && c1 < w as isize {
            res.push((r1 as usize, c1 as usize));
        }
    }
    res.into_iter()
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    let t = scan.next();
    for _ in 0..t {
        let h = scan.next();
        let w = scan.next();
        let mut field: Vec<_> = (0..h)
            .map(|_| scan.next::<String>().as_bytes().to_owned())
            .collect();
        if (0..h).all(|r| (0..w).all(|c| field[r][c] != b'G')) {
            writeln!(out, "Yes").ok();
            continue;
        }
        let mut fail = false;
        for r in 0..h {
            for c in 0..w {
                if field[r][c] == b'B' {
                    neigh(r, c, h, w).for_each(|(r, c)| {
                        if field[r][c] == b'G' {
                            fail = true;
                        } else if field[r][c] == b'.' {
                            field[r][c] = b'#'
                        }
                    });
                }
            }
        }
        let mut ok = field.clone();
        if ok[h - 1][w - 1] == b'#' {
            fail = true;
        }
        ok[h - 1][w - 1] = b'o';
        let mut togo = vec![(h - 1, w - 1)];
        while let Some((r, c)) = togo.pop() {
            for (r, c) in neigh(r, c, h, w) {
                if ok[r][c] != b'o' && ok[r][c] != b'#' {
                    ok[r][c] = b'o';
                    togo.push((r, c));
                }
            }
        }
        fail = fail || (0..h).any(|r| (0..w).any(|c| field[r][c] == b'G' && ok[r][c] != b'o'));
        writeln!(out, "{}", if fail { "No" } else { "Yes" }).ok();
    }
}