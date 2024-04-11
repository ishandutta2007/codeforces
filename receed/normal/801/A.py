s=input()
if len(s)==1:
    print(0)
else:
    x=s.count('VK')
    for i in range(len(s)):
        if s[i]=='K':
            if i<len(s)-1 and s[i+1]=='K' and (i==0 or s[i-1]=='K'):
                x+=1
                break
        elif i>0 and s[i-1]=='V' and (i==len(s)-1 or s[i+1]=='V'):
            x+=1
            break
    print(x)