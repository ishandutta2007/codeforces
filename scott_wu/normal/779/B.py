a, b = raw_input().split()
b = int(b)

cc = 0
for i in range(len(a)):
    if a[len(a)-i-1] == '0':
        cc += 1
    if cc == b:
        print (i - b + 1)
        break

if cc < b:
    print (len(a) - 1)