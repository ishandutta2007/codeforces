def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    minel = n + 1
    minpos = -1
    maxel = 0
    maxpos = -1
    p = -1
    for i in lst:
        p += 1
        if maxel:
            if i < maxel:
                print("YES")
                print(minpos + 1, maxpos + 1, p + 1)
                return 0
            else:
                maxel = i
                maxpos = p
        else:
            if minel < i:
                maxel = i
                maxpos = p
            else:
                minel = i
                minpos = p
    print("NO")
for i in range(int(input())):
    solve()