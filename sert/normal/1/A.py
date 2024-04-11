n, m, a = raw_input().split(" ")
n = int(n)
m = int(m)
a = int(a)
n += a - 1
m += a - 1
ans = (n // a) * (m // a)
print (ans)