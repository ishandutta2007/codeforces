def nd(lst,num, prc):
    dp = [0 for i in range(len(lst))]
    dp[0] = int(lst[0] <= prc)
    for i in range(1, len(lst)):
        if lst[i] > prc:
            dp[i] = dp[i-1]
        else:
            if i >= 2:
                dp[i] = max(dp[i-1], dp[i-2] + 2)
            else:
                dp[i] = 2
    return max(dp[-1], dp[-2] + 1) >= num
n, k = map(int,input().split())
lst = list(map(int,input().split()))
l = min(lst)
r = max(lst)
while (r-l) > 1:
    m = (l + r) // 2
    if nd(lst,k, m):
        r = m
    else:
        l = m
if nd(lst,k, l):
    print(l)
else:
    print(r)