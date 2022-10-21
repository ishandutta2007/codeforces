

t = int(input())

for T in range(t):
    n, a, b, c, d = map(int, input().split(" "))
    lo = (a-b)*n
    hi = (a+b)*n
    if lo > c+d or hi < c-d:
        print("No")
    else:
        print("Yes")