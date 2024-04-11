def better(i, j):
    return (A[i] | A[j]) == A[j]


n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
sm = {}
for i in range(n):
    if A[i] not in sm:
        sm[A[i]] = set()
    sm[A[i]].add(i)
rzr = set()
ans = 0
for i in sm:
    if len(sm[i]) >= 2:
        for kek in sm[i]:
            ans += B[kek]
            rzr.add(kek)
for _ in range(4):
    cc = set()
    for i in range(n):
        f = 1
        if i not in rzr:
            for j in rzr:
                if f and better(i, j):
                    cc.add(i)
                    f = 0
                    ans += B[i]
    rzr |= cc
print(ans)