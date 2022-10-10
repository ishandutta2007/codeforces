for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    mp = {}
    ret = 0
    for i in range(n):
        ret += mp.get(a[i] - i, 0)
        mp[a[i] - i] = mp.get(a[i] - i, 0) + 1
    print(ret)