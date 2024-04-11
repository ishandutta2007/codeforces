t = int(input())
for iter in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    
    vis = [0] * n
    ok = True
    
    for i in range(n, 0, -1):
        tmp = False
        for j in range(n): 
            
            if vis[j] == 0:
                x = a[j]
                while x > 0:
                    if x == i: 
                        tmp = True
                        vis[j] = 1
                        break
                    x //= 2
            
            if tmp: break
        ok &= tmp
    print("YES" if ok else "NO")