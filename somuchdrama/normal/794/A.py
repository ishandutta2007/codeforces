q, b, c = map(int, input().split())
n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in a:
	if b < i < c:
		ans += 1
print(ans)