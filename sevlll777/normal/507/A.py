n, k = map(int, input().split())
A = list(map(int, input().split()))
for i in range(n):
    A[i] = [A[i], i]
A.sort()
ans = []
for j in range(n):
    if k >= A[j][0]:
        k -= A[j][0]
        ans.append(A[j][1] + 1)
print(len(ans))
print(*ans)