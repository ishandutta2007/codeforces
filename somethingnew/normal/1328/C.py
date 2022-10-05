for i in range(int(input())):
    n = int(input())
    nummax = ''
    nummin = ''
    tr = False
    lst = list(input())
    for i in lst:
        if i == '2':
            if tr:
                nummax += '0'
                nummin += '2'
            else:
                nummin += '1'
                nummax += '1'
        elif i == '1':
            if tr:
                nummax += '0'
                nummin += '1'
            else:
                nummax += '1'
                nummin += '0'
                tr = True
        else:
            nummin += '0'
            nummax += '0'
    print(nummax)
    print(nummin)