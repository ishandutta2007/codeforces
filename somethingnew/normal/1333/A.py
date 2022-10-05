for t in range(int(input())):
    n,m = map(int,input().split())
    if n == 2 and m == 2:
        print('BB')
        print('BW')
    elif n > 2:
        mas = [['B' for i in range(m)] for j in range(n)]
        mas[0][0] = 'W'
        mas[1][0] = 'W'
        for i in mas:
            print(*i,sep='')
    else:
        mas = [['B' for i in range(m)] for j in range(n)]
        mas[0][0] = 'W'
        mas[0][1] = 'W'
        for i in mas:
            print(*i, sep='')