__author__ = 'Alex'
n = int(input())
a = [int(i) for i in input().split()]
cnt1, cnt2 = [0] * 2
ans = []
for i in a:
    if i < 0:
        if cnt2 > 1:
            ans.append(cnt1)
            cnt1 = cnt2 = 0
        cnt2 += 1
    cnt1 += 1
if cnt1 > 0:
    ans.append(cnt1)
print(len(ans))
print(' '.join([str(i) for i in ans]))