n = int(input())
A = list(map(int, input().split()))
A.sort()
B = [0] * n
ans = 0
for i in range(n):
    if B[i] == 0:
        ans += 1
        B[i] = 1
        for j in range(n):
            if A[j] % A[i] == 0:
                B[j] = 1
print(ans)