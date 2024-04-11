n = int(raw_input())
ans = 0;
a = raw_input().split(' ');
mx = int(a[0])
mn = int(a[0])
for i in range(n):
    if int(a[i]) > mx:
        mx = int(a[i])
        ans += 1
    if int(a[i]) < mn:
        mn = int(a[i])
        ans += 1

print ans