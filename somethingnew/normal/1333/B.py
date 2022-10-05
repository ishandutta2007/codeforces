for t in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    helppl = [False] * n
    helpmin = [False] * n
    helppl[0] = a[0]==1
    helpmin[0] = a[0]==-1
    for i in range(1,n):
        helppl[i] = helppl[i-1] or a[i] == 1
        helpmin[i] = helpmin[i - 1] or a[i] == -1
    tr = True
    if a[0] != b[0]:
        tr = False
    for i in range(1, n):
        if b[i] - a[i] > 0:
            if not helppl[i-1]:
                tr = False
        elif b[i] - a[i] < 0:
            if not helpmin[i-1]:
                tr = False
    if tr:
        print('YES')
    else:
        print('NO')