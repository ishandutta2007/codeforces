import sys,random,bisect
from collections import deque,defaultdict
from heapq import heapify,heappop,heappush
from itertools import permutations
from math import log,gcd


input = lambda :sys.stdin.readline()
mi = lambda :map(int,input().split())
li = lambda :list(mi())

for _ in range(int(input())):
    n = int(input())
    memo = [-1] * 10
    for i in range(n):
        b,d = mi()
        memo[d-1] = max(memo[d-1],b)
    if -1 in memo:
        print("MOREPROBLEMS")
    else:
        print(sum(memo))