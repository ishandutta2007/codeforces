n = int(input())

a = input().split()
for i in range(n):
    a[i] = int(a[i])

cnt1 = 0
cnt2 = 0

for i in a:
    if i % 2 == 0:
        cnt1 += 1
    else:
        cnt2 += 1

if cnt2 % 2 == 0:
    print(cnt1)
else:
    print(cnt2)