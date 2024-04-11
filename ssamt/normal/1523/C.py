t = int(input())
for i in range(t):
    n = int(input())
    l = []
    for j in range(n):
        a = int(input())
        if a != 1:
            while len(l) > 0 and int(l[-1]) != a-1:
                l.pop()
            l.pop()
        l.append(str(a))
        print('.'.join(l))