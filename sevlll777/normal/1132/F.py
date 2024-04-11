

def solve(l,r):
    if(l>r): return 0
    if(l == r): return 1
    if(dp[l][r] != -1): return dp[l][r]
    ans = solve(l+1,r)+1
    for i in range(l+1,r+1):
        if(s[i]==s[l]): ans = min(ans , solve(l+1,i-1)+solve(i,r))
    dp[l][r] = ans
    return ans

def F():
    n = int(input())
    global s;
    s = input()

    global dp;
    dp = [[-1]*n for _ in range(n)]
    ans = solve(0,n-1)

    print(ans)
F()