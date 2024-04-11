L = list(map(int,input().split()))
L.sort()
print(str(L[3]-L[2]) + ' ' +str(L[3]-L[1]) + ' ' +str(L[3]-L[0]))