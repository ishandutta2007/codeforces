import re

n = int(input())
s = input()
l = re.split(r"\.|\?|\!", s)
r = [len(x.strip())+1 for x in l if len(x.strip())>0]
if max(r)>n:
    print("Impossible")
else:
    cur = -1
    ans = 1
    for i in r:
        if cur+i+1<=n:
            cur=cur+i+1
        else:
            ans=ans+1
            cur=i
    print(ans)