#!/usr/bin/python3

n = int(input())
a = list(map(int, input().split()))
b = sorted([(a[i], i) for i in range(n)])
res = []

for _ in range(n):
	for i in range(n - 1):
		if b[i][1] > b[i + 1][1]:
			res.append((b[i + 1][1], b[i][1]))
			b[i], b[i + 1] = b[i + 1], b[i]

print(len(res))
for i, j in res: print(i + 1, j + 1)