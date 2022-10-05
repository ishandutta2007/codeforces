for t in range(int(input())):
    n, x = map(int,input().split())
    even = 0
    odd = 0
    for i in list(map(int,input().split())):
        if i % 2:
            odd += 1
        else:
            even += 1
    if odd:
        if odd % 2 == 0:
            odd -= 1
        ans = odd + even
        if ans >= x:
            if x % 2 == 0:
                if even:
                    print("Yes")
                else:
                    print("No")
            else:
                print('Yes')
        else:
            print("No")
    else:
        print("No")