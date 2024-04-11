def ms(n):
    if n == 1:
        print(1, end=' ')
        return 0
    if n % 2:
        ms(n-1)
        print(n,end=' ')
    else:
        print(n,end=' ')
        ms(n-1)
def solve():
   n = int(input())
   ms(n)
   print()
for i in range(int(input())):
    solve()