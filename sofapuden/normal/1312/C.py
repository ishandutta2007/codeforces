def find_heigest(i,y):
    t=0
    k=0
    while (i>=t):
        maxvalue = t
        t = y**k
        k+=1
    return maxvalue


import math
N=int(input())
for i in range(N):
    x,y=map(int,input().split())
    L=list(map(int,input().split()))
    arraywithpowers = []
    key = 0
    t=0
    while(t<len(L)):

        if L[t] != 0:
            if find_heigest(L[t],y) not in arraywithpowers:
                arraywithpowers.append(find_heigest(L[t],y))
                L.append(L[t]-find_heigest(L[t],y))
            elif key == 0:
                print('NO')
                key = 1
        t+=1
    if key == 0:
        print('YES')