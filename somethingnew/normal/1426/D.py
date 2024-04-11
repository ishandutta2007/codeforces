n = int(input())
lst = list(map(int,input().split()))
pref = dict()
sum = lst[0]
pref[lst[0]] = 1
pref[0] = 1
res = 0
for r in range(1, n):
    sum += lst[r]
    if pref.get(sum, 0):
        pref = dict()
        pref[0] = 1
        res += 1
        sum = lst[r]
    pref[sum] = 1
print(res)