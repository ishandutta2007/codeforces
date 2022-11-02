package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"math/big"
	"os"
)

const mod = 1000000007

func solve() {
	x := NextInt()
	s := []byte(NextString())
	
	
	total := len(s)

	for l := 0; l < x;  {
		l++
		// println(l, s)
		cnt := s[l - 1] - '1'

		delta := total - l + mod
		if delta >= mod {
			delta -= mod
		}
		substr := s[l:]
		for ; cnt > 0; cnt-- {
			if len(s) < x {
				s = append(s, substr...)
			}
			total += delta
			if total >= mod {
				total -= mod
			}
		}
		// println(total)
	}

	println(total)
}

func main() {
	defer writer.Flush()

	t := NextInt()
	for c := 0; c < t; c++ {
		solve()
	}
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