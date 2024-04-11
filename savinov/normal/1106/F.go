package main

import (
	"bufio"
	"fmt"
	"math"
	"math/big"
	"os"
)

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(bufio.NewReaderSize(os.Stdin, 1<<20))
	scanner.Split(bufio.ScanWords)
}

func NextInt64() int64 {
	scanner.Scan()
	var res int64
	var negative bool
	bytes := scanner.Bytes()
	if bytes[0] == '-' {
		negative = true
		bytes = bytes[1:]
	}
	for _, c := range bytes {
		res = res*10 + int64(c-'0')
	}
	if negative {
		res = -res
	}
	return res
}

func NextInt() int {
	return int(NextInt64())
}

func NextBigInt() *big.Int {
	scanner.Scan()
	n := new(big.Int)
	n, _ = n.SetString(scanner.Text(), 10)
	return n
}

const P = 998244353
const root = 3

//sum (min(r - i, min(x[l .. j[i]])) for i in range(l, r)

func polyMul(a, b []int64, mod int64) []int64 {
	res := make([]int64, len(a)+len(b)-1)
	for i, x := range a {
		for j, y := range b {
			res[i+j] += x * y
			res[i+j] %= mod
		}
	}
	return res
}

func polyMod(a, b []int64, mod int64) []int64 {
	res := a[:]
	for i := len(a) - 1; i >= len(b); i-- {
		for j, x := range b {
			res[i-1-j] += x * res[i]
			res[i-1-j] %= mod
		}
	}
	return res[:len(b)]
}

type BGStep struct {
	step  int64
	baby  []int64
	giant map[int64]int64
}

func pow(x int64, n int64, mod int64) int64 {
	res := int64(1)
	for ; n > 0; n >>= 1 {
		if n%2 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
	}
	return res
}

func NewBGStep(p int64, r int64) BGStep {
	res := BGStep{}
	res.step = int64(math.Sqrt(float64(p) + 2))
	res.baby = make([]int64, res.step)
	res.giant = make(map[int64]int64, res.step)

	rstep := pow(r, res.step, p)

	rr := pow(r, p-2, p)

	res.baby[0] = 1
	curg := int64(1)

	res.giant[curg] = 0

	for i := int64(0); i+1 < res.step; i++ {
		res.baby[i+1] = res.baby[i] * rr % p
		curg = curg * rstep % p

		res.giant[curg] = i + 1
	}

	return res
}

func (b BGStep) Logarithm(x int64) int64 {
	if x == 0 {
		panic("x == 0")
	}

	for i := int64(0); i < b.step; i++ {
		v := x * b.baby[i] % P
		if index, ok := b.giant[v]; ok {
			return index*b.step + i
		}
	}

	panic("this shouldn't happen")
}

func GCD(a, b int64, x, y *int64) int64 {
	if b == 0 {
		*x, *y = 1, 0
		return a
	}
	//a * x + b * y == g

	//a == b * k + a'

	g := GCD(b, a%b, x, y)

	// b * x + (a - k * b) * y == g

	*x, *y = *y, *x-a/b**y

	return g
}

func main() {
	k := NextInt()
	var b []int64
	for i := 0; i < k; i++ {
		b = append(b, NextInt64())
	}

	n, m := NextInt64() - 1, NextInt64()

	bgs := NewBGStep(P, root)

	log := bgs.Logarithm(m)

	poly := make([]int64, k)
	poly[0] = 1

	pt := make([]int64, k + 1)
	pt[1] = 1
	pt = polyMod(pt, b, P - 1)

	for ; n > 0; n >>= 1 {
		if n%2 == 1 {
			poly = polyMod(polyMul(poly, pt, P-1), b, P-1)
		}
		pt = polyMod(polyMul(pt, pt, P-1), b, P-1)
	}
	
	U := poly[k-1]
	Z := log

	//X * U == Z mod (P - 1)
	// X * u * gu == Z mod (P - 1)

	var x, y int64
	gu := GCD(U, P-1, &x, &y)

	//fmt.Println(gu)

	if Z%gu != 0 {
		fmt.Println("-1")
		return
	}

	// X * u == (Z / gu) mod (P - 1) / gu

	GCD(U/gu, (P-1)/gu, &x, &y)

	if x < 0 {
		x += P - 1
	}

	x = x * (Z / gu) % (P - 1)

	fmt.Println(pow(root, x, P))
}