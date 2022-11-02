a = input()
s = list(input())
for i in range(len(s)):
    s[i] = int(s[i])

x0 = 0
for i in range(10000):

    x0 = 0
    flag = True
    ch = 0
    for j in s:
        x0 += j
        if x0 == i:
            x0 = 0
            ch += 1
        if x0 > i:
            flag = False
            break
    if x0 != 0:
        flag = False
    if ch < 2:
        flag = False
    if flag:
        print("Yes")
        break
if flag == False:
    print("NO")