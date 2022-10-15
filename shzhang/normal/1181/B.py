l = int(input())
n = input()
pos = []
bestdiff = 100000000
for i in range(l-1):
    if n[i+1] != "0":
        pos.append(i)
        bestdiff = min(bestdiff, max(i+1, l-i-1))
ans = []
for i in pos:
    if max(i+1, l-i-1) == bestdiff:
        ans.append(int(n[:i+1]) + int(n[i+1:]))
print(min(ans))