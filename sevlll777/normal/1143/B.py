def f(n):
    if n < 10:
        return n
    else:
        s = list(str(n))
        s = list(map(int, s))
        q = max(1, (s[0] - 1)) * 9 ** (len(s) - 1)
        w = s[0] * f(n % (10 ** (len(s) - 1)))
        return max(q, w)


print(f(int(input())))