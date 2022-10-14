l, r = map(int, input().split())
if r <= l + 1:
    print(-1)
    exit(0)
elif l % 2 == 0:
    print(l, l + 1, l + 2)
else:
    if r == l + 2:
        print(-1)
    else:
        print(l + 1, l + 2, l + 3)