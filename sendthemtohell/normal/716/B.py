def good(s):
    f=dict()
    for i in s:
        if f.get(i):
            return False
        if i!="?":
            f[i]=1
    return True

def fix(s):
    f=dict()
    for i in s:
        if i!="?":
            f[i]=1
    ans=""
    e="A"
    for i in s:
        if i!="?":
            ans+=i
        else:
            while f.get(e):
                e=chr(ord(e)+1)
            ans+=e
            e=chr(ord(e)+1)
    return ans

def gog(s):
    a=""
    for i in s:
        if i!="?":
            a+=i
        else:
            a+="A"
    return a

s=input()
gg=-1
for i in range(0,len(s)-25):
    if(good(s[i:i+26])):
        gg=i
        break
if gg>=0:
    ans=gog(s[:i])+fix(s[i:i+26])+gog(s[i+26:])
else:
    ans=-1
print(ans)