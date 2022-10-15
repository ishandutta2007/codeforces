##n = int(input())
##s = input()
##A = list(map(int, input().split()))
n, m = map(int, input().split())
if m - n < 2:
    print(-1)
else:
    if n % 2 == 0:
        print(n, n+1, n+2)
    else:
        if m -n < 3:
            print(-1)
        else:
            print(n+1, n+2, n+3)