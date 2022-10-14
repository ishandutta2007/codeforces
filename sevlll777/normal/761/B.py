n, L = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
for b in range(L):
    C = []
    for x in A:
        C.append((x - b) % L)
    if sorted(C) == B:
        print('YES')
        exit(0)
print('NO')