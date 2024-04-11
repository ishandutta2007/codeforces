s=input()
s=s.split(":")
h=s[0]
m=s[1]
h=h[::-1]
m=m[::-1]
mi=0
def eval(s,x):
  su=0
  j=0
  for  i in s:  
    if ord(i)>=ord('0') and ord(i)<=ord('9'):
      su=su+(x**j)*(ord(i)-48)
    else:
        su=su+(x**j)*(ord(i)-55)
    j+=1      
  return su

for i in (h+m):
    if ord(i)>=ord('0') and ord(i)<=ord('9'):
       mi=max(mi,ord(i)-48)
    else:
        mi=max(mi,ord(i)-55)

mi+=1
mi=max(2,mi)
x=mi
if(eval(h,x)>23 or eval(m,x)>59): print(0)
elif(eval(h,x)==eval(h,x+1) and eval(m,x)==eval(m,x+1)): print(-1)
else: 
    while 1:
        if eval(h,x)<=23 and eval(m,x)<=59:
            x+=1
        else: break
    if(mi==x):print(0)         
    for i in range(mi,x):
     print(i,end=" ")
    print("")