for t in range(int(input())):
    n = int(input())
    dct = {}
    lst = list(map(int,input().split()))
    for key in lst:
        dct[key] = dct.get(key, 0) + 1
    print(min(len(dct.keys()), max(dct.values())) - (len(dct.keys()) == max(dct.values())))