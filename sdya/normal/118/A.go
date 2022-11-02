package main

import "fmt"

func isVowel(a uint8) bool {
	if a >= 'A' && a <= 'Z' {
		a = a - 'A' + 'a'
	}

	return a == 'a' || a == 'o' || a == 'y' || a == 'e' || a == 'u' || a == 'i';
}

func main() {
	var a string
	fmt.Scan(&a)
	n := len(a)

	for i := 0; i < n; i++ {
		if isVowel(a[i]) {
			continue
		}
		buf := a[i]
		if buf >= 'A' && buf <= 'Z' {
			buf = buf - 'A' + 'a'
		}
		fmt.Printf(".%c", buf)
	}
	fmt.Println()
}