n = int(input())
A = list(map(int, input().split()))
q = -2
kek = {ww - 1: 0 for ww in set(A)}
for elemq in range(n):
    elem = A[elemq]
    kek[elem] = 1
    if not kek[elem - 1] and elem != 0:
        q = elemq
        break
print(q + 1)