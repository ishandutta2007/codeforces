from math import *

prec = [0, 0.5, 1, 1]

def prob(known, unknown):
    cnt = 0
    ret = 0
    for i in range(4):
        cur = comb(known, i) * comb(unknown, 3 - i)
        cnt += cur
        ret += cur * prec[i]
    return ret / cnt

inp = input().split()
n = int(inp[0])
p = float(inp[1])

for i in range(n + 1):
    if prob(i, n - i) >= p:
        print(i)
        break