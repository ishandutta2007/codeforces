def psums(a):
    b = [a[0] for i in range(len(a))]
    for i in range(1, len(a)):
        b[i] = b[i-1] + a[i]
    return b

t = int(input())
for tc in range(t):
    n, x = map(int, input().split())
    w = [*map(int, input().split())]
    w = sorted(w)
    ps = psums(w)
    if ps[-1] == x:
        print("NO")
        continue

    if x in ps:
        i = ps.index(x)
        w[i], w[i+1] = w[i+1], w[i]

    print("YES")
    print(*w)