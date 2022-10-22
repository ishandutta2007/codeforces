n = int(raw_input())
a = [0 , 0 , 0]
t = [0 , 0 , 0]
for i in range(n):
    b = raw_input().split(' ')
    for j in range(3):
        a[j] += int(b[j])
if a == t:
    print "YES"
else:
    print "NO"