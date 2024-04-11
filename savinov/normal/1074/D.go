package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReaderSize(os.Stdin, 2<<16)

var p map[int]int
var x map[int]int
var s map[int]int

func get(v int) (int, int) {
	if par, ok := p[v]; !ok || par == v {
		return v, 0
	}
	var t int
	p[v], t = get(p[v])
	x[v] ^= t

	return p[v], x[v]
}

func getSize(v int) int {
	if _, ok := s[v]; !ok {
		s[v] = 1
	}
	return s[v]
}

func unite(a, b, xor int) {
	a, xa := get(a)
	b, xb := get(b)

	if a == b {
		return
	}

	if getSize(a) > getSize(b) {
		a, b = b, a
	}

	p[a] = b
	x[a] = xor ^ xa ^ xb
	s[a] += getSize(b)
}

func query(a, b int) (int, bool) {
	a, xa := get(a)
	b, xb := get(b)

	if a != b {
		return -1, false
	}
	return xa ^ xb, true
}

func main() {

	var q int
	fmt.Fscan(in, &q)

	p = make(map[int]int, 2*q)
	x = make(map[int]int, 2*q)
	s = make(map[int]int, 2*q)

	last := 0
	for i := 0; i < q; i++ {
		var t int
		fmt.Fscan(in, &t)
		switch t {
		case 1:
			var l, r, x int
			fmt.Fscan(in, &l, &r, &x)
			l, r, x = l^last, r^last, x^last
			if l > r {
				l, r = r, l
			}
			r += 1
			unite(l, r, x)
		case 2:
			var l, r int
			fmt.Fscan(in, &l, &r)
			l, r = l^last, r^last
			if l > r {
				l, r = r, l
			}
			r += 1

			answer, ok := query(l, r)
			if ok {
				last = answer
			} else {
				last = 1
			}
			fmt.Printf("%d\n", answer)
		}
	}
}