dct = {1 : 0, 2 : 1, 3 : 2}
def solve():
    a,b,c = map(int,input().split())
    lst = [[a,0],[b,1],[c,2]]
    lst.sort(reverse=True)
    if lst[0][0] == lst[1][0]:
        ans = [lst[2][0],lst[2][0],lst[2][0]]
        ans[dct[lst[0][1] + lst[1][1]]] = lst[0][0]
        print("YES")
        print(*ans)
    else:
        print("NO")
for i in range(int(input())):
    solve()