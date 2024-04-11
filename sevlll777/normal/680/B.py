n, a = map(int, input().split())
A = list(map(int, input().split()))
i = 1
cnt = A[a - 1]
while a - 1 - i >= 0 or a - 1 + i <= n - 1:
    x = a - 1 - i
    y = a - 1 + i
    if x >= 0 and y <= n - 1:
        if A[x] and A[y]:
            cnt += 2
    elif x >= 0:
        cnt += A[x]
    else:
        cnt += A[y]
    i += 1
print(cnt)