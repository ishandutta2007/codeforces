n = int(input())
A = list(map(int, input().split()))
heh = []
for z in range(n-1, -1, -1):
    if A[z] not in heh:
        heh.append(A[z])
heh = heh[::-1]
print(len(heh))
print(' '.join(list(map(str, heh))))