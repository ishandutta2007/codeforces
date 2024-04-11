for i in range(int(input())):
    n = int(input()) 
    A = list(map(int, input().split())) 
    d = {0:0,1:0, 2:0} 
    for i in A:
        d[i % 3] += 1
    Z = min(d[1],d[2])
    d[1] -= Z
    d[2] -= Z
    print(d[0] + Z + d[1] // 3 + d[2] // 3)