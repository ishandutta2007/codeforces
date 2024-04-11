// 
// 
// xorn-1xor
// a[0]xor
// and, or 
// or = and + xor
// A B
// 
// n=2
// xor 0a&b 
// 
// 
// a=0
// 
// and
// or

fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read();
    let mut cnt = 0;
    let mut query = |op: &str, x: usize, y: usize| -> usize {
        assert!(x != y && x.max(y) < n);
        assert!(cnt < n + 1);
        cnt += 1;
        println!("{} {} {}", op, x + 1, y + 1);
        read()
    };
    let mut elem = vec![None; n];
    let mut pair = None;
    let mut xor = vec![0; n];
    for i in 1..n {
        let v = query("XOR", 0, i);
        if let Some(k) = elem[v] {
            pair = Some((k, i));
        }
        xor[i] = v;
        elem[v] = Some(i);
    }
    let mut ans = vec![0; n];
    if let Some(k) = elem[0] {
        let v = query("AND", 0, k);
        ans[0] = v ^ xor[k];
    } else if let Some((a, b)) = pair {
        let v = query("AND", a, b);
        ans[0] = v ^ xor[a];
    } else if let Some(k) = elem[n - 1] {
        let x = (1..n).find(|p| *p != k).unwrap();
        let v = query("AND", 0, x) | query("AND", k, x);
        ans[0] = xor[x] ^ v;
    }
    for i in 1..n {
        ans[i] = ans[0] ^ xor[i];
    }
    let mut s = String::from("!");
    for a in ans {
        s.push_str(&format!(" {}", a));
    }
    println!("{}", s);
}

fn main() {
    run();
}