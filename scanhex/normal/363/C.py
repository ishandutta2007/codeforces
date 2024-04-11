__author__ = 'Alex'
s = input().strip()
cur = '#'
cnt = 0
pd = False
ans = []
for x in s:
    if x != cur:
        cnt = 0
        cur = x
    cnt += 1
    if cnt == 3:
        cnt -= 1
    else:
        ans.append(x)
cur = '#'
cnt = 0
s = ans
ans = []
for x in s:
    if x != cur:
        if cnt != 2:
            pd = False
        cnt = 0
        cur = x
    cnt += 1
    if not (cnt == 2 and pd):
        ans.append(x)
    else:
        pd = False
        cnt -= 1
    if cnt == 2 and not pd:
        pd = True
print(''.join(ans))