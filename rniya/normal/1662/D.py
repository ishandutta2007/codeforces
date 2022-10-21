import sys,random,bisect
from collections import deque,defaultdict
from heapq import heapify,heappop,heappush
from itertools import permutations
from math import log,gcd


input = lambda :sys.stdin.readline().rstrip()
mi = lambda :map(int,input().split())
li = lambda :list(mi())

res = []
for _ in range(int(input())):
    S = input()
    T = input()
    if S.count("B")&1!=T.count("B")&1:
        res.append("NO")
        continue
    S = "".join([S[i] for i in range(len(S)) if S[i]!="B"])
    T = "".join([T[i] for i in range(len(T)) if T[i]!="B"])

    #print(S,T)

    s = []
    for p in S:
        if s and s[-1]==p:
            s.pop()
        else:
            s.append(p)
    
    t = []
    for p in T:
        if t and t[-1]==p:
            t.pop()
        else:
            t.append(p)
    
    #print(s,t)
    if s==t:
        res.append("YES")
    else:
        res.append("NO")



print(*res,sep="\n")