n = int(input())
downs = []
ups = []
for i in range(n):
    a, b = map(int, input().split())
    if a < b:
        ups.append([a, b, i + 1])
    else:
        downs.append([a, b, i + 1])
if len(ups) >= len(downs):
    ups.sort(key=lambda x: x[0], reverse=True)
    ans = []
    for a, b, i in ups:
        ans.append(i)
    print(len(ans))
    print(*ans)
else:
    downs.sort(key=lambda x: x[1])
    ans = []
    for a, b, i in downs:
        ans.append(i)
    print(len(ans))
    print(*ans)