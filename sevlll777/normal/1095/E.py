n = int(input())
skobs = input()
cnt9 = 0
fl = 0
cnt0 = 0
cnt10, cnt19 = 0, 0
bz = float("inf")
bz2 = float("-inf")
for y in range(n):
    if skobs[y] == "(":
        cnt9 += 1
    else:
        cnt0 += 1
    if cnt0 - cnt9 > 2:
        fl = 1
    if cnt0 - cnt9 == 1:
        bz = min(bz, y)
for y2 in range(n-1, -1, -1):
    if skobs[y2] == "(":
        cnt19 += 1
    else:
        cnt10 += 1
    if cnt19 - cnt10 > 2:
        fl = 1
    if cnt19 - cnt10 == 1:
        bz2 = max(bz2, y2)
if abs(cnt9-cnt0) != 2 or fl or (bz2 != float("-inf") and bz != float("inf")):
    print(0)
elif bz == float("inf") and bz2 != float("-inf"):
    ww = skobs[bz2:]
    print(ww.count("("))
elif bz2 == float("-inf") and bz != float("inf"):
    ww = skobs[:bz+1]
    print(ww.count(")"))