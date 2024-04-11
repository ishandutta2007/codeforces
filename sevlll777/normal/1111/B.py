n, k, m = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
hau = sum(A)
heks = (sum(A) + min(m, n*k)) / n
for i in range(n - 1):
    if m > 0:
        m -= 1
        hau -= A[i]
        heks = max(heks, (hau + min(m, (n - 1 - i) * k)) / (n - i - 1))
print(heks)