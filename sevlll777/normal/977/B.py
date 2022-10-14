n = int(input())
s = input()
mek = {}
for i in range(1, n):
    if (s[i]+s[i-1]) in mek:
        mek[(s[i]+s[i-1])] += 1
    else:
        mek[(s[i] + s[i - 1])] = 1
he, zz=0, 0
for j in mek:
    if mek[j] > he:
        he = mek[j]
        zz = j
print(zz[1] + zz[0])