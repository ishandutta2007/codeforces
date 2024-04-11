n = int(input())

a = input().split()
b = input().split()

for i in range(n):
    a[i] = int(a[i]) - 1
    b[i] = int(b[i]) - 1

c = [0 for i in range(n)]
for i in range(n):
    c[a[i]] = n - i - 1

s = n
for i in b:
    #print(i)
    #print(s, c[i], i)
    if c[i] < s:
        print(s - c[i], end = ' ')
        s = c[i]
    else :
        print(0, end = ' ')
    #print()