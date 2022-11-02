t = int(input())
for i in range(t):
    n = int(input())
    a = list(range(1, n+1))
    if n%2 == 1:
        for j in range(0, n-2, 2):
            a[j], a[j+1] = a[j+1], a[j]
        a[-3:] = [n-1, n, n-2]
    else:
        for j in range(0, n, 2):
            a[j], a[j+1] = a[j+1], a[j]
    a = list(map(str, a))
    print(' '.join(a))