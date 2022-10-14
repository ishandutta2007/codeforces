n = int(input())
A = list(map(int, input().split()))
dp = [A[0] // 3]
cnt = A[0]
for i in range(1, n):
    ans = 0
    x = cnt - 3 * dp[-1]
    y = A[i] // 2
    if y <= x:
        dp.append(dp[-1] + y)
    else:
        s = A[i] - 2 * x
        dp.append(dp[-1] + s // 3 + x)
    cnt += A[i]
print(dp[-1])