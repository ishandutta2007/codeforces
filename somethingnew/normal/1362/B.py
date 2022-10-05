for t in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    a = set(arr)
    ans = -1
    for i in range(1, 1024):
        b = set()
        for j in range(n):
            b.add(arr[j] ^ i)
        if b == a:
            ans = i
            break
    print(ans)