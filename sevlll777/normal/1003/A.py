from collections import Counter
n = int(input())
A = list(map(int, input().split()))
ans = 0
z = Counter(A)
for i in z:
    ans = max(ans, z[i])
print(ans)