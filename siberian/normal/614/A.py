a = input().split()
l = int(a[0])
r = int(a[1])
k = int(a[2])
ans = []
pos = 1;
while pos <= r:
    if pos >= l and pos <= r:
        ans.append(str(pos))
    pos = pos * k
if len(ans) == 0:
    ans.append("-1")
print(" ".join(ans))