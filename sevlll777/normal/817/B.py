n = int(input())
A = list(map(int, input().split()))
A.sort()
p = A[0] * A[1] * A[2]
c = 1
for i in range(3, n):
    if A[i] == A[2]:
        c += 1
    else:
        break
if A[0] == A[1] == A[2]:
    print((c + 2) * (c + 1) * c // 6)
elif A[1] == A[2]:
    print((c + 1) * c // 2)
else:
    print(c)