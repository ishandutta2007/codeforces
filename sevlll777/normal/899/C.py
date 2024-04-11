n = int(input())
if n % 4 == 0:
    print(0)
    ans = []
    x = 1
    for i in range(n // 4):
        ans.append(x)
        ans.append(n + 1 - x)
        x += 1
    print(len(ans), *ans)
elif n % 4 == 1:
    x = 2
    ans = []
    print(1)
    for i in range(n // 4):
        ans.append(x)
        ans.append(n + 2 - x)
        x += 1
    print(len(ans), *ans)
elif n % 4 == 2:
    x = 3
    ans = [2]
    print(1)
    for i in range(n // 4):
        ans.append(x)
        ans.append(n + 3 - x)
        x += 1
    print(len(ans), *ans)
else:
    print(0)
    x = 4
    ans = [3]
    for i in range(n // 4):
        ans.append(x)
        ans.append(n + 4 - x)
        x += 1
    print(len(ans), *ans)