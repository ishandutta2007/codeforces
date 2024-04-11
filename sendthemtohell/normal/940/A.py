n,d = (int(z) for z in input().split())
arr = [int(z) for z in input().split()]
arr.sort()
mx = -1
for i in range(n):
    for j in range(i, n):
        if arr[j] - arr[i] <= d:
            mx = max(mx, j - i + 1)
print(n - mx)