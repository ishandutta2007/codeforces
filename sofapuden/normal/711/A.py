N = int(input())
x = 0
L = []
for i in range(N):
    tmps = str(input())
    tmp = []
    for i in tmps:
        tmp.append(i)
    if(x == 0):
        if(tmp[0] == 'O' and tmp[1] == 'O'):
            tmp[0] = "+"
            tmp[1] = "+"
            x = 1
        elif(tmp[3]  == 'O' and tmp[4] == 'O'):
            tmp[4] = "+"
            tmp[3] = "+"
            x = 1
    L.append(tmp)
if(x == 0):
    print('NO')
else:
    print('YES')
    for i in range(N):
        print(*L[i], sep = "")