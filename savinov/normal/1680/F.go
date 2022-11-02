package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"log"
	"math/big"
	"os"
	"runtime/pprof"
)

type Graph struct {
	g [][]int

	used   []int
	parity []int
}

func NewGraph(n int) *Graph {
	return &Graph{
		g:      make([][]int, n),
		used:   make([]int, n),
		parity: make([]int, n),
	}
}

func (g *Graph) clear() {
	for i := range g.used {
		g.used[i] = 0
	}
}

func (g *Graph) addEdge(u, v int) {
	g.g[u] = append(g.g[u], v)
	g.g[v] = append(g.g[v], u)
}

func (g *Graph) dfs(v int, p int, totalBad int, F *int, T *int) (int, int) {
	g.used[v] = 1
	if p != -1 {
		g.parity[v] = g.parity[p] ^ 1
	}

	bad, good := 0, 0

	for _, to := range g.g[v] {
		if to == p {
			continue
		}

		if g.used[to] == 2 {
			if g.parity[to] == g.parity[v] {
				bad -= 1
			} else {
				good -= 1
			}
		} else if g.used[to] == 1 {
			if g.parity[to] == g.parity[v] {
				bad += 1
			} else {
				good += 1
			}
		} else {
			nbad, ngood := g.dfs(to, v, totalBad, F, T)

			if nbad == totalBad && ngood == 0 {
				*F = v
				*T = to
			}

			bad += nbad
			good += ngood
		}

	}

	g.used[v] = 2

	return bad, good
}

func (g *Graph) dfs2(v int, p int, c int, F *int, T *int) (int, int) {
	g.used[v] = 1
	g.parity[v] = c

	bad, good := 0, 0

	for _, to := range g.g[v] {
		if to == p {
			continue
		}

		if g.used[to] == 2 {
			continue
		} else if g.used[to] == 1 {
			if g.parity[to] == g.parity[v] {
				*F = v
				*T = to

				bad += 1
			} else {
				good += 1
			}
		} else {
			nbad, ngood := g.dfs2(to, v, c^1, F, T)

			bad += nbad
			good += ngood
		}

	}

	g.used[v] = 2

	return bad, good
}

func solve() {
	n := NextInt()
	m := NextInt()

	g := NewGraph(n)

	for i := 0; i < m; i++ {
		u := NextInt() - 1
		v := NextInt() - 1

		g.addEdge(u, v)
	}

	F, T := -1, -1

	bad, _ := g.dfs2(0, -1, 0, &F, &T)
	g.clear()

	if bad == 0 {
		println("YES")
		for i := range g.parity {
			printf("%d", g.parity[i]^1)
		}
		printf("\n")
	} else if bad == 1 {
		g.used[T] = 2
		g.dfs2(F, T, 0, nil, nil)
		g.dfs2(T, F, 0, nil, nil)

		println("YES")
		for i := range g.parity {
			printf("%d", g.parity[i]^1)
		}
		printf("\n")
	} else {
		F, T = -1, -1
		g.dfs(0, -1, bad, &F, &T)

		if F == -1 {
			println("NO")
			return
		}
		g.clear()
		
		g.used[T] = 2
		g.dfs2(F, T, 0, nil, nil)
		g.dfs2(T, F, 0, nil, nil)

		println("YES")
		for i := range g.parity {
			printf("%d", g.parity[i]^1)
		}
		printf("\n")
	}

}

func main() {
	defer writer.Flush()

	if *cpuprofile != "" {
		f, err := os.Create(*cpuprofile)
		if err != nil {
			log.Fatal(err)
		}
		pprof.StartCPUProfile(f)
		defer pprof.StopCPUProfile()
	}

	T := NextInt()

	for t := 0; t < T; t++ {
		solve()
	}
}

var reader *bufio.Reader
var writer *bufio.Writer

var inputFile = flag.String("input", "", "")
var cpuprofile = flag.String("cpuprofile", "", "write cpu profile to file")

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