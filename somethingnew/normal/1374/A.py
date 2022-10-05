def solve():
    x,y,n = map(int,input().split())
    r = n - y
    r = r // x * x
    print(r + y)
    
for i in range(int(input())):
    solve()