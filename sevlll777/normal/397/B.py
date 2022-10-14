for i in range(int(input())):
    n, l, r = map(int, input().split())
    if n % l <= (n // l) * (r - l):
        print('Yes')
    else:
        print('No')