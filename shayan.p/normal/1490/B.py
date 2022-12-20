def gint():
    return list(map(int, input().split()))
    
INF = 2**60

q, = gint()

for _ in range(q):
    n, = gint()
    c = [0]*3
    inp = gint()
    n = len(inp)
    for x in inp:
        c[x%3]+= 1
    c += c
    def calc(i):
        arr = c[i:i+3].copy()
        if arr[0] < n//3:
            return INF
        tmp1 = arr[0] - (n//3)
        arr[1]+= tmp1
        if arr[1] < n//3:
            return INF
        tmp2 = arr[1] - (n//3)
        return tmp1 + tmp2
    print(int(min(list(map(calc, list(range(3)))))))