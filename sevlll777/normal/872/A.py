n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
for s in range(1, 10):
    if s in A and s in B:
        print(s)
        exit(0)
if 0 in A or 0 in B:
    for s in range(1, 10):
        if s in A or s in B:
            print(s * 10)
            exit(0)
else:
    x = min(A)
    y = min(B)
    x, y = min(x, y), max(x, y)
    print(10 * x + y)