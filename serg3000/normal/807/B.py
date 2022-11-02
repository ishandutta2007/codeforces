p,x,y=map(int,input().split())
r=x
z=0
m=0
c=-1
a=[0]*25
while r >= y:
    s = x - z*50
    i = (s // 50) % 475
    for q in range(25):
        i =(i * 96 + 42) % 475
        a[q]=26 + i
        
    r-=50
    z+=1
    for i in range(25):
        if a[i]==p:
            c=0
            m=1
if c!=0:
    c=0
    while m!=1:
        c+=1
        s = x - 50 + c*100
        i = (s // 50) % 475
        for q in range(25):
            i =(i * 96 + 42) % 475
            a[q]=26 + i
        for i in range(25):
            if a[i]==p:
                m=1
        s = x + c*100
        i = (s // 50) % 475
        for q in range(25):
            i =(i * 96 + 42) % 475
            a[q]=26 + i
        for i in range(25):
            if a[i]==p:
                m=1
                
        
print(c)