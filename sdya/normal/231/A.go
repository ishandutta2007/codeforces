package main

import "fmt"

func main() {
	var n, res int
	fmt.Scanf("%d\n", &n)
	res = 0
	for i := 0; i < n; i++ {
		var a, b, c int
		fmt.Scanf("%d%d%d\n", &a, &b, &c)
		if a + b + c >= 2 {
			res = res + 1
		}
	}
	fmt.Println(res)
}