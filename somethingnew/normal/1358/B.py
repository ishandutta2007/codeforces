for t in range(int(input())):
    n = int(input())
    lst = list(map(int, input().split()))
    lst.sort()
    num = 1
    ans = 1
    for i in lst:
        num += 1
        if num > i:
            ans = num
    print(ans)