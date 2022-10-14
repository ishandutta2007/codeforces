n, m, k = map(int, input().split())
A = list(map(int, input().split()))
gal = A[-1] - A[0]
h = []
for z in range(1, n):
    h.append(A[z] - A[z - 1])
print(gal - sum(sorted(h, reverse=True)[:k-1]) + k)