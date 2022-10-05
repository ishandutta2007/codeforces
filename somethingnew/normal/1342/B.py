for t in range(int(input())):
    a = list(input())
    if len(set(a)) == 1:
        print(a[0]*len(a))
    else:
        print('01'*len(a))