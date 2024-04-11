for t in range(int(input())):
    l1, r1, l2, r2 = map(int, input().split())
    if l1 != l2:
        print(l1, l2)
    elif l1 != r2:
        print(l1, r2)
    else:
        print(l2, r1)