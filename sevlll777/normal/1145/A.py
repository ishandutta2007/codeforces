from collections import deque
n = int(input())
A = list(map(int,input().split()))
Ans = 1
for m in (2, 4, 8, 16, 32, 64):
    if n >= m:
        K=A[:m]
        for i in range(m, n):
            if i%m==0 and K==sorted(K): 
                Ans=m
            K=K[1:]
            K.append(A[i])
        if K==sorted(K): 
            Ans=m
print(Ans)