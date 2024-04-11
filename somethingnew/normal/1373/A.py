def solve():
    a,b,c = map(int,input().split())
    if a < c:
        print(1,end=" ")
    else:
        print(-1,end=" ")
    if a* b > c:
        print(b)
    else:
        print(-1)
for i in range(int(input())):
    solve()