package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"math/big"
	"math/bits"
	"os"
)

func solve(n, x uint64) uint64 {
	if x > n {
		return 0
	}

	res := uint64(1)
	if x % 2 == 0 {
		res += solve(n, x + 1)
	}

	xlen := uint(bits.Len64(x))
	nlen := uint(bits.Len64(n))

	nx := x << (nlen - xlen)

	if nlen > xlen {
		res += (uint64(1) << (nlen - xlen)) - 2
	}

	if nx <= n && nlen > xlen {
		if n >> (nlen - xlen) == x {
			res += n - nx + 1
		} else {
			res += uint64(1) << (nlen - xlen)
		}
	}

	return res
}

func solveStupid(n, x uint64) uint64 {
	if x > n {
		return 0
	}

	res := uint64(1)
	if x % 2 == 0 {
		res += solveStupid(n, x + 1)
	}
	res += solveStupid(n, x * 2)

	return res
}

func main() {
	defer writer.Flush()

	n, k := uint64(NextInt64()), uint64(NextInt64())

	x := uint64(1)
	l := uint(0)
	for ; solve(n, x * 2) >= k; x *= 2 {
		l++
	}

	for i := uint(0); i < l; i++ {
		if solve(n, x + (uint64(1) << (l - i - 1))) >= k {
			x += uint64(1) << (l - i - 1)
		}
	}

	println(x)
}

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