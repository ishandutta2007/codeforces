def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    dct = dict()
    p = 1
    for i in lst:
        if dct.get(i, False):
            if p - dct[i] > 1:
                print("YES")
                return
        else:
            dct[i] = p
        p += 1
    print("NO")

for i in range(int(input())):
    solve()