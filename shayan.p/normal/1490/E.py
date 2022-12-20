def gint():
    return list(map(int, input().split()))
    
q, = gint()

for _ in range(q):
    n, = gint()
    arr = gint()
    S = sum(arr)
    LST = max(arr)
    arr = sorted(list(map(lambda x:(x[1], x[0]), list(enumerate(arr)))))
    arr.reverse()
    ans = []
    for i in range(n):
        if S >= LST:
            ans.append(arr[i][1]+1)
        else:
            break
        LST = arr[i][0]
        S-= arr[i][0]
    ans.sort()
    print(len(ans))
    print(*ans)