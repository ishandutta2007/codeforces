p = input().split()
p = set(p)
ans = 2
lol = [0] * 3
for i1 in p:
    for i2 in p:
        if i1[1] == i2[1] and 1 <= int(i1[0]) - int(i2[0]) <= 2:
            if int(i1[0]) - int(i2[0]) == 1:
                lol[1] += 1
            else:
                lol[2] = 1
ans -= max(lol)
ans = min(ans, len(p) - 1)
print(max(0, ans))