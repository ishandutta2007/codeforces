n = int(input())
A = list(map(int, input().split()))
lol = {}
for i in range(n):
    lol[i + 1] = A[i]
for k in lol:
    j = lol[lol[k]]
    # k lubit lol[k]
    # lol[k] lubit j
    if lol[j] == k:
        print('YES')
        exit(0)
print('NO')