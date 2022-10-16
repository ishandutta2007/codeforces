a=input()
b=input()
s=""
n=int(input())
l=""
r=""
flag=0
def match(x,y):
    if len(x)!=len(y) :
        return 0
    for i in range(len(x)):
        if x[i]=='?':
            if y[i] in a:
                continue
            else:
                return 0
        if x[i]!=y[i]:
            return 0
    #print("matches",x,"and",y)
    return 1
def allbad():
    for letter in s[len(l):len(s)-len(r)]:
        if letter in a:
            return 0
    #print("allbad")
    return 1
for i in range(len(b)):
    if b[i]=='*':
        l=b[0:i]
        r=b[i+1:]
        flag=1
        break
for i in range(n):
    s=input()
    if not flag:
        if(len(b)!=len(s)):
            print("NO\n");
        else:
            if match(b,s):
                print("YES\n")
            else:
                print("NO\n")
    else:
        if(len(b)-1>len(s)):
            print("NO\n")
        else:
            #print(len(l),len(s)-len(r))
            l2=s[0:len(l)]
            r2=s[len(s)-len(r):]
            #print('|',l,'|',r,'|',l2,'|',r2,'|')
            if allbad() and match(l,l2) and match(r,r2):
                print("YES\n")
            else:
                print("NO\n")