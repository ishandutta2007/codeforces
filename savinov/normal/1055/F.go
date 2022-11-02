package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"sort"
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
		res = res*10 + int64(c - '0')
	}
	if negative {
		res = -res
	}
	return res
}

func NextInt() int {
	return int(NextInt64())
}

var xx []uint64

func calculateForBit(prefix uint64, bit uint, old []uint64, new []uint64) (int64, []uint64) {
	res := int64(0)
	l, r := 0, 0

	for i := 0; i < len(old); {
		var j1, j2 int

		left := (((old[i] ^ prefix) >> bit) ^ 1) << bit
		right := left + (1 << bit)

		for ; l < len(xx) && xx[l] < left; l++ {
		}
		for ; r < len(xx) && xx[r] < right; r++ {
		}

		for j1 = i; j1 < len(old) && old[j1]>>bit == old[i]>>bit; j1++ {
			res += int64(r - l)
		}

		if j1 != len(old) {
			left = (((old[j1] ^ prefix) >> bit) ^ 1) << bit
			right = left + (1 << bit)

			for ; l < len(xx) && xx[l] < left; l++ {
			}
			for ; r < len(xx) && xx[r] < right; r++ {
			}
		}

		for j2 = j1; j2 < len(old) && old[j2]>>(bit+1) == old[i]>>(bit+1); j2++ {
			res += int64(r - l)
		}

		copy(new[i:i+j2-j1], old[j1:j2])
		copy(new[i+j2-j1:j2], old[i:j1])
		i = j2
	}

	return res, new
}

func main() {

	n := NextInt()
	k := NextInt64() - 1

	xx = make([]uint64, n)

	for i := 1; i < n; i++ {
		p := NextInt()
		v := uint64(NextInt64())
		p--
		xx[i] = xx[p] ^ v
	}

	rand.Shuffle(n, func(i, j int) {
		xx[i], xx[j] = xx[j], xx[i]
	})

	sort.Slice(xx, func(i, j int) bool {
		return xx[i] < xx[j]
	})

	current := make([]uint64, n)
	copy(current, xx)

	buf := make([]uint64, n)

	sum := int64(0)
	answer := uint64(0)

	for i := 61; i >= 0; i-- {
		if res, newArr := calculateForBit(answer^(1<<uint(i)), uint(i), current, buf); sum+res <= k {
			sum += res
			current, buf = newArr, current
			answer ^= 1 << uint(i)
		}
	}

	fmt.Println(answer)
}