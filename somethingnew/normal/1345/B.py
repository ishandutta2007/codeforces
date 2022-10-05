from math import sqrt
for t in range(int(input())):
    k = int(input())
    shag = 0
    while k >= 2:
        n = int(((1/2+sqrt(1/4+6*k))/3))
        while 3*(n*(n+1)//2)-n > k: n-=1
        k -= 3*(n*(n+1)//2)-n
        shag += 1
    print(shag)