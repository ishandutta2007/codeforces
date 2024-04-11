n, k = map(int, input().split())
bzz = []
cnt = 0
A = list(map(int, input().split()))
for i in range(k):
    if max(A) - min(A) != 0:
        i1, i2 = 0, 0
        ma, mi = 0, 10 ** 9
        for i in range(n):
            if A[i] > ma:
                ma = A[i]
                i1 = i
            if A[i] < mi:
                mi = A[i]
                i2 = i
        bzz.append([i1 + 1, i2 + 1])
        A[i1] -= 1
        A[i2] += 1
        cnt += 1
print(max(A) - min(A), cnt)
for i in bzz:
    print(*i)