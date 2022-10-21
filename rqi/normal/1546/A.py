t = int(input())

for T in range(t):
    n = int(input())
    a = input().split(" ")
    b = input().split(" ")

    for i in range(len(a)):
        a[i] = int(a[i])
    for i in range(len(b)):
        b[i] = int(b[i])

    opers = []
    while True:
        foundBig = -1
        foundSmall = -1
        for i in range(n):
            if a[i] > b[i]:
                foundBig = i
            elif a[i] < b[i]:
                foundSmall = i
        if foundBig != -1 and foundSmall != -1:
            a[foundBig]-=1
            a[foundSmall]+=1
            opers.append([foundBig, foundSmall])
        else:
            break
    if a == b:
        print(len(opers))
        for o in opers:
            print(o[0]+1, o[1]+1)
    else:
        print(-1)