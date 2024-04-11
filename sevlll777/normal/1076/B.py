n = int(input())
if n % 2 == 0:
    print(n//2)
else:
    fl = 1
    for u in range(2, int((n+1)**0.5)+2):
        if n%u == 0:
            print(1+(n-u)//2)
            fl = 0
            break
    if fl:
        print(1)