import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    if n % 2:
        print('NO')
        continue
    a.sort()
    ans = []
    for i in range(n // 2):
        ans.append(a[i])
        ans.append(a[n//2 + i])
    for i in range(n):
        if ans[i-1] < ans[i] > ans[(i+1)%n] or ans[i-1] > ans[i] < ans[(i+1)%n]:
            continue
        print('NO')
        break
    else:
        print('YES')
        print(*ans)