n, s = map(int, input().split())
if s >= n and s % n != 0:
    print(s//n+1)
elif s % n == 0:
    print(s//n)
else:
    print(1)