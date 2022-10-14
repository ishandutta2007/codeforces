for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    z = []
    for i in range(n):
        if s[i] == '0':
            z.append(i)
    x = 0
    j = 0
    ans = ''
    while j < len(z):
        if x + z[j] - j <= k:
            x += z[j] - j
        else:
            break
        j += 1
    if j == len(z):
        print('0' * len(z) + '1' * (n - len(z)))
    else:
        t = '0' * j + '1' * (z[j] - j - (k - x)) + '0' + '1' * (k - x) + s[z[j]+1:]
        print(t)