// 
// (x mod a) >= (y mod a)
// 1 <= a <= 10^9
//
// 0 1 1x, y 
//
// 2^k, 2^(k + 1) , ka
// 
// 
//

fn read() -> String {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().chars().collect()
}

fn run() {
    loop {
        let s = read();
        if s != "start" {
            assert!(s == "end");
            break;
        }
        let mut cnt = 0;
        // (x mod a) >= (y mod a)
        let mut query = |x: u32, y: u32| -> bool {
            assert!(cnt < 60);
            assert!(x < 2 * 10u32.pow(9));
            assert!(y < 2 * 10u32.pow(9));
            cnt += 1;
            println!("? {} {}", x, y);
            let s = read();
            assert!(s != "e");
            s == "x"
        };
        let mut k = 0;
        while !query(1 << k, 2 << k) {
            k += 1;
        }
        // low < a <= high
        let mut low = 1 << k;
        let mut high = 2 << k;
        while high - low > 1 {
            let mid = (low + high) / 2;
            if query(low, mid) {
                high = mid;
            } else {
                low = mid;
            }
        }
        let mut ans = high;
        if k == 0 && query(0, 1) {
            ans = 1;
        }
        println!("! {}", ans);
    }
}

fn main() {
    run();
}