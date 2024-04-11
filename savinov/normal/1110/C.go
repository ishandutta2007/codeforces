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

func gcd(a, b int) int {
	for ; b > 0; a, b = b, a%b {
	}
	return a
}

func solve(a int) int {
	var res int
	for i := 1; i < a; i++ {
		g := gcd(i^a, i&a)
		if g > res {
			res = g
		}
	}
	return res
}

func main() {
	defer writer.Flush()

	q := NextInt()

l:
	for ; q > 0; q-- {
		x := uint(NextInt())

		if x&(x+1) == 0 {
			for t := uint(2); t*t <= x; t++ {
				if x%t == 0 {
					println(x / t)
					continue l
				}
			}
			println(1)
			continue l
		}

		l := bits.Len(x)
		println((1 << uint(l)) - 1)
	}
}