for t in range(int(input())):
    x,n,m = map(int,input().split())
    ans = 10 * m
    if m == 0:
        print('NO')
    elif m == 1:
        if x > ans:
            print('NO')
        else:
            print("YES")
    else:
        for i in range(n):
            ans -= 10
            ans *= 2
            ans += 1
        if ans >= x:
            print('YES')
        else:
            print('NO')