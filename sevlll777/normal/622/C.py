n, m = map(int, input().split())
A = list(map(int, input().split()))
B = [-1]
for i in range(1, n):
    if A[i] == A[i - 1]:
        B.append(B[-1])
    else:
        B.append(i - 1)
ans = []
for _ in range(m):
    l, r, x = map(int, input().split())
    l -= 1
    r -= 1
    if A[r] != x:
        ans.append(r + 1)
    else:
        if B[r] >= l:
            ans.append(B[r] + 1)
        else:
            ans.append(-1)
print('\n'.join(list(map(str, ans))))