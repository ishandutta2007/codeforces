n = int(input())
A = list(map(int, input().split()))
cnt1, cnt2 = 0, 0
for i in A:
    if i > 0:
        cnt1 += 1
    elif i < 0:
        cnt2 += 1
if cnt1 >= (n + 1) // 2:
    print(1)
elif cnt2 >= (n + 1) // 2:
    print(-1)
else:print(0)