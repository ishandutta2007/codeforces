n, k = map(int, input().split())
names = []
for i in range(ord('a'), ord('z') + 1):
    names.append('A' + chr(i))
for i in range(ord('a'), ord('z') + 1):
    names.append('B' + chr(i))
pos = 0
a = input().split()
ans = []
for i in range(k - 1):
    ans.append(names[pos])
    pos += 1
for i in range(n - k + 1):
    if a[i] == "YES":
        ans.append(names[pos])
        pos += 1
    else:
        ans.append(ans[i])
print(' '.join(ans))