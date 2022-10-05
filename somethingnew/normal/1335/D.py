for t in range(int(input())):
    d = [list(input()) for i in range(9)]
    newd = []
    for i in d:
        k = i.index('1')
        i[k//3*3+(k+1)%3] = '1'
        newd.append(i)
    for i in newd:
        print(*i,sep='')