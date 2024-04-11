package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		l := len(s)
		if l <= 10 {
			fmt.Println(s)
		} else {
			fmt.Printf("%c%d%c\n", s[0], l - 2, s[l - 1])
		}
	}
}