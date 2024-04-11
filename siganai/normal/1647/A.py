import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n = int(input())
    N = n
    ans = []
    st = 2
    while n > 0:
        ans.append(st)
        n -= st
        st = 3 - st
    if sum(ans) == N:
        print(*ans,sep = '')
    else:
        st = 1
        ans = []
        while N > 0:
            ans.append(st)
            N -= st
            st = 3 - st
        print(*ans,sep = '')