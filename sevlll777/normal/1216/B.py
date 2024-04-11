n = int(input())
A = list(map(int, input().split()))
for i in range(n):
    A[i] = [A[i], i]
A.sort(reverse=True)
B = []
ans = 0
for i in range(n):
    x, ind = A[i]
    ans += x * i + 1
    B.append(ind + 1)
print(ans)
print(*B)