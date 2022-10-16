from sys import *

s=input()
sf=input()
pair=dict()
abet="abcdefghijklmnopqrstuvwxyz"
for i in range(len(s)):
    if not pair.get(s[i]) and not pair.get(sf[i]):
        pair[s[i]]=sf[i]
        pair[sf[i]]=s[i]
    elif not pair.get(s[i]) or not pair.get(sf[i]):
        print(-1)
        exit(0)
    elif pair[s[i]]!=sf[i] or pair[sf[i]]!=s[i]:
        print(-1)
        exit(0)
ans=[]
for i in abet:
    if pair.get(i) and pair[i] < i:
        ans.append((i,pair[i]))
print(len(ans))
#print(ans)
for i in ans:
    print(i[0],i[1])