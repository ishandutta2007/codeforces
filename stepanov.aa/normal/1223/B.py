for c in range(int(input())):
    s = set(list(input()))
    t = set(list(input()))
    if s.intersection(t):
        print('YES')
    else:
        print('NO')