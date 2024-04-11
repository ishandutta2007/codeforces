n = int(input())
A = list(map(int, input().split()))
c = set()
ans = 1
for i in A:
    if i in c:
        c.discard(i)
    else:
        c.add(i)
    ans = max(ans, len(c))
print(ans)