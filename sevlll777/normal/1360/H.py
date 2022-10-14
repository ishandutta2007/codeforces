from bisect import bisect_left
for _ in range(int(input())):
    n, m = map(int, input().split())
    A = []
    G = set()
    for __ in range(n):
        kek = int(input(), 2)
        A.append(kek)
        G.add(kek)
    A.sort()
    k = 2**m - n
    k = (k - 1) // 2
    ans = -1
    for num in range(2**(m-1)-2*n-20, 2**(m-1)+2*n+20):
        if 0<=num<2**m:
            lol = num - bisect_left(A, num+1)
            if lol == k and num not in G:
                ans = num
                break
    l = ans
    print(str(bin(l))[2:].zfill(m))