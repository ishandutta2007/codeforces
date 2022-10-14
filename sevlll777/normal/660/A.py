from math import gcd
n = int(input())
A = list(map(int, input().split()))
ans = [A[0]]
i = 1
while i < n:
    if gcd(ans[-1], A[i]) == 1:
        ans.append(A[i])
        i += 1
    else:
        ans.append(1)
print(len(ans) - n)
print(*ans)