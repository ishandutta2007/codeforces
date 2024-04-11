def main():
    n,k = map(int, input().split())
    lst = list(input())
    dp = [0 for i in range(n + 1)]
    bnx = 0
    for i in range(1, n + 1):
        if bnx:
            bnx -= 1
            dp[i] = dp[i-1]
            if lst[i-1] == "1":
                bnx = k
        else:
            if lst[i-1] == "1":
                bnx = k
                try:
                    dp[i] = dp[i-k-1]
                except:
                    dp[i] = 0
            else:
                try:
                    dp[i] = max(dp[i-1], dp[i-k-1]+1)
                except:
                    dp[i] = dp[i-1]
    print(dp[-1])
for t in range(int(input())):
    main()