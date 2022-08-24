n = int(input())
arr = list(map(int, input().split()))
res = [[], [], []]
for j, i in enumerate(arr):
    if i:
        res[i-1].append(j + 1)

x = min(map(len, res))
print(x)
for i in range(x):
    print(res[0][i], res[1][i], res[2][i])