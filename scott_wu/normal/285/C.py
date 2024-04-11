n = int(input())
arr = sorted(list(map(int, input().split())))

ans = 0
for i in range(n):
    ans += abs (arr[i] - i - 1)
print (ans)