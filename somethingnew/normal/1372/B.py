from math import sqrt
def solve():
    n = int(input())
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            x = n // i
            print(x, x * (i-1))
            return 
    print(n-1,1)
for i in range(int(input())):
    solve()