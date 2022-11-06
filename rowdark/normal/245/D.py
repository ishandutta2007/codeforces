a = [[0 for i in range(0,1001)]for j in range(1,1000)]
b = [0 for i in range(1,1001)]
n = int(raw_input())
for i in range(1, n + 1):
    s = raw_input()
    m = s.split()
    for j in range(1, n + 1):
        a[i][j] = int(m[j - 1])
        if a[i][j] != -1:
            b[i] |= a[i][j]
            b[j] |= a[i][j]
ans = str(b[1])
for i in range(2, n + 1):
    ans += " " + str(b[i])
print(ans)