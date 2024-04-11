n,m=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
pref=[0]
ans=0
for i in a:
    pref.append(pref[-1]+i)
for i in range(m):
    k,l=[int(i) for i in input().split()]
    plus=pref[l]-pref[k-1]
    if plus>0:
        ans+=plus
print(ans)