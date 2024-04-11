for t in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    b = [(a[i] + i) % n for i in range(n)]
    b.sort()
    if b == list(range(n)):
        print('YES')
    else: print('NO')