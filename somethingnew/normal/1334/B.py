for t in range(int(input())):
    n, x= map(int,input().split())
    lst = list(map(int,input().split()))
    howbolsh = 0
    sumbolsh = 0
    ans = 0
    mensh = []
    for i in lst:
        if i > x:
            howbolsh += 1
            sumbolsh += i
        elif i == x:
            ans += 1
        else:
            mensh.append(i)
    mensh.sort(reverse=True)
    k = 0
    perex = x * howbolsh
    while k < len(mensh) and perex < sumbolsh:
        if mensh[k] + sumbolsh >= perex + x:
            sumbolsh += mensh[k]
            perex += x
            howbolsh += 1
            k += 1
        else:
            break
    print(ans + howbolsh)