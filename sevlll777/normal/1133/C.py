n = int(input())
A = list(map(int, input().split()))
z = {}
ans = 0
for i in range(n):
    if A[i] not in z:
        z[A[i]] = 0
    z[A[i]] += 1
for x in z:
    cnt = 0
    cnt += z[x]
    if x + 1 in z:
        cnt += z[x + 1]
    if x + 2 in z:
        cnt += z[x + 2]
    if x + 3 in z:
        cnt += z[x + 3]
    if x + 4 in z:
        cnt += z[x + 4]
    if x + 5 in z:
        cnt += z[x + 5]
    ans = max(ans, cnt)
print(ans)