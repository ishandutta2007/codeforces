package main

import "fmt"

func main() {
	var a[64] int
	var (
		n int
		k int)

	fmt.Scanf("%d%d", &n, &k)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	var res = 0
	for i := 0; i < n; i++ {
		if a[i] >= a[k - 1] && a[i] > 0 {
			res++
		}
	}

	fmt.Println(res)
}