from math import ceil, log
for t in range(int(input())):
    izm = 0
    lastizm = 0
    n = int(input())
    lst = list(map(int,input().split()))
    for i in range(n-1):
        izm = max(izm, lst[i] - lst[i+1])
        lst[i + 1] = max(lst[i],lst[i+1])
    if izm == 0:
        print(0)
    else:
        print(int(log(izm*2,2)))