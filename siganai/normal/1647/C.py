import sys
input=sys.stdin.readline

def solve(n,m):
    if table[0][0]:
        print(-1)
        return
    ans = []
    for i in range(n)[::-1]:
        for j in range(m)[::-1]:
            if table[i][j]:                
                if i > 0:
                    ans.append([i,j+1,i+1,j+1])
                elif j > 0:
                    ans.append([i+1,j,i+1,j+1])
    print(len(ans))
    for a,b,c,d in ans:
        print(a,b,c,d)
    return
t = int(input())
for _ in range(t):
    n,m=map(int,input().split())
    table = [list(map(int,input().rstrip())) for _ in range(n)]
    solve(n,m)