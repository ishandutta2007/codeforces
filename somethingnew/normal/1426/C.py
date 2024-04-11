import math
def solve():
    n= int(input())
    k = int(math.sqrt(n))
    if k * k == n:
        print(k * 2 - 2)
    elif k * (k + 1) >= n:
        print(k * 2 - 1)
    else:
        print(k * 2)
for i in range(int(input())):
    solve()