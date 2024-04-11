n,l,k = [int(i) for i in input().split()]
k -= 1
s = sorted(input(),reverse=True)
#print(s)

m = [[-1 for j in range(l)] for i in range(n)]

i = 0
j = 0
min_i = 0
last_c = '0'
done = -1
while len(s)>0:
    c = s.pop()
    #print(i,j,c)
    m[i][j] = c
    if c != last_c:
        min_i = i
        last_c = c
    if i<k:
        i += 1
    else:
        if j==l-1:
            break
        j += 1
        i = min_i

for i in range(n):
    for j in range(l):
        if m[i][j] == -1:
            m[i][j] = s.pop()
for i in m:
    print(''.join(i))