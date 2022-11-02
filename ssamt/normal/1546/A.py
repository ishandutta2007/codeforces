t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    if sum(a) == sum(b):
        a_idx = []
        b_idx = []
        for j in range(n):
            for k in range(a[j]):
                a_idx.append(j)
        for j in range(n):
            for k in range(b[j]):
                b_idx.append(j)
        print(len(a_idx))
        for j in range(len(a_idx)):
            print(a_idx[j]+1, b_idx[j]+1)
    else:
        print(-1)