n, s = map(int, input().split())
kvas = list(map(int, input().split()))
if s > sum(kvas):
    print(-1)
else:
    if s <= sum(kvas) - n*min(kvas):
        print(min(kvas))
    else:
        print(min(kvas) - 1 - (s - sum(kvas) + n*min(kvas) - 1)//n)