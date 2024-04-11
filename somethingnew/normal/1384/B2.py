def solve():
    n, k, l = map(int,input().split())
    dp = [[0, -1] for i in range(n)]
    lst = list(map(int,input().split()))
    dp[0][0] = l - lst[0]
    if dp[0][0] < 0:
        print("NO")
        return 0
    for i in range(1, n):
        if k + lst[i] <= l:
            dp[i] = [k, -1]
            continue
        if dp[i-1][1] == 1:
            if(dp[i-1][0] == k):
                if k - 1 + lst[i] <= l:
                    dp[i] = [k-1,-1]
                    continue
                else:
                    print("NO")
                    return 0
            if dp[i-1][0] + 1 + lst[i] <= l:
                dp[i] = [dp[i-1][0] + 1, 1]
            else:
                print("NO")
                return 0
        else:
            num = l - lst[i]
            if num < 0:
                print("NO")
                return 0
            if num < dp[i-1][0]:
                dp[i][0] = num
            else:
                dp[i][0] = dp[i-1][0] - 1
                if dp[i][0] == 0:
                    dp[i][1] = 1
                elif dp[i][0] == -1:
                    dp[i][0] = 1
                    dp[i][1] = 1
                if dp[i][0] + lst[i] > l:
                    print("NO")
                    return 0

    print("YES")
for i in range(int(input())):
    solve()