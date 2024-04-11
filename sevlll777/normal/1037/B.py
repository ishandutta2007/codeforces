n, s = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
cnt = 0
if A[n // 2] == s:
    pass
elif A[n // 2] > s:
    x = n // 2
    while x >= 0 and A[x] > s:
        cnt += A[x] - s
        x -= 1
else:
    x = n // 2
    while x < n and A[x] < s:
        cnt += s - A[x]
        x += 1
print(cnt)