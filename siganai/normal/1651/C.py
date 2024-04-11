import sys
input=sys.stdin.readline
INF = 1 << 31
t=int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    mina0 = INF;mina1 = INF;minb0 = INF;minb1 = INF
    for bb in b:
        mina0 = min(mina0,abs(a[0] - bb))
        mina1 = min(mina1,abs(a[-1] - bb))
    for aa in a:
        minb0 = min(minb0,abs(b[0] - aa))
        minb1 = min(minb1,abs(b[-1] - aa))
    ans = min(mina0 + mina1 + minb0 + minb1,mina0 + minb0 + abs(a[-1] - b[-1]),mina1 + minb1 + abs(a[0] - b[0]),abs(a[0] - b[0]) + abs(a[-1] - b[-1]))
    ans = min(ans,abs(a[0] - b[-1]) + abs(a[-1] - b[0]),mina0 + minb1 + abs(a[-1] - b[0]),mina1 + minb0 + abs(a[0] - b[-1]))
    print(ans)