n, m = map(int, input().split())
for i in range(m):
    qq = list(map(int, input().split()))
    qq = qq[1:]
    aaa = len(set(qq))
    qq = list(map(abs, qq))
    if aaa == len(set(qq)):
        print('YES')
        exit(0)
print('NO')