s = list(map(int, input()))
ps = [0]
for i in s:
    if i == 0:
        ps.append(ps[-1] + 1)
    else:
        ps.append(ps[-1] - 1)
b = 0
maba = 0
sufmax = [-10 ** 9]
for i in range(len(ps) - 1, 0, -1):
    sufmax.append(max(sufmax[-1], ps[i]))
sufmax = sufmax[::-1]
ans = []
cnt = 0
if s[0] == 1:
    cnt += 1
else:
    ans.append('0')
for i in range(1, len(s)):
    if s[i] == 0 and s[i - 1] == 0:
        ans.append('0')
    elif s[i] == 1:
        cnt += 1
    else:
        maba = sufmax[i] - ps[i]
        maba = min(maba, cnt)
        for _ in range(cnt - maba):
            ans.append('0')
        for _ in range(maba):
            ans.append('1')
        cnt = 0
        ans.append('0')
for _ in range(len(s) - len(ans)):
    ans.append('0')
print(''.join(ans))