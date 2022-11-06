n = int(raw_input())
a = []
s = raw_input().split()
pre = 0
cc = 0
for i in range(0, n):
    if int(s[i]) < 0:
        cc += 1
        if cc == 3:
            a += [i - pre]
            pre = i
            cc = 1
a += [n - pre]
print(len(a))
output = str(a[0])
for i in range(1, len(a)):
    output += ' ' + str(a[i])
print(output)