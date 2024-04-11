def gint():
    return list(map(int, input().split()))
    
q, = gint()

for _ in range(q):
    n, = gint()
    arr = gint()
    dic = {}
    for x in arr:
        if x in dic:
            dic[x]+= 1
        else:
            dic[x] = 1
    ret = []
    for x in dic:
        ret.append(dic[x])

    arr = ret
    arr.sort()
    SM = [0]

    n = len(arr)
    for x in arr:
        SM.append(SM[-1] + x)

    S = 0
    ans = 2**50
    for i in range(n):
        S+= arr[i]
        ans = min(ans, SM[-1] - S - arr[i] * (n-i-1) + SM[i])
    print(ans)