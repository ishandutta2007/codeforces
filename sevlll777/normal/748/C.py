n = int(input())
s = input()
xcnt= 1
what = set()
for i in s:
    if i == 'L' and 'R' in what or i == 'R' and 'L' in what or i == 'U' and 'D' in what or 'D' == i and 'U' in what:
        what = set()
        xcnt += 1
    what.add(i)
print(xcnt)