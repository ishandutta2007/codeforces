from sys import *

#def mask(a):
#   res1=''
#   while a>0:
#       p=(a%10)%2
#       res1+=str(p)
#       a//=10
#   res1+='0'*(18-len(res1))
#   return res1[::-1]

odd=set(["1","9","3","5","7"])

def mask(a):
    res="0"*(18-len(a))
    for i in a:
        if i in odd:
            res+="1"
        else:
            res+="0"
    return res

di=dict()
t=int(stdin.readline())
for i in range(t):
    s=stdin.readline().split()
    if s[0]=='+':
        w=mask(s[1])
        if di.get(w,-1)==-1:
            di[w]=1
        else:
            di[w]+=1
    if s[0]=='-':
        w=mask(s[1])
        di[w]-=1
    if s[0]=='?':
        w=mask(s[1])
        if di.get(w,-1)==-1:
            print('0')
        else:
            print(di[w])