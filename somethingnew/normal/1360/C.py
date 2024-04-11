def main():
    n = int(input())
    lst = list(map(int,input().split()))
    lst.sort()
    dp = [0 for i in range(n)]
    for i in range(1, n):
        if lst[i] == lst[i-1] + 1:
            if i >= 2:
                dp[i] = max(dp[i-1], dp[i-2] + 1)
            else:
                dp[i] = 1
        else:
            dp[i] = dp[i-1]
    n1 = 0
    n2 = 0
    for i in lst:
        if i % 2:
            n2 += 1
        else:
            n1 += 1
    if n2%2 + n1%2 <= dp[-1] * 2:
        print("Yes")
    else:
        print("No")
for t in range(int(input())):
    main()