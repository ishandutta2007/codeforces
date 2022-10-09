n = int(input())
a = input().split()
a = list(map(int, a))
a.sort()

r = 0
ans = 0
for l in range(n):
    while r < n and a[r] <= a[l] + 5:
        r += 1
    ans = max(ans, r - l)

print(ans)