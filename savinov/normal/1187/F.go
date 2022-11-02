package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"math"
	"math/big"
	"os"
)

var reader *bufio.Reader
var writer *bufio.Writer

var inputFile = flag.String("input", "", "")

func init() {
	flag.Parse()
	var i io.Reader
	if *inputFile != "" {
		i, _ = os.Open(*inputFile)
	} else {
		i = os.Stdin
	}
	reader = bufio.NewReaderSize(i, 1<<20)
	writer = bufio.NewWriterSize(os.Stdout, 1<<20)
}

func println(a ...interface{}) {
	_, _ = fmt.Fprintln(writer, a...)
}

func printf(format string, a ...interface{}) {
	_, _ = fmt.Fprintf(writer, format, a...)
}

func scanf(format string, a ...interface{}) {
	_, _ = fmt.Fscanf(reader, format, a...)
}

func scan(a interface{}) {
	_, _ = fmt.Fscan(reader, a)
}

func NextInt64() int64 {
	var res int64
	scan(&res)
	return res
}

func NextInt() int {
	var res int
	scan(&res)
	return res
}

func NextIntArray(n int) []int {
	res := make([]int, n)
	for i := range res {
		scan(&res[i])
	}
	return res
}

func NextInt64Array(n int) []int64 {
	res := make([]int64, n)
	for i := range res {
		scan(&res[i])
	}
	return res
}

func NextString() string {
	var res string
	scan(&res)
	return res
}

func NextBigInt() *big.Int {
	n := new(big.Int)
	n, _ = n.SetString(NextString(), 10)
	return n
}

func AbsInt64(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func MinInt64(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

func MaxInt64(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func MaxInt(x, y int) int {
	if x > y {
		return x
	}
	return y
}


type segment struct {
	l int64
	r int64
}

func newSegment() segment {
	return segment{
		l: math.MinInt64,
		r: math.MaxInt64,
	}
}

func intersect(a, b segment) segment {
	return segment{
		l: MaxInt64(a.l, b.l),
		r: MinInt64(a.r, b.r),
	}
}

func (s segment) len() int64 {
	if s.l >= s.r {
		return 0
	}
	return s.r - s.l
}

const MOD = 1000000007


func inv(a int64) int64 {
	res := int64(1)
	for a > 1 {
		res = res * (MOD - MOD / a) % MOD
		a = MOD % a
	}
	return res
}


func prob2(a, b segment) int64 {
	return intersect(a, b).len() * inv(a.len() * b.len() % MOD) % MOD
}

func prob3(a, b, c segment) int64 {
	return intersect(a, intersect(b, c)).len() * inv(a.len() * b.len() % MOD * c.len() % MOD) % MOD
}

func prob(a, b, c segment) int64 {
	return 1 - prob2(a, b) - prob2(b, c) + prob3(a, b, c)
}


func main() {
	defer writer.Flush()

	n := NextInt()
	a := make([]segment, n)
	for i := 0; i < n; i++ {
		a[i].l = NextInt64()
	}
	for i := 0; i < n; i++ {
		a[i].r = NextInt64() + 1
	}

	probs := make([]int64, n)

	s := int64(1)
	probs[0] = 1
	for i := 1; i < n; i++ {
		probs[i] = 1 - prob2(a[i - 1], a[i])
		s += probs[i]
		s %= MOD
	}

	answer := int64(0)
	for i := 0; i < n; i++ {
		s2 := s - probs[i] + 1
		if i > 0 {
			s2 -= probs[i - 1]
			if i > 1 {
				answer += prob(a[i - 2], a[i - 1], a[i])
			} else {
				answer += probs[i]
			}
		}

		if i + 1 < n {
			s2 -= probs[i + 1]
			if i > 0 {
				answer += prob(a[i-1], a[i], a[i+1])
			} else {
				answer += probs[i + 1]
			}
		}

		answer += s2 * probs[i]
		answer %= MOD
	}

	if answer < 0 {
		answer += MOD
	}

	println(answer)
}