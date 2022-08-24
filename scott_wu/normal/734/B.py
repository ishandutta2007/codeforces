a, b, c, d = map(int, input().split())
x = min(a, c, d)
print(x*256+32*min(b, a-x))