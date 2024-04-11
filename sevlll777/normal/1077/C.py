n = int(input())
A = list(map(int, input().split()))
s = sum(A)
for i in range(n):
    A[i] = [A[i], i + 1]
ans = []
A.sort()
m = A[-1][0]
for i in range(n):
    if A[i][0] != m:
        if s - A[i][0] - m == m:
            ans.append(A[i][1])
    else:
        if i == n - 1:
            if s - A[i][0] - A[-2][0] == A[-2][0]:
                ans.append(A[i][1])
        else:
            if s - A[i][0] - m == m:
                ans.append(A[i][1])
print(len(ans))
print(*ans)