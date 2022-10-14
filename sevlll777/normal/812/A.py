a = []
n = 4
for i in range(4):
    temp = list(map(int,input().split()))
    a.append(temp)
cnt = True

if a[0][3] == 1:
        if a[0][0] == 1 or a[0][1] == 1 or a[0][2] == 1 or a[1][0] == 1 or a[2][1] == 1 or a[3][2] == 1:
            cnt = False
if a[1][3] == 1:
        if a[1][0] == 1 or a[1][1] == 1 or a[1][2] == 1 or  a[0][2] == 1 or a[2][0] == 1 or a[3][1] == 1:
            cnt = False
if a[2][3] == 1:
        if a[2][0] == 1 or a[2][1] == 1 or a[2][2] == 1 or a[0][1] == 1 or a[1][2] == 1 or a[3][0] == 1:
            cnt = False
if a[3][3] == 1:
        if a[3][0] == 1 or a[3][1] == 1 or a[3][2] == 1 or a[0][0] == 1 or a[1][1] == 1 or a[2][2] == 1:
            cnt = False

if cnt == False:
    print("YES")
else:
    print("NO")