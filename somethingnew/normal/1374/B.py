def deli(n):
    n3 = 0
    n2 = 0
    while n % 3 == 0:
        n //= 3
        n3 += 1
    while n % 2 == 0:
        n //= 2
        n2 += 1
    if n != 1:
        return -1, -1
    else:
        return n2,n3
def solve():
    n = int(input())
    a,b = deli(n)
    if a == -1:
        print(-1)
    elif b < a:
        print(-1)
    else:
        print(b + b - a)

for i in range(int(input())):
    solve()