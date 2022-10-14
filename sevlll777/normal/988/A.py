n, k = map(int, input().split())
A = list(map(int, input().split()))
raz = []
balls = set()
for z in range(n):
    if A[z] not in balls:
        balls.add(A[z])
        raz.append(str(z+1))
if len(raz) < k:
    print('NO')
else:
    print('YES')
    print(' '.join(raz[:k]))