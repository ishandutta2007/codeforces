m, n = map(int, input().split())
D = []
for i in range(m):
    A = list(map(int, input().split()))
    D.append(set(A[1:]))
for i in range(m):
    for j in range(i + 1, m):
        if D[i].intersection(D[j]) == set():
            print('impossible')
            exit(0)
print('possible')