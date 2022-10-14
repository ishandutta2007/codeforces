x, d = map(int, input().split())
s = str(bin(x))[2:]
wqa = 1
ans = []
koms = 0
for i in range(len(s)):
    if s[i] == '1':
        for idq in range(len(s) - i - 1):
            ans.append(wqa)
        koms += 1
        wqa += d + 1
for ii in range(koms):
    ans.append(wqa)
    wqa += d
print(len(ans))
print(*ans)