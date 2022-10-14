n = int(input())
A = list(map(int, input().split()))
one = [0]
two = [0]
for i in A:
    one.append(one[-1])
    two.append(two[-1])
    if i == 1:
        one[-1] += 1
    else:
        two[-1] += 1
rdp1 = [[1] * n for _ in range(n)]
rdp2 = [[1] * n for _ in range(n)]
for l in range(n):
    for r in range(l + 1, n):
        if A[r] == 2:
            rdp1[l][r] = rdp1[l][r - 1] + 1
        else:
            if rdp1[l][r - 1] == one[r] - one[l]:
                rdp1[l][r] = rdp1[l][r - 1] + 1
            else:
                rdp1[l][r] = rdp1[l][r - 1]
        if A[r] == 1:
            rdp2[l][r] = rdp2[l][r - 1] + 1
        else:
            if rdp2[l][r - 1] == two[r] - two[l]:
                rdp2[l][r] = rdp2[l][r - 1] + 1
            else:
                rdp2[l][r] = rdp2[l][r - 1]
dp = [0] * n
dp[0] = 1
for i in range(1, n):
    if A[i] == 2:
        dp[i] = dp[i - 1] + 1
    else:
        if dp[i - 1] == one[i]:
            dp[i] = dp[i - 1] + 1
        else:
            dp[i] = dp[i - 1]
    dp[i] = max(dp[i], rdp2[0][i])
    for j in range(i):
        if rdp1[0][j] == one[j + 1]:
            dp[i] = max(dp[i], rdp1[0][j] + rdp2[j + 1][i])
        dp[i] = max(dp[i], rdp1[0][j] + two[i + 1] - two[j + 1])
print(dp[-1])