import sys
l=[]
for i in range(1,101):
    l.append(i)
g=[]
h=[]
for i in range(101,16000):
    t=[]
    for j in l:
        if j^i in t or j^i in h:
            break
        else:  
            t.append(j^i)
            h.append(j^i)

    if(len(t)==100): g.append(i)
    if(len(g)==100): break
print("?",end=" ")
print(*l)
sys.stdout.flush()
c =int(input())
print("?",end=" ")
print(*g)
sys.stdout.flush()
d=int(input())
a=0
b=0
for  i in l:
    for j in g:
        if(j^i==c^d):
            a=i
            b=j
            break
print("!",end=" ")
print(c^a)
sys.stdout.flush()