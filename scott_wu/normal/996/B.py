n = int(input())
arr = map(int, raw_input().split())
res = []
for i in range(n):
    c = max (0, arr[i] - i + n - 1)
    res.append(c//n)

x = min(res)
for i in range(n):
    if res[i] == x:
        print(i+1)
        break