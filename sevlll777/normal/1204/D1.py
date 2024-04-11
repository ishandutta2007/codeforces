s = list(map(int, input()))
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
        maba = 0
        b = 0
        for x in range(i, len(s)):
            if s[x] == 1:
                b -= 1
            else:
                b += 1
            maba = max(maba, b)
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