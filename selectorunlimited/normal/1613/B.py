from collections import Counter
import math
import sys
from bisect import bisect,bisect_left,bisect_right
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def mod(): return 10**9+7
 
for _ in range(INT()):
    n = INT()
    #s = input()
    #n,m = MAP()
    arr = LIST()
    arr.sort()
    d = {}
    for i in arr:
        d[i] = 1
    ans = []
    x = n//2
    i = 1
    while(i < n):
        if arr[i] in d and arr[i] == arr[i-1]:
            i += 1
            continue
        ans.append([arr[i],arr[0]])
        i += 1
        if len(ans) == x:
            break
    for i in ans:
        print(*i)