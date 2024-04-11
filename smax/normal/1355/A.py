def prod(x):
    x = [int(i) for i in list(str(x))]
    return min(x) * max(x)

t = int(input())
for _ in range(t):
    a, k = map(int, input().split())
    for i in range(k - 1):
        add = prod(a)
        if add == 0:
            break
        a += add
    print(a)