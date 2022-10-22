import math

inp = input().split(' ')
t = int(inp[0])
a = int(inp[1])
b = int(inp[2])

if(a == b):
    print("1/1")
    exit(0)

if(a > b):
    a += b
    b = a - b
    a -= b

n = a // math.gcd(a, b) * b

mxk = t // n

ans = min(a, t - mxk * n + 1)

ans += mxk * a - 1

g = math.gcd(ans, t)

print(ans // g, "/", t // g, sep = "")