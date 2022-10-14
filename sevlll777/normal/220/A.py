n = int(input())
A = list(map(int, input().split()))
B = sorted(A)
gB = set()
for i in range(n):
    if A[i] != B[i]:
        gB.add(i + 1)
if len(gB) == 0 or len(gB) == 2:
    print('YES')
else:
    print('NO')