maxx = 0
n = int(input())
lst = list(map(int, input().split()))
newlst = []
for i in lst:
    newlst.append(i + maxx)
    maxx = max(maxx, i + maxx)
print(*newlst)