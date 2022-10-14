n = int(input())
if n == 1:
    print(0)
    exit(0)
s = input()
K = []
lc = s[0]
cnt = 0
for i in s:
    if i == lc:
        cnt += 1
    else:
        K.append(cnt)
        cnt = 1
    lc = i
K.append(cnt)
bad = 3 * n - K[0] - K[-1] - (len(K) - 1)
print(n * (n + 1) // 2 - bad)