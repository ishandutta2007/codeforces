n, c = map(int, input().split())
arr = list(map(int, input().split()))

ans = 1
for i in range(n - 2, -1, -1):
    if arr[i] + c < arr[i+1]:
        break
    ans += 1
print(ans)