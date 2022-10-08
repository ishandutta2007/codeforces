s=raw_input()
n=len(s)
f=[0]*n
g=[0]*n
'''
AB->BA
No Other AB
'''
# 0=A
f[0]=1
for i in xrange(0,n-1):
    if (s[i]=='A') and (s[i+1]=='A'):
        f[i+1]+=g[i]
        f[i+1]+=f[i]
    if (s[i]=='A') and (s[i+1]=='B'):
        f[i+1]+=f[i]
        f[i+1]+=g[i]
        g[i+1]+=g[i]
    if (s[i]=='B') and (s[i+1]=='A'):
        g[i+1]+=f[i]
        f[i+1]+=g[i]
    if (s[i]=='B') and (s[i+1]=='B'):
        f[i+1]+=g[i]
        g[i+1]+=g[i]
ans=0
if s[n-1]=='B':
    ans+=g[n-1]
else:
    ans=f[n-1]+g[n-1]
f=[0]*n
g=[0]*n
# 0=B
g[0]=1
for i in xrange(0,n-1):
    if (s[i]=='A') and (s[i+1]=='A'):
        f[i+1]+=g[i]
        f[i+1]+=f[i]
    if (s[i]=='A') and (s[i+1]=='B'):
        f[i+1]+=f[i]
        f[i+1]+=g[i]
        g[i+1]+=g[i]
    if (s[i]=='B') and (s[i+1]=='A'):
        g[i+1]+=f[i]
        f[i+1]+=g[i]
    if (s[i]=='B') and (s[i+1]=='B'):
        f[i+1]+=g[i]
        g[i+1]+=g[i]
if (s[0]=='A') and (s[n-1]=='B'):
    ans+=f[n-1]
elif (s[0]=='B'):
    ans+=g[n-1]
print ans