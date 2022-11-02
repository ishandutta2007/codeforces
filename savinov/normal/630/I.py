n = int(raw_input())

dp = [1]

for i in xrange(1, 2 * n - 1):
    x = 0
    for j in xrange(1,min(i+1, i+1)):
        if  j == n:
            continue
        if i == j:
            x += 4 *dp[i-j]
        else:
            x += 3 * dp[i-j]
    dp.append(x)

print 4**(2*n-2) - dp[-1]