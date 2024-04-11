t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    h = 1
    flag = True
    for i in range(n):
        if a[i] == 0:
            if i > 0 and a[i - 1] == 0 and flag:
                print(-1)
                flag = False
                break
        else:
            if i > 0 and a[i - 1] == 1:
                h += 5
            else:
                h += 1
    if flag:
        print(h)