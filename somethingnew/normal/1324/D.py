def solve():
    n = int(input())
    lst1 = list(map(int,input().split()))
    lst2 = list(map(int, input().split()))
    lst = [lst1[i] - lst2[i] for i in range(n)]
    lst.sort()
    l = 0
    r = n - 1
    ans = 0
    while l != r:
        if lst[l] + lst[r] > 0:
            r -= 1
        else:
            ans += n - r - 1
            l += 1
    print(ans + (n-l)*(n-l-1)//2)
for i in range(1):
    solve()