class SegmentTree:
    def __init__(self, init_val, segfunc, ide_ele):
        n = len(init_val)
        self.segfunc = segfunc
        self.ide_ele = ide_ele
        self.num = 1 << (n - 1).bit_length()
        self.tree = [ide_ele] * 2 * self.num
        self.size = n
        for i in range(n):
            self.tree[self.num + i] = init_val[i]
        for i in range(self.num - 1, 0, -1):
            self.tree[i] = self.segfunc(self.tree[2 * i], self.tree[2 * i + 1])

    def update(self, k, x):
        k += self.num
        self.tree[k] = self.segfunc(self.tree[k],x)
        while k > 1:
            k >>= 1
            self.tree[k] = self.segfunc(self.tree[2*k], self.tree[2*k+1])

    def query(self, l, r):
        if r==self.size:
            r = self.num

        res = self.ide_ele

        l += self.num
        r += self.num
        right = []
        while l < r:
            if l & 1:
                res = self.segfunc(res, self.tree[l])
                l += 1
            if r & 1:
                right.append(self.tree[r-1])
            l >>= 1
            r >>= 1

        for e in right[::-1]:
            res = self.segfunc(res,e)
        return res

import sys,random,bisect
from collections import deque,defaultdict
from heapq import heapify,heappop,heappush
from itertools import permutations
from math import log,gcd

input = lambda :sys.stdin.readline().rstrip()
mi = lambda :map(int,input().split())
li = lambda :list(mi())

for _ in range(1):
    #S = [random.choice("ABC") for i in range(10)]
    #T = [random.choice("ABC") for i in range(10)]
    #U = [random.choice("ABC") for i in range(10)]
    #S = "".join(S)
    #T = "".join(T)
    #U = "".join(U)
    S = input()
    T = input()
    U = input()

    max_match = 0
    for q in range(26):
        ch = chr(q+ord("A"))
        X = [i for i in range(len(S)) if S[i]==ch]
        Y = [i for i in range(len(T)) if T[i]==ch]
        Z = [i for i in range(len(U)) if U[i]==ch]
        x,y,z = len(X),len(Y),len(Z)
        """
        0 <= k <= min(x,y)
        maximize k+min(z,x+y-2*k)
        """

        check = -1
        k = -1
        for tt in range(min(x,y)+1):
            tmp = tt + min(x+y-2*tt,z)
            if tmp > check:
                k = tt
                check = tmp
        max_match += check
    
    check = -1
    EM = -1
    for t in range(max_match+1):
        tmp = min(t,len(S))+min(t,len(T))+min(t,len(U))-2*t
        if tmp > check:
            check = tmp
            EM = t

    ST = []
    TU = []
    US = []

    res = []
    use_S = [False] * len(S)
    use_T = [False] * len(T)
    use_U = [False] * len(U)

    for q in range(26):
        ch = chr(q+ord("A"))
        X = [i for i in range(len(S)) if S[i]==ch]
        Y = [i for i in range(len(T)) if T[i]==ch]
        Z = [i for i in range(len(U)) if U[i]==ch]
        x,y,z = len(X),len(Y),len(Z)
        """
        0 <= k <= min(x,y)
        maximize k+min(z,x+y-2*k)
        """

        check = -1
        k = -1
        for tt in range(min(x,y)+1):
            tmp = tt + min(x+y-2*tt,z)
            if tmp > check:
                k = tt
                check = tmp

        def calc(tt):
            if tt < 0 or tt > min(x,y):
                return -1
            return tt + min(x+y-2*tt,z)
        assert calc(k-1) <= calc(k)
        assert calc(k) >= calc(k+1)
        for _ in range(k):
            a,b = X.pop(),Y.pop()
            if EM:
                EM -= 1
                ST.append(ch)
                use_S[a] = True
                use_T[b] = True
        while Z and X and EM:
            a,c = X.pop(),Z.pop()
            US.append(ch)
            use_S[a] = use_U[c] = True
            EM -= 1
        while Z and Y and EM:
            b,c = Y.pop(),Z.pop()
            TU.append(ch)
            use_T[b] = use_U[c] = True
            EM -= 1
    

    ans = []
    X = [S[i] for i in range(len(S)) if not use_S[i]]
    Y = [T[i] for i in range(len(T)) if not use_T[i]]
    Z = [U[i] for i in range(len(U)) if not use_U[i]]
    while X and TU:
        ans.append(X.pop()+TU.pop())
    while Y and US:
        ans.append(Y.pop()+US.pop())
    while Z and ST:
        ans.append(Z.pop()+ST.pop())
    #print(ST,TU,US,X,Y,Z)

    for ch in ST:
        X.append(ch)
        Y.append(ch)
    for ch in TU:
        Y.append(ch)
        Z.append(ch)
    for ch in US:
        Z.append(ch)
        X.append(ch)
        

    if len(X) > len(Y):
        X,Y = Y,X
    if len(Y) > len(Z):
        Y,Z = Z,Y

    ALL = [X,Y,Z]

    while True:
        p = [0,1,2]
        p.sort(key=lambda i:len(ALL[i]))
        if not ALL[p[1]]:
            break
        a = ALL[p[2]].pop()
        b = ALL[p[1]].pop()
        ans.append(a+b)

    for a in ALL[p[2]]:
        ans.append(a+"A")

    print(len(ans))
    print(*ans,sep="\n")

    def check(S,res):
        n = len(res)
        for i in range(2**n):
            cnt = [0] * 26
            for j in range(n):
                p = res[j]
                if i>>j & 1:
                    cnt[ord(p[0])-ord("A")] += 1
                else:
                    cnt[ord(p[1])-ord("A")] += 1
            for j in range(26):
                ch = chr(ord("A")+j)
                if cnt[j] < S.count(ch):
                    break
            else:
                return True
        return False

    def checker(S,T,U,res):
        for p in [S,T,U]:
            if not check(p,res):
                return False
        return True

    

    #assert checker(S,T,U,ans)