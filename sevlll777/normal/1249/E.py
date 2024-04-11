n, c = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
sb = [0]
for i in B:
    sb.append(sb[-1] + i)
ans = [0]
hemin = 0
for i in range(1, n):
    tw = min(ans[i - 1] + A[i - 1], hemin + c + sb[i])
    ans.append(tw)
    hemin = min(hemin, ans[i] - sb[i])
print(*ans)