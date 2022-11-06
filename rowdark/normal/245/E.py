s = raw_input()
ans = 0
nans = 0
fans = 0
for i in s:
    if i == '-':
        ans -= 1
        if nans > ans: nans = ans
    else:
        ans += 1
        if fans < ans: fans = ans
print(fans - nans)