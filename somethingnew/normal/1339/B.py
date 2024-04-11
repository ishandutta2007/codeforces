for t in range(int(input())):
    n = int(input())
    lst = list(map(int,input().split()))
    lst.sort()
    lstmin = lst[n//2:][::-1]
    lstmax = lst[:n//2]
    ans =[]
    if n % 2:
        ans += [lstmin[0]]
        for i in range(len(lstmax)):
            ans += [lstmax[i],lstmin[i+ 1]]
    else:
        for i in range(len(lstmin)):
            ans += [lstmin[i], lstmax[i]]
    print(*ans[::-1])