from collections import Counter

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    c = Counter()

    for x in a:
        c[x] += 1
    
    tups = []
    
    for k, v in c.items():
        v = min(v, 2)
        tups.append((k, v))
    
    tups.sort()
    
    a, b = 0, 0
    f = False
    for k, v in tups:
        if v == 2:
            a += 1
            b += 1
        else:
            if not f:
                a += 1
                b += 1
                f = True
            else:
                if a < b:
                    a += 1
                else:
                    b += 1
    
    ans = min(a, b)
    print(ans)