for i in range(int(input())):
    n = int(input())
    lst = map(int,input().split())
    lst1 = []
    lst2 = []
    ind = 1
    for i in lst:
        if i % 2:
            lst1.append(ind)
        else:
            lst2.append(ind)
        ind += 1
    if len(lst2)%2:
        lst2.pop()
        lst1.pop()
    else:
        if lst1:
            lst1.pop()
            lst1.pop()
        else:
            lst2.pop()
            lst2.pop()
    for i in range(0, len(lst1), 2):
        print(lst1[i], lst1[i+1])
    for i in range(0, len(lst2), 2):
        print(lst2[i], lst2[i+1])