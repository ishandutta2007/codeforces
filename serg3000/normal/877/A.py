a=input()
z=0
s1=a.find("Ann")  
s2=a.rfind("Ann")

if s1==s2 and s1!=-1:
    z+=1
else:
    if s1!=-1:
        z+=2
s1=a.find("Danil")  
s2=a.rfind("Danil")

if s1==s2 and s1!=-1:
    z+=1
else:
    if s1!=-1:
        z+=2
s1=a.find("Olya")  
s2=a.rfind("Olya")
    
if s1==s2 and s1!=-1:
    z+=1
else:
    if s1!=-1:
        z+=2

s1=a.find("Slava")  
s2=a.rfind("Slava")
                
if s1==s2 and s1!=-1:
    z+=1
else:
    if s1!=-1:
        z+=2
s1=a.find("Nikita")  
s2=a.rfind("Nikita")
                
if s1==s2 and s1!=-1:
    z+=1
else:
    if s1!=-1:
            z+=2

if z==1:
    print("YES")
else:
    print("NO")