cnt = [0] * 11
#kitten
n,m,k = (int(z) for z in input().split())
for i in range(n):
    c = input()
    for j in range(m):
	    if c[j] == 'Y':
	        cnt[j] += 1
ans = 0
for i in range(m):
    if cnt[i] >= k:
        ans += 1
print(ans)