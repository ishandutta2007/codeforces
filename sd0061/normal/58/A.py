a = raw_input()
b = "hello"
j = 0
for i in range(len(a)):
    if j < 5 and a[i] == b[j]:
        j += 1
if j == 5:
    print "YES"
else:
    print "NO"