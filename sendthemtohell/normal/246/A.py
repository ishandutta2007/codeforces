n=int(input())
if n<3:
    print(-1)
else:
    s=[100,2]+[1]*(n-2)
    print(' '.join(map(str,s)))