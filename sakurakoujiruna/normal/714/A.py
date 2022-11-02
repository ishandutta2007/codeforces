l1, r1, l2, r2, k = [int(s) for s in raw_input().split()]
l = max(l1, l2)
r = min(r1, r2)

ans = r - l + 1
if l <= k and k <= r :
	ans -= 1
ans = max(ans, 0)
print(ans)