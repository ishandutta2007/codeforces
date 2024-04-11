package main

import "fmt"

func check(n int64, p2 int, p3 int) bool {
    for i := 0; i < p2; i++ {
        n = n / 2
    }
    for i := 0; i < p3; i++ {
        n = n / 3
    }
    return n >= 1
}

func solve(n int64) int {
    c := 0
    for i := 0; i < 32; i++ {
        for j := 0; j < 25; j++ {
            if check(n, i, j) {
                c += 1
            }
        }
    }
    return c
}

func main() {
    var l, r int64
    fmt.Scan(&l, &r)
    ans := solve(r) - solve(l - 1)
	fmt.Println(ans)
}