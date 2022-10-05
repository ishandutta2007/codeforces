for t in range(int(input())):
    n = int(input())
    lst = list(map(int,input().split()))
    goodlst = []
    bolsh = True
    first = True
    for i in lst:
        if first:
            first = False
            goodlst.append(i)
            bolsh = (i>0)
        else:
            if bolsh == (i>0):
                goodlst[-1] = max(goodlst[-1],i)
            else:
                goodlst.append(i)
                bolsh = not bolsh
    print(sum(goodlst))