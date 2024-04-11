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

const mod = 1000000007

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

func polyDiv(data []int32, a int) {
	for i := a; i < len(data); i++ {
		data[i] -= data[i-a]
		if data[i] < 0 {
			data[i] += mod
		}
	}
}

func polyMul(data []int32, a int) {
	for i := len(data) - 1; i >= a; i-- {
		data[i] += data[i-a]
		if data[i] >= mod {
			data[i] -= mod
		}
	}
}

func main() {
	defer writer.Flush()

	s := []byte(NextString())

	types := make([]int, len(s))

	counts := make([]int, 52)

	for i, c := range s {
		if c >= 'a' && c <= 'z' {
			types[i] = int(c - 'a')
		} else {
			types[i] = 26 + int(c-'A')
		}
		counts[types[i]]++
	}

	n := len(s)

	r := make([]int64, n+1)
	r[1] = 1
	for i := 2; i <= n; i++ {
		r[i] = int64(mod-(mod/i)) * r[mod%i] % mod
		if r[i]*int64(i)%mod != 1 {
			panic("oops")
		}
	}

	f := make([]int64, n+1)
	rf := make([]int64, n+1)

	f[0], rf[0] = 1, 1

	for i := 1; i <= n; i++ {
		f[i] = f[i-1] * int64(i) % mod
		rf[i] = rf[i-1] * r[i] % mod
	}

	total := make([]int32, n+1)
	total[0] = 1

	for _, c := range counts {
		if c > 0 {
			polyMul(total, c)
		}
	}

	answer := make([][]int32, len(counts))

	for i := range counts {
		if counts[i] == 0 {
			continue
		}

		answer[i] = make([]int32, len(counts))
		cur := total

		polyDiv(cur, counts[i])

		for j := 0; j < i; j++ {
			if counts[j] == 0 {
				continue
			}

			polyDiv(cur, counts[j])

			if counts[i]+counts[j] <= n/2 {
				answer[i][j] = cur[n/2-(counts[i]+counts[j])] + cur[n/2]

				if answer[i][j] >= mod {
					answer[i][j] -= mod
				}
			}

			polyMul(cur, counts[j])
		}

		polyMul(cur, counts[i])

	}

	var mul int64 = 1

	for _, c := range counts {
		mul = mul * rf[c] % mod
	}
	mul = mul * f[n/2] % mod
	mul = mul * f[n/2] % mod

	q := NextInt()

	for i := 0; i < q; i++ {
		x := NextInt() - 1
		y := NextInt() - 1

		t1, t2 := types[x], types[y]
		if t1 < t2 {
			t1, t2 = t2, t1
		}

		if t1 == t2 {
			println(int64(total[n/2]) * mul % mod)
		} else {
			println(int64(answer[t1][t2]) * mul % mod)
		}
	}
}