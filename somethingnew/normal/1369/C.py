def solve():
    n, k = map(int,input().split())
    lst1 = list(map(int,input().split()))
    lst1.sort(reverse=True)
    ind = 0
    ans = 0
    lst2 = list(map(int,input().split()))
    lst2.sort()
    for i in range(k):
        lst2[i] -= 1
        if lst2[i] == 0: ans += lst1[ind]
        ans += lst1[ind]
        ind += 1
    lst2.sort()
    for i in lst2:
        if i != 0:
            ind += i - 1
            ans += lst1[ind]
            ind += 1
    print(ans)
for i in range(int(input())):
    solve()