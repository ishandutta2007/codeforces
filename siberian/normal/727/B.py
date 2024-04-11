arr = ['1','2','3','4','5','6','7','8','9','0','.']
a = list(input())
s = []
x = ""
for i in a:
    if not (i in arr):
        if x != "":
            y = int("".join(x.split(".")))
            if len(x) < 3:
                y*=100
            elif x[-3] != '.':
                y*=100
            s.append(y)
            x = ""
    else:
        x += i
if x != "":
    y = int("".join(x.split(".")))
    if len(x) < 3:
        y*=100
    elif x[-3] != '.':
        y*=100    
    s.append(y)
    x = ""

ans = 0
for i in s:
  #  print(i)
    ans+=i
ans = str(ans)
res = []
p = ""

for i in range(len(ans)-1, -1, -1):
    p += ans[i]
#print(p)
if len(p) < 3:
    if len(p) < 2:
        print("0.0" + str(p))
    else:
        print("0." + p[1] + p[0])
else:
    res = []
    if (p[0] != "0" or p[1] != "0"):
        res.append(p[0])
        res.append(p[1])
        res.append(".")
    x = 0
    for i in range(2, len(p)):
        x+=1
        res.append(p[i])
        if not (i == len(p)-1) and x % 3 == 0:
            res.append(".")
    #print("".join(res))
    res = "".join(res)
    ans = ""
    for i in range(len(res)):
        ans += res[-i-1]
    print(ans)