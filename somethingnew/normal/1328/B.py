from math import sqrt
for i in range(int(input())):
    n,k = map(int,input().split())
    pos1 = int((sqrt(1 + k * 8)-1)/2)
    pos2 = k - ((pos1 - 1) * pos1) // 2 - 1
    while pos2 >= pos1:
        pos1 += 1
        pos2 = k - ((pos1 - 1) * pos1) // 2 - 1
    ans = ['a'] * n
    ans[pos1] = 'b'
    ans[pos2] = 'b'
    print(*ans[::-1], sep='')