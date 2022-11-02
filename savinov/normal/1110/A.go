package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
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

func main() {
	defer writer.Flush()

	b := NextInt()
	k := NextInt()

	a := NextIntArray(k)

	if b%2 == 0 {
		if a[k-1]%2 == 0 {
			println("even")
		} else {
			println("odd")
		}
		return
	}
	var s int
	for i := 0; i < k; i++ {
		s = (s + a[i]) % 2
	}

	if s%2 == 0 {
		println("even")
	} else {
		println("odd")
	}
}