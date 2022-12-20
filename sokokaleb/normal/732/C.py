arr = map(int, raw_input().split(' '))

ans = 10 ** 100

day = max(arr)

comb = [[0, 0, 0], [0, 0, -1], [0, -1, -1], [-1, 0, 0], [-1, -1, 0], [0, -1, 0], [-1, 0, -1]]

for aug in xrange(2):
    for item in comb:
        ok = True
        tmp = 0
        for i in xrange(3):
            ok = ok and (arr[i] <= item[i] + day + aug)
            tmp += item[i] + day + aug - arr[i]
        if ok: ans = min(ans, tmp)

print ans