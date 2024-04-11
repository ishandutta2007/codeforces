def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    c = lst[0] % 2
    for i in lst:
        if i % 2 != c:
            print("NO")
            return 
    print("YES")
    
for i in range(int(input())):
    solve()