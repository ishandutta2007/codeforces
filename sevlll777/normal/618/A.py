dp = [[1]]
for i in range(2, 20):
    heh = []
    for elem in dp:
        x = [i] + elem
        heh.append(x)
    dp.append([i])
    dp += heh
print(*dp[int(input()) - 1])